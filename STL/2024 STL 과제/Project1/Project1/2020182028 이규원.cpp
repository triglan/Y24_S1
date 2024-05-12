#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <deque>
#include <vector>
#include <map>
#include <numeric> 
#include <iterator>
#include <algorithm>
using namespace std;


class Player {
private:
	string name; // 이름, 길이[3, 15]
	int score; // 점수
	size_t id; // 아이디, 겹치는 아이디 있을 수 있음
	size_t num; // free store에 확보한 바이트 수
	unique_ptr<char[]> p; // free store에 확보한 메모리

public:
	Player() : score(0), id(0), num(0), p(nullptr) {}

	Player& operator=(const Player& other) {
		if (this != &other) { 
			name = other.name;
			score = other.score;
			id = other.id;
			num = other.num;
			p = std::make_unique<char[]>(num);
			memcpy(p.get(), other.p.get(), num); 
		}
		return *this;
	}
	Player(Player&& other) noexcept
		: name(std::move(other.name)), score(other.score), id(other.id), num(other.num), p(std::move(other.p)) {}
	Player& operator=(Player&& other) noexcept {
		if (this != &other) {
			name = std::move(other.name);
			score = other.score;
			id = other.id;
			num = other.num;
			p = std::move(other.p);
		}
		return *this;
	}

	bool read(std::istream& is) {
		is.read((char*)this, sizeof(Player) - sizeof(std::unique_ptr<char[]>));
		char temp[sizeof(std::unique_ptr<char[]>)];

		is.read(temp, sizeof(std::unique_ptr<char[]>));
		p = std::make_unique<char[]>(num);

		is.read((char*)p.get(), num);

		return (bool)is;
	}

	int getScore() const { return score; }
	size_t getID() const { return id; }
	string getName() const { return name; }

	friend std::ostream& operator<<(std::ostream& os, const Player& player) {
		os << "이름 : " << player.name
			<< ", 아이디 : " << player.id
			<< ", 점수 : " << player.score
			<< ", 자원수 : " << player.num << std::endl
			<< "저장된 글자 : " << player.p.get();

		return os;	}	Player(const Player& other) {
		name = other.name; // Deep copy using copy assignment
		score = other.score;
		id = other.id;
		num = other.num;
		p = std::make_unique<char[]>(num); // Allocate new memory and copy data
		memcpy(p.get(), other.p.get(), num);
	}	void sortP() {		string str(p.get());		sort(str.begin(), str.end());		p = make_unique<char[]>(str.length() + 1);

		strcpy(p.get(), str.c_str());	}	bool IsAtoZ() {		std::string str(p.get());
		int alphabetMask{};		for (auto& c : str) {
			if (std::isalpha(c)) {
				int index = std::tolower(c) - 'a';
				
				alphabetMask |= (1 << index);
			}
		}
		return (alphabetMask == ((1 << 26) - 1));	}};int main() {	ifstream in("2024 STL 과제 파일", ios::binary);	if (not in) exit(444);	vector<Player> players;	Player p;


	while (p.read(in)) {
		players.push_back(move(p));
	}
	if (!players.empty()) {
		cout << "마지막 플레이어 정보:" << players.back() << endl << endl;
	}	int totalScore = accumulate(players.begin(), players.end(), 0,
		[](int sum, const Player& player) { return sum + player.getScore(); });

	float averageScore = (float)totalScore / players.size();
	cout << "플레이어의 평균 점수: " << averageScore << endl;

	auto maxScore = max_element(players.begin(), players.end(),
		[](const Player& a, const Player& b) {
			return a.getScore() < b.getScore();
		});
	cout << "플레이어의 최고 점수: " << *maxScore << endl << endl;
	cout << "같은 아이디 검색중..." << endl;
	map<size_t, vector<Player>> playerID;

	for (const Player& player : players) {
		playerID[player.getID()].push_back(player);
	}

	ofstream out("같은아이디.txt");

	int totalSameIDPlayers = 0;
	for (const auto& pair : playerID) {
		if (pair.second.size() > 1) { // 동일 ID 플레이어가 2명 이상인 경우
			for (const Player& player : pair.second) {
				out << "이름: " << player.getName() << ", 아이디: " << player.getID() << endl << endl;
			}
		}
		int sameIDCount = pair.second.size();
		if (sameIDCount > 1) {
			totalSameIDPlayers += sameIDCount;
		}
	}


	cout << "같은아이디 개수: " << totalSameIDPlayers << endl << endl;



	cout << "a to z 검색중..." << endl;
	int isAtoZCount{};
	for (auto& p : players) {
		p.sortP();

		if (p.IsAtoZ())
			++isAtoZCount;
	}
	cout << "a to z : " << isAtoZCount << endl << endl;	size_t targetID;

	while (true) {
		vector<Player>::iterator search{};

		cout << "조회할 플레이어 ID 입력: ";
		cin >> targetID;
		cout << "검색중..." << endl;



		sort(players.begin(), players.end(),//ID 오름차순
			[](const Player& a, const Player& b) {
				return a.getID() < b.getID();
			});
		search = lower_bound(players.begin(), players.end(), targetID,
			[](const Player& p, size_t id) {
				return p.getID() < id;
			});

		auto searchID = search->getID();
		auto searchName = search->getName();
		auto searchScore = search->getScore();

		if (search == players.end() || search->getID() != targetID) {
			cout << "존재하는 ID가 아닙니다." << endl;
			continue;
		}

		if (search != players.begin())//ID출력
			cout << "prevID : " << *prev(search) << endl;
		cout << "search ID : " << *search << endl;
		if (next(search) != players.end())
			cout << "next ID : " << *next(search) << endl << endl;



		sort(players.begin(), players.end(),//name 오름차순
			[](const Player& a, const Player& b) {
				return a.getName() < b.getName();
			});
		search = find_if(players.begin(), players.end(),
			[&searchName, &searchID, &searchScore](const Player& p) {
				return p.getName() == searchName && p.getID() == searchID && p.getScore() == searchScore;
			});

		if (search != players.begin())//Name출력
			cout << "prev Name : " << *prev(search) << endl;
		cout << "search Name : " << *search << endl;
		if (next(search) != players.end())
			cout << "next Name : " << *next(search) << endl << endl;


		std::sort(players.begin(), players.end(),
			[](const Player& a, const Player& b) {
				return a.getScore() < b.getScore();
			});

		search = find_if(players.begin(), players.end(),
			[&searchName, &searchID, &searchScore](const Player& p) {
				return p.getName() == searchName && p.getID() == searchID && p.getScore() == searchScore;
			});

		if (search != players.begin())//Score출력
			cout << "prev Score : " << *prev(search) << endl;
		cout << "search Score : " << *search << endl;
		if (next(search) != players.end())
			cout << "next Score : " << *next(search) << endl << endl;

	}
	cout << endl << endl << "처리 완료" << endl;	return 0;}