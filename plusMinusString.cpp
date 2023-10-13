// 문자열 계산하기
#include <string>
#include <vector>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    vector<string> v;
    string temp = "";
    for (int i=0;i<my_string.size();i++){
        if (my_string[i] == ' ') {
            v.push_back(temp);
            temp = "";
        }
        else {
            temp += my_string[i];
        }
    }
    v.push_back(temp);
    for (int i=0;i<v.size();i++){
        if (v[i] == "+") {
            v[i+1] = to_string(stoi(v[i-1]) + stoi(v[i+1]));
        }
        else if (v[i] == "-") {
            v[i+1] = to_string(stoi(v[i-1]) - stoi(v[i+1]));
        }
    }
    answer = stoi(v[v.size()-1]);
    return answer;
}
