// 프로그래머스 다리를 지나는 트럭
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weights = 0;
    int index = 0; 
    queue<int> q; 
    while( true) {
        if (index == truck_weights.size()) {
            answer += bridge_length;
            break;
        } 
        answer++; 
        int now = truck_weights[index]; 
        if (q.size() == bridge_length) {
            weights -= q.front(); 
            q.pop();
        } 
        if (weights + now <= weight) {
            q.push(now); 
            weights += now; 
            index++; 
        } 
        else { 
            q.push(0); 
        } 
    } 
    return answer;
}
