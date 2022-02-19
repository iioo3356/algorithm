#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
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
    return answer;
}
