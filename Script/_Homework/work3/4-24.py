import random
deck = [i for i in range(52)]

numbers = ['A',2,3,4,5,6,7,8,9,19,'J','Q','K'] # 13개 숫자 리스트
suits = ['스페이드', '다이아몬드', '하트', '클로버'] # 4개의 무늬

random.shuffle(deck)

for i in deck:
    suit = i // 13 # 0,1,2,3
    number = i % 13 # 0,1,2,..., 12
    print(suits[suit], numbers[number])