class Person:
    name = 'Default Name' # 클래스 멤버 변수
    def Print(self): # 멤버 함수
        print('My Name is {0}'.format(self.name))

str = 'Not Class Member'

class GString: # 객체와 클래스
    str = ''
    def Set(self, msg):
        self.str = msg # 객체를 바꿈
        #Gstring.str = msg -> 클래스를 변경하라는 뜻 다른 의미
    def Print(self):
        print(str)

class MyClass: # 생성자 테스트
    def __init(self, value):
        self.Value = value
        print('Class is created Value = ', value)
    def __del__(self):
        print('Class is deleted')
def foo():
    d = MyClass(10)

class CounterManager:# 킄ㄹ래스 변수 변경
    insCount = 0
    def __init__(self):
        CounterManager.insCount += 1 # 클래스 멤버 변수 1 증가
    def printInstanceCount(): # 클래스 멤버변수
        print('Instance Count : '. CounterManager.insCount)


class Person:
    def __init__(self,name,phoneNumber):
        self.Name = name
        self.PhoneNumber = phoneNumber
    def PrintInfo(self):
        print('Info(Name ; {0}, Phone Number : {1}'.format(self.Name, self.PhoneNumber))
    def PrintPersonData(self):
        print('Person(Name ; {0}, Phone Number : {1}'.format(self.Name, self.PhoneNumber))
class Student(Person):
    def __init__(self, name, phonenumber, subject, studentID):
        Person.__init__(self, name, phonenumber)
        self.Name = name
        self.PhoneNumber = phonenumber
        self.Subject = subject
        self.StudentID = studentID
    def printStudentData(self):
        print('Student(Subject : {0}, StudentID:{1}'.format(self.Subject, self.StudentID))
    def PrintInfo(self): #이게 메소드 오버라이딩 중요 ㅇㅇ
        print('Info(Name : {0}, Phone Number : {1}'.format(self.Name, self.PhoneNumber))
        print('Info(Subject:{0}, StudentID:{1}'.format(self.Subject, self.StudentID))