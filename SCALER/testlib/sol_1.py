from heapq import heappush,heappop
N,M=map(int,input().split())
LRC=[list(map(int,input().split())) for i in range(M)]
data=[[],[]]+[[[i-1,0]] for i in range(2,N+1)]
for L,R,C in LRC:
    data[L].append([R,C])
dist=[[0,1]]
inf=float("inf")
flag=[inf]*(N+1)
while dist:
    y,x=heappop(dist)
    if flag[x]!=inf:
        continue
    flag[x]=y
    for u in data[x]:
        if flag[u[0]]==inf:
            heappush(dist,[y+u[1],u[0]])
    if flag[N]!=inf:
        break
if flag[N]==inf:
    print(-1)
else:
    print(flag[N])