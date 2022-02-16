// 프로그래머스 더 맵게
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i=0;i<scoville.size();i++) pq.push(scoville[i]);
        while (pq.size() >= 2 && pq.top() < K){
            answer += 1;
            int first= pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int newS = first + second * 2;
            pq.push(newS);
        }
    if (pq.top() < K) answer = -1;
    return answer;
}
