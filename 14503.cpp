// boj 14503 로봇 청소기
#include <iostream>
using namespace std;

int n, m, d, r, c;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int map[51][51];
int count;

void dfs(){
    for (int i=0;i<4;i++){
        int nd = (d+3-i)%4;
        int nr = r+dir[nd][0];
        int nc = c+dir[nd][1];
        if (0<=nr && nr<n && 0<=nc && nc<m){
            if (map[nr][nc] == 0){
                map[nr][nc] = 2;
                d=nd;
                count++;
                r = nr;
                c = nc;
                dfs();
            }
        }
    }
    
    int back;
    if (d>1) back = d-2;
    else back = d+2;
    int br = r+dir[back][0];
    int bc = c+dir[back][1];
    if (0<=br && br<=n || 0<=bc || bc <= m){
        if (map[br][bc] == 2) {
            r = br;
            c = bc;
            dfs();
        }
        else if (map[br][bc] == 1){
            return;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    map[r][c] = 2;
    count++;
    dfs();

    cout << count << "\n";
    return 0;
}
