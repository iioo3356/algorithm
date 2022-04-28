// 프로그래머스 게임 맴 최단거리
#include <queue>

using namespace std;

int board[101][101];
int dist[101][101];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
queue<pair<int, int>> q;

int solution(vector<vector<int> > maps) {
    int answer = 0;
    for (int i=0;i<101;i++)
        for (int j=0;j<101;j++)
            dist[i][j] = 0;
  
    for (int i=0; i<maps.size();i++)
        for (int j=0;j<maps[i].size();j++)
            board[i][j] = maps[i][j];
 
    int height = maps.size();
    int width = maps[0].size();
    
    q.push({0, 0});
    dist[0][0] = 1;
    while (!q.empty()){
        auto cur = q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int nx = dir[i][0] + cur.first;
            int ny = dir[i][1] + cur.second;
            if (nx < 0 || ny < 0 || nx >= height || ny >= width) continue;
            if (board[nx][ny] != 1 || dist[nx][ny] >= 1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    
    if (dist[height-1][width-1] == 0) return -1;
    else return dist[height-1][width-1]; 
    return answer;
}
