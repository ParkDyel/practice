# Q1
def getB(a, m):
    # 두 개의 정수, a,b 와 그 두 수의 평균을 m 이라 하자.
    # 즉, m = (a+b)/2 이때, a와 m을 입력받고, b를 출력하는 프로그램을 작성.
    return (2*m -a)

#Q2
def getGcd(num1, num2):
    if num1 < num2:
        (num1, num2) = (num2, num1)
    while num2 != 0:
        (num1, num2) = (num2, num1 % num2)
    return num1

#Q3
def getMulti(n):
    ret = 1
    while(n != 0 ):
        ret = ret * (n%10)
        # print(ret)
        n = (n - n%10)/10
        # print(n)
    print(int(ret))
    return int(ret)

def setMultiFun(n):
    #f(n)을 다음과 같이 정의하자.
    # “n은 10이상의 자연수이며, f(n) = n의 각 자리수의 곱으로 정의”
    # 예) f(10) = 1*0 = 0 , f(23) = 2*3 = 6, f(99) = 9*9 =81
    sum = 0
    for idx in range(10, n+1):
        sum = sum + getMulti(idx)
    return int(sum)