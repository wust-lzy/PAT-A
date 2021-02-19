#python 大数直接做 
n = int(input())
for i in range(1, n + 1):
    a, b, c = map(int, input().split())
    if a + b > c:
        print("Case #%d: true" % i)
    else:
        print("Case #%d: false" % i)
        
