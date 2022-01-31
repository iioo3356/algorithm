// 프로그래머스 문자열 내림차순으로 배치하기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> arr;
    for (int i=0;i<s.size();i++){
        arr.push_back(s[i]);
    }
    sort(arr.begin(), arr.end(), greater<>());
    for (int i=0;i<arr.size();i++){
        answer += arr[i];
    }
    return answer;
}
