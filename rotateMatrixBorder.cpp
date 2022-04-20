// 프로그래머스 행렬 테두리 회전하기
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
using namespace std;
 
int map[101][101];
int minNum = INT_MAX;
 
void rotate(int x1, int y1, int x2, int y2) {
    int start = map[x1][y1];
    for (int i=x1;i<x2;i++) {
        map[i][y1] = map[i+1][y1];
        minNum = min(minNum, map[i][y1]);
    }
    for (int i=y1;i<y2;i++) {
        map[x2][i]=map[x2][i+1];
        minNum = min(minNum, map[x2][i]);
    }
    for (int i = x2; i > x1; i--) {
        map[i][y2] = map[i - 1][y2];
        minNum = min(minNum, map[i][y2]);
    }
    for (int i = y2; i > y1 + 1; i--) {
        map[x1][i] = map[x1][i - 1];
        minNum = min(minNum, map[x1][i]);
    }
 
    map[x1][y1 + 1] = start;
    minNum = min(minNum, map[x1][y1 + 1]);
}
 
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    memset(map, 0, sizeof(map));
 
    for (int i=1;i<=rows;i++) {
        for (int j=1;j<=columns;j++) {
            map[i][j] = (i - 1) * columns + j;
        }
    }
    for (int i = 0; i < queries.size(); i++) {
        minNum = INT_MAX;
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        rotate(x1,y1,x2,y2);
        answer.push_back(minNum);
    }
    return answer;
}
