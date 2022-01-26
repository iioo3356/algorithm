// 프로그래머스 정수 내림차순으로 배치하기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;
    while (n>=10){
        arr.push_back(n%10);
        n/=10;
    }
    arr.push_back(n);
    sort(arr.begin(), arr.end(), greater<>());
    int j = 1;
    for (int i=arr.size()-1; i>=0;i--){
        answer += arr[i] * j;
        j*=10;
    }
    
    return answer;
}
