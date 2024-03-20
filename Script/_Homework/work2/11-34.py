def getRightmostLowestPoint(points):
    i = 0
    maxlen, maxindex = 0, -1
    while i < len(points):
        if points[i] > 0 and points[i+1] < 0:
            if maxlen < points[i]**2 + points[i]**2:
                maxlen, maxindex = points[i]**2 + points[i]**2, i
        i+=2
    return maxindex

ilst = input('6개의 점 : ').split()
lst = [eval(s) for s in ilst]
maxi = getRightmostLowestPoint(lst)
print("최우측하단의 점은 (", lst[maxi], ", ", lst[maxi + 1], ") 입니다.")

