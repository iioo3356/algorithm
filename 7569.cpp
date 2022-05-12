//백준 7569 토마토(3차원)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n, h;
vector<vector<vector<int>>> boxes;
queue<vector<int>> q;

int dir_r[6] = {0,1,-1,0,0,0};
int dir_c[6] = {1,0,0,-1,0,0};
int dir_h[6] = {0,0,0,0,1,-1};

void bfs(){
    while (!q.empty()){
        int current_h = q.front()[0];
        int current_r = q.front()[1];
        int current_c = q.front()[2];
        q.pop();
        for (int i=0;i<6;i++){
            int next_h = current_h + dir_h[i];
            int next_r = current_r + dir_r[i];
            int next_c = current_c + dir_c[i];
            if (next_h>=0 && next_r>=0 && next_c>=0 && next_h<h &&next_r<n && next_c<m){
                if (boxes[next_h][next_r][next_c] == 0){
                    boxes[next_h][next_r][next_c] = boxes[current_h][current_r][current_c]+1;
                    vector<int> v = {next_h, next_r, next_c};
                    q.push(v);
                }
            }
        }
    }
}
int main(){
    cin >> m >> n >> h;
    for (int k=0;k<h;k++){
        vector<vector<int>> t;
        for (int i=0;i<n;i++){
            vector<int> tmp;
            for (int j=0;j<m;j++){
                int t;
                cin >> t;
                tmp.push_back(t);
                vector<int> v = {k, i, j};
                if (t == 1){ 
                    q.push(v);
                }
            }      
            t.push_back(tmp);
        }
        boxes.push_back(t);
    }

    bfs();
    bool isIncomplete = false;
    int max_day = -1;
    for (int k=0;k<h;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (boxes[k][i][j] == 0) {
                    isIncomplete = true;
                }
                max_day = max(max_day, boxes[k][i][j]);
            }
        }
    }

    if (isIncomplete) cout << -1 << endl;
    else if (max_day == 1) cout << 0 << endl;
    else cout << max_day-1 << endl;
    return 0;
}
