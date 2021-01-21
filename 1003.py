fibo_arr = {}

def fibo(n) :
    global fibo_arr
    if n in fibo_arr :
        return fibo_arr[n]
    if n == 0 :
        fibo_arr[n] = tuple((1,0))
    elif n == 1 :
        fibo_arr[n] = tuple((0,1))
    else :
        fibo_arr[n] = tuple((fibo(n-1)[0] + fibo(n-2)[0], fibo(n-1)[1] + fibo(n-2)[1]))
    return fibo_arr[n]

T = int(input())

for _ in range(T):
    num = int(input())
    fibonacci = fibo(num)
    print(fibonacci[0], fibonacci[1])
