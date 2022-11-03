// boj 14502 연구소
#include <iostream>
using namespace std;

int n, m;
int map[9][9];
int copy_map[9][9];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x, int y) {
    for (int i=0;i<4;i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if (0<=nx && nx<n && 0<=ny && ny<m){
            if (copy_map[nx][ny] == 0){
                copy_map[nx][ny] = 2;
                dfs(nx,ny);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    int answer = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (map[i][j] != 0) continue;
            for (int i2=0;i2<n;i2++){
                for (int j2=0;j2<m;j2++){
                    if (map[i2][j2] != 0) continue;
                    if (i == i2 && j == j2) continue;
                    for (int i3=0;i3<n;i3++){
                        for (int j3=0;j3<m;j3++){
                            if (map[i3][j3] !=0) continue;
                            if (i2 == i3 && j2 == j3) continue;
                            if (i == i3 && j == j3) continue;
                            map[i][j] = 1;
                            map[i2][j2] = 1;
                            map[i3][j3] = 1; // 벽 세우기
                            int count = 0;
                            for (int r=0;r<n;r++){
                                for (int c=0;c<m;c++){
                                    copy_map[r][c] = map[r][c];
                                }
                            }
                            for (int r=0;r<n;r++){
                                for (int c=0;c<m;c++){
                                    if (copy_map[r][c] == 2){
                                        dfs(r, c); // 바이러스 퍼뜨리기
                                    }
                                }
                            }
                            for (int r=0;r<n;r++){
                                for (int c=0;c<m;c++){
                                    if (copy_map[r][c] == 0)
                                        count++; // 안전구역 세기
                                }
                            }
                            answer = max(answer, count);
                            
                            map[i][j] = 0;
                            map[i2][j2] = 0;
                            map[i3][j3] = 0; // 벽 되돌리기
                        }
                    }
                }
            }
        }
    }
    cout << answer << "\n";
    return 0;
}
