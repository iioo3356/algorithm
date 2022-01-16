// 프로그래머스 서울에서 김서방 찾기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    auto it = find(seoul.begin(), seoul.end(), "Kim");
    int idx = it - seoul.begin();
    answer = "김서방은 " + to_string(idx) + "에 있다";
    return answer;
}
