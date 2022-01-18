// 프로그래머스 부족한 금액 채우기
#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long int all_price= 0;
    for (int i=1;i<count+1;i++){
        all_price += (price * i);
    }
    long long int answer = all_price - money;
    if (answer <= 0) return 0;
    return answer;
}
