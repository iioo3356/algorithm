// 프로그래머스 조이스틱
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int min_move = name.size() -1;
    int next = 0;
    int len = name.size();
    while (name[min_move] == 'A' && min_move > 0) min_move-=1;
    if (min_move < 0) return answer;
    for (int i=0;i<name.size();i++){
        answer += min(name[i]-'A', 'Z'-name[i]+1);
        next = i+1;
        while (next < name.size() and name[next] == 'A') next += 1;
        min_move = min(min_move, i+len-next + min(i,len-next));
    }
    answer += min_move;
    return answer;
}
