//백준 7576 토마토

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
vector<vector<int>> box;
queue<pair<int, int>> q;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void bfs(){
    while (!q.empty()){
        int current_r = q.front().first;
        int current_c = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_r = current_r + dir[i][0];
            int next_c = current_c + dir[i][1];
            if (next_r>=0 && next_c>=0 && next_r<n && next_c<m){
                if (box[next_r][next_c] == 0){
                    box[next_r][next_c] = box[current_r][current_c]+1;
                    q.push(make_pair(next_r, next_c));
                }
            }
        }
    }
}
int main(){
    cin >> m >> n;
    for (int i=0;i<n;i++){
        vector<int> tmp;
        for (int j=0;j<m;j++){
            int t;
            cin >> t;
            tmp.push_back(t);
            if (t == 1){ 
                q.push(make_pair(i,j));
            }
        }      
        box.push_back(tmp);
    }
    bfs();
    bool isIncomplete = false;
    int max_day = -1;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (box[i][j] == 0) {
                isIncomplete = true;
            }
            max_day = max(max_day, box[i][j]);
        }
    }
    if (isIncomplete) cout << -1 << endl;
    else if (max_day == 1) cout << 0 << endl;
    else cout << max_day-1 << endl;
    return 0;
}
