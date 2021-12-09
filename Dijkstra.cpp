from queue import PriorityQueue

def dijkstra(road, N):
    dist = [1000000] * (N + 1)
    dist[1] = 0 #시작노드 1은 0
    pq = PriorityQueue()
    pq.put([0,1])
    
    while not pq.empty():
        cost, here = pq.get()
        if cost > dist[here]: continue
        
        for i in range(len(road)):
            if road[i][0] == here:
                cost2, there = road[i][2] + cost, road[i][1]
                if cost2 < dist[there]:
                    dist[there] = cost2
                    pq.put([cost2, there])
            elif road[i][1] == here:
                cost2, there = road[i][2] + cost, road[i][0]
                if cost2 < dist[there]:
                    dist[there] = cost2
                    pq.put([cost2, there])
    return dist
    
def solution(N, road, K):
    answer = 0
    dist = dijkstra(road, N)
    for i in dist:
        if i <= K:
            answer += 1
    return answer



void Dijkstra(int N)
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, 1));
    Dist[1] = 0;
 
    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
 
        for (int i = 0; i < V[Cur].size(); i++)
        {
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;
 
            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
}
 
int solution(int N, vector<vector<int> > road, int K)
{
    Dist.resize(N + 1, 2e9);
    for (int i = 0; i < road.size(); i++)
    {
        int N1 = road[i][0];
        int N2 = road[i][1];
        int Dist = road[i][2];
 
        V[N1].push_back(make_pair(N2, Dist));
        V[N2].push_back(make_pair(N1, Dist));
    }
 
    Dijkstra(N);
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (Dist[i] <= K) answer++;
    }
 
    return answer;
}





#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <functional>
#include <algorithm>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {

    vector<int> Graph(N+1);
    
    vector<vector <int>> adj(N+1);
    vector < vector <int> > v(10,vector <int>(10,0));
    for (int i=0;i<road.size();i++){
        adj[road[i][0]].push_back(road[i][1]);
    }
    for (int i=1;i<Graph.size();i++){
        Graph[i] = INT_MAX;
    }
    Graph[0] = -1;
    Graph[1] = 0; // 초기화
    
    vector<int> S(N+1);
    priority_queue< int, vector<int>, greater<int> > Q;
    
    for (int i=1;i<Graph.size();i++){
        Q.push(Graph[i]);
    }
    // vector<int> Q2 = Graph;
    while (!Q.empty()){
        int uValue = Q.top();
        auto it = find(Graph.begin(), Graph.end(), uValue);
        int u = it - Graph.begin();
        // cout << u << endl;
        Q.pop();
        // S[u] = 1;
        for (int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            int w;
            for (int j=0;j<road.size();j++){
                if (road[j][0] == u && road[j][1]==v){
                    w = road[j][2];
                    continue;
                }
            }
            if (Graph[v]>Graph[u]+w){
                Graph[v] = Graph[u]+w;
                priority_queue< int, vector<int>, greater<int> > temp;
                for (int j=1;j<Graph.size();j++){
                    if (S[j]==0){
                        if (Graph[v] <= K){
                            S[j] = Graph[v];
                        }
                        else{
                            S[j] = 1;
                        }
                        temp.push(Graph[j]);
                    }
                }
                // cout << temp.size() << endl;
                Q = temp;
            }
        }
        
    }
    for (int i=1;i<S.size();i++){
        cout << S[i] <<" ";
    }
    cout << endl;
    
    int answer =0;
    

    return answer;
}




from queue import PriorityQueue()
import math

def dijkstra(n, roads):
    dist=[math.inf] * (n+1)
    dist[1] = 0
    Q = PriorityQueue()
    Q.put([0, 1])
    while not Q.empty():
        cost, here = Q.get()
        if (dist[here] < cost):
            continue
        else:
            for i in range(len(road)):
                if (roads[i][0] == here):
                    cost2, there = road[i][2] + cost, road[i][1]
                    if cost2< dist[there]:
                        dist[there] = cost2
                        Q.put([cost2, there])
                elif (roads[i][1] == there):
                    cost2, there = road[i][2] + cost, road[i][0]
                    if cost2<dist[there]:
                        dist[there] = cost2
                        Q.put([cost2, there])
    
    return dist

def solution(n, roads, K):
    answer = 0
    dist = dijkstra(n, roads)
    for i in dist:
        if i<=K:
        answer += 1
    return answer