// 백준 2178 미로탐색

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<vector<char>> g;
vector<vector<int>> dist;
bool isChecked[101][101];
int end_r, end_c;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push(make_pair(r,c));
    isChecked[r][c] = true;
    int count = 1;
    while (!q.empty()){
        int current_r = q.front().first;
        int current_c = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_r = current_r + dir[i][0];
            int next_c  = current_c + dir[i][1];
            if (next_r >= 0 && next_r <= end_r-1 && next_c >= 0 && next_c <= end_c-1){
                if (!isChecked[next_r][next_c] && g[next_r][next_c] == '1'){
                    q.push(make_pair(next_r, next_c));
                    isChecked[next_r][next_c] = true;
                    dist[next_r][next_c] = dist[current_r][current_c] + 1;
                    count += 1;
                }
            }
        }
    }
    return count;
}

int main() { 
    int answer;
    int n, m;
    cin >> n >> m;
    end_r = n;
    end_c = m;
    for (int i=0;i<n;i++){
        string s;
        vector<char> tmp;
        vector<int> tmp2;
        cin >> s;
        for (int j=0;j<m;j++){
            tmp.push_back(s[j]);
            tmp2.push_back(0);
        }
        g.push_back(tmp);
        dist.push_back(tmp2);
    }
    dist[0][0] = 1;
    bfs(0,0);
    answer = dist[n-1][m-1];
    cout << answer << endl;

    return 0;
}
