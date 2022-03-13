// 프로그래머스 기능개발
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> v;
    for (int i=0;i<progresses.size();i++){
        v.push_back(ceil((100-progresses[i])/(double)speeds[i]));
    }
    queue<int> q;
    q.push(v[0]);
   
    for (int i=1;i<v.size();i++){
        if (q.front() >= v[i]) {
            q.push(v[i]);
        }
        else {
            answer.push_back(q.size());
            while(!q.empty()) q.pop();
            q.push(v[i]);
        }
    }
    if (!q.empty()) answer.push_back(q.size());
    
    return answer;
} 
