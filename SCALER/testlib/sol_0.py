s, v1, v2, t1, t2 = list(map(int, input().split()))
a = 2*t1 + s*v1 
b = 2*t2 + s*v2
if a > b:
    print("Second")
elif a < b:
    print("First")
else:
    print("Friendship")

