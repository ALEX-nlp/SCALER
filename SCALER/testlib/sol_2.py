n,l,a = map(int,input().split())
b =[]
for i in range(n):
	b.append([int(e) for e in input().split()])
ans = 0
for i in range(n-1):
	ans += (b[i+1][0] - b[i][1] - b[i][0])//a
if(n > 0):
	ans += b[0][0]//a
	ans += (l - b[n-1][1] - b[n-1][0])//a
else:
	ans += l//a
print(ans)
