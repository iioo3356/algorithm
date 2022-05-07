// 백준 2606 바이러스
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isVisited[101];
vector<vector<int>> g;

int bfs(int n){
    isVisited[n] = true;
    int count = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()){
        int current = q.front();
        q.pop();
        for (int i=0;i<g[current].size();i++){
            if (!isVisited[g[current][i]]){
                count++;
                q.push(g[current][i]);
                isVisited[g[current][i]] = true;
            }
        }
    }
    return count;
}

int main() {
    int numComputer, numPairs;
    cin >> numComputer >> numPairs;
    for (int i=0;i<numComputer+1;i++){
        vector<int> t;
        g.push_back(t);
    }
    int answer = 0;
    for (int i=0;i<numPairs;i++){
        int current, next;
        cin >> current >> next;
        g[current].push_back(next);
        g[next].push_back(current);
    }
    answer = bfs(1);
    cout << answer << endl;
    return 0;
}
