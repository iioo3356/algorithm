// 프로그래머스 문자열 내 마음대로 정렬하기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int globalN;
bool cmp (string a, string b){
    if (a[globalN] == b[globalN]){
        return a < b;
    }
    return a[globalN] < b[globalN];
}
vector<string> solution(vector<string> strings, int n) {
    globalN = n;
    vector<string> answer;
    sort(strings.begin(), strings.end(), cmp);
    answer = strings;
    return answer;
}
