<<<<<<< Updated upstream
#W방 H층
T = eval(input())
for _ in range(T):
    H, W, C = map(int, input().split())
    cnt = 0
    for x in range(W):
        for y in range(H):
           cnt+=1
           if cnt == C:
               print(100 * (y+1) + (x+1))
               y,x = H,W
=======
# d = []
# count = 0
# flag = True
# for _ in range(8):
#     d = input()
#     for i in range(8):
#         if flag:
#             if i%2 == 0 and d[i] == 'F':
#                 count += 1
#         else:
#             if i%2 == 1 and d[i] == 'F':
#                 count += 1
#     flag = not flag
#
# print(count)


cnt = 0
for _ in range(cnt):
>>>>>>> Stashed changes
