def isPrime(num):
    if num==1:
        return False
    else:
        for i in range(2, int(num**0.5)+1):
            if num%i == 0:
                return False
        return True

li = list(range(2,246912))
prime_li = []
for i in li:
    if isPrime(i):
        prime_li.append(i)

while True:
    num = int(input())
    if num == 0:
        break
    count = 0

    for i in prime_li:
        if num+1 <= i <= num*2:
            count += 1

    print(count)
