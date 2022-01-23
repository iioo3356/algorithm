// 프로그래머스 최대공약수와 최소공배수
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int num;
    int big = m;
    int small = n;
    if (n>m){
        big = n;
        small = m;
    }
    while (small!=0){                
        num = big % small;
        big = small;
        small = num;     
    }
    int gcf = big;
    int lcf = (n*m)/gcf;
    answer.push_back(gcf);
    answer.push_back(lcf);
    return answer;
}
