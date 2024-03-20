#lst = 1 2 3 4 5 -> True
#lst = 1 3 2 4 5 -> False
def isSorted(lst): #오름차순 정렬되어 있으면 True 반환
    for i in range(len(lst)-1):
        if lst[i] > lst[i+1]:
            return False
    return True

sList = input('정수를 입력 : ').split()
iList = [eval(s) for s in sList]
if isSorted(iList):
    print('정렬되어 있음')
else:
    print('정렬되어 있지 않음')