// 프로그래머스 배달
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> d;

struct cmp {
  bool operator()(pair<int, int>&a, pair<int, int>&b) {
    return a.second < b.second;
  }
};

void dijkstra (int start){
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
    pq.push(make_pair(start, 0));
    d[start] = 0;
    while (!pq.empty()){
        pair<int, int> now = pq.top();
        pq.pop();
        for (int i=0;i<g[now.first].size();i++){
            pair<int, int> next = g[now.first][i];
            int next_dist = now.second + next.second;
            if (next_dist<d[next.first]){
                d[next.first] = next_dist;
                pq.push(make_pair(next.first, next_dist));
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i=0;i<N+1;i++){
        vector<pair<int, int>> k;
        d.push_back(INT_MAX);
        g.push_back(k);
    }
    for (int i=0;i<road.size();i++){
        g[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        g[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    
    dijkstra(1);
    
    for (int i=1;i<d.size();i++){
        if (d[i] <= K ) answer += 1;
    }
    
    return answer;
}
