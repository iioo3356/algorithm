// 프로그래머스 가장 큰 수
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    string mod_a;
    string mod_b;
    while (mod_a.size()<15){
        mod_a += a;
    }
    while (mod_b.size()<15){
        mod_b += b;
    }
    return mod_a > mod_b;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    for (int i=0;i<numbers.size();i++){
        strings.push_back(to_string(numbers[i]));
    }
    sort(strings.begin(), strings.end(), cmp);
    for (int i=0;i<strings.size();i++){
        answer += strings[i];
    }
    while (answer[0] == '0'){
        if (answer.size() ==1 )break;
        answer.erase(0,1);
    }
    return answer;
}
