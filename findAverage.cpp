// 프로그래머스 평균 구하기
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum = 0;
    for (int i=0;i<arr.size();i++) sum+=arr[i];
    double answer = (double)sum/arr.size();
    return answer;
}
