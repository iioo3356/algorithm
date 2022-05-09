// 백준 1012 유기농 배추
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int m, n, k;
int v[51][51];
bool isVisited[51][51];
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs(int r, int c){
    queue<pair<int, int>> q;
    isVisited[r][c] = true;
    q.push(make_pair(r,c));
    while (!q.empty()){
        int current_r = q.front().first;
        int current_c = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_r = current_r + dir[i][0];
            int next_c = current_c + dir[i][1];
            if (next_r>=0 && next_r<n && next_c>=0 && next_c<m){
                if (!isVisited[next_r][next_c] && v[next_r][next_c] == '1'){
                    q.push(make_pair(next_r, next_c));
                    isVisited[next_r][next_c] = true;
                }
            }
        }
    }
}

int main(){
    int numTestCases;
    cin >> numTestCases;
    for (int test=0;test<numTestCases;test++){
        int answer = 0;
        cin >> m >> n >> k;
        memset(v, '0', sizeof(v));
		memset(isVisited, false, sizeof(isVisited));
        for (int i=0;i<k;i++){
            int x, y;
            cin >> x >> y;
            v[y][x] = '1';
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (v[i][j] == '1' && !isVisited[i][j]){
                    answer++;
                    bfs(i, j);
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}
