// 프로그래머스 방문 길이
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int nowX = 0, nextX = 0, nowY = 0, nextY=0;
    unordered_map <string, bool> um;
    for (int i=0;i<dirs.size();i++){
        if (dirs[i] == 'U') {
            nextY+=1;
        }
        else if (dirs[i] == 'D') {
            nextY-=1;
        }
        else if (dirs[i] == 'L') {
            nextX-=1;
        }
        else {
            nextX+=1;
        }
        if (abs(nextY)>5 || abs(nextX)>5) {
            nextX = nowX;
            nextY = nowY;
            continue;
        }
        string x_str = nowX>nextX?to_string(nowX)+to_string(nextX):to_string(nextX)+to_string(nowX);
        string y_str = nowY>nextY?to_string(nowY)+to_string(nextY):to_string(nextY)+to_string(nowY);
        
        if (um.find(x_str+y_str) == um.end()){
            answer++;
            um[x_str+y_str] = true;
        }
        nowX = nextX;
        nowY = nextY;
        
    }
    return answer;
}
