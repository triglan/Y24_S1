def sumRating(i):
    if i ==1:
        return 1/2
    return sumRating(i-1) + i/(i+1)

for i in range(1,21):
    print(i, '\t', sumRating(i))