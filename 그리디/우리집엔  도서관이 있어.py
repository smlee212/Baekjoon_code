import sys
input=sys.stdin.readline
n=int(input())
book=[int(input().rstrip()) for _ in range(n)]

cnt = n
for i in range(n-1,-1,-1):
  if book[i] == cnt:
    cnt -= 1

print(cnt)