// 백준 2667 단지 번호 붙이기
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<bool>> isVisited;
vector<vector<char>> graph;

int bfs(int x, int y, int n){
    isVisited[x][y] = true;
    queue<pair<int, int>> q;
    int countHome = 1;
    q.push(make_pair(x, y));
    while (!q.empty()){
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_x = current_x + dir[i][0];
            int next_y = current_y + dir[i][1];
            if (0<=next_x && 0<=next_y && next_x < n && next_y <n){
                if (!isVisited[next_x][next_y] && graph[next_x][next_y] == '1') {
                    countHome++;
                    isVisited[next_x][next_y] = true;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }
    return countHome;
}
int main(){
    int n; // 가로 세로 크기
    int count = 0; // 단지 수
    vector<int> counts; // 단지에 속하는 집의 수
    cin >> n;
    for (int i=0;i<n;i++){
        string inputString;
        cin >> inputString;
        vector<char> tmp;
        vector<bool> tmp2;
        for (int j=0;j<n;j++){
            tmp.push_back(inputString[j]);
            tmp2.push_back(false);
        }
        graph.push_back(tmp);
        isVisited.push_back(tmp2);
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (graph[i][j] == '1' && !isVisited[i][j]){
                count++;
                int countHome = bfs(i, j, n);
                counts.push_back(countHome);
            }
        }
    }

    if (count == 0) cout << count << endl;
    else {
        cout << count << endl;
        sort(counts.begin(), counts.end());
        for (int i=0;i<counts.size();i++){
            cout << counts[i] << endl;
        }
    }


}
