// 프로그래머스 N개의 최소공배수
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    int max_n = max(a, b);
    int min_n = min(a, b);
    while (max_n % min_n != 0) {
        int temp = max_n % min_n;
        max_n = min_n; 
        min_n = temp;
    }
    return min_n;
}
int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i=1;i<arr.size();i++){
        int gcd_n = gcd(answer, arr[i]);
        answer = answer * arr[i] / gcd_n;
    }
    return answer;
}
