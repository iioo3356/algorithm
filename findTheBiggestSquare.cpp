// 프로그래머스 가장 큰 정사각형 찾기
#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board){
    int max_num = 0;
    for (int i=1;i<board.size();i++){
        for (int j=1;j<board[i].size();j++){
            if (board[i][j] == 1){
                int min_num = min(board[i-1][j], board[i-1][j-1]);
                min_num = min(min_num, board[i][j-1]);
                board[i][j] = min_num + 1;
            }
        }
    }
    for (int i=0;i<board.size();i++){
        for (int j=0;j<board[i].size();j++){
            max_num = max(max_num, board[i][j]);
        }
    }
    int answer = max_num * max_num;
    return answer;
}
