// 프로그래머스 하샤드 수
#include <string>
#include <vector>
using namespace std;

bool solution(int x) {
    string x_mod = to_string(x);
    bool answer = true;
    int sum = 0;
    for (int i=0;i<x_mod.size();i++){
        sum += (int(x_mod[i])-48);
    }
    if (x%sum != 0) answer = false;    
    return answer;
}
