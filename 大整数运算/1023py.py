from collections import Counter
    
if __name__ == "__main__":
    num = input()
    n = str(int(num)*2)
    a = Counter(num)
    b = Counter(n)
    if a==b:
        print("Yes")
    else:
        print("No")
    print(a)
    print(n)