// 카카오프렌즈 컬러링북
#include <vector>
#include <queue>
using namespace std;

bool isVisit[100][100];
int width;
int height;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int bfs(int cx, int cy, vector<vector<int>> v){
    queue<pair<int, int>> q;
    int color = v[cx][cy];
    int size = 1;
    isVisit[cx][cy] = true;
    q.push(make_pair(cx,cy));
    
    while (!q.empty()){
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int nextX = nowX + dir[i][0];
            int nextY = nowY + dir[i][1];
            if (nextX >= 0 && nextY >= 0 && nextX < height && nextY < width)
                if (v[nextX][nextY] == color && !isVisit[nextX][nextY]){
                    size += 1;
                    isVisit[nextX][nextY] = true;
                    q.push(make_pair(nextX, nextY));
                }
        }
    }
    return size;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;    
    vector<int> answer(2);
    height = m;
    width = n;
    for (int i=0;i<height;i++)
        for (int j=0;j<width;j++)
            isVisit[i][j] = false;
    
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            if (picture[i][j] != 0 && !isVisit[i][j]){
                int size = bfs(i, j, picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, size);
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
