#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket ;
    basket.push(-1);
    for (int i=0;i<moves.size();i++){
        // cout << moves[i] << " move" << endl;
        for (int j=0;j<board.size();j++){
            if (board[j][moves[i]-1] > 0){
                // cout << board[j][moves[i]-1]<< endl;
                // cout << "top " << basket.top() << endl;
                if (basket.top() == board[j][moves[i]-1]){
                    basket.pop();
                    basket.pop();
                    answer += 2;
                }
                else{
                    basket.push(board[j][moves[i]-1]);

                }
                board[j][moves[i]-1] = 0;

                // cout << board[j][moves[i]-1] << endl;
                break;
            }
        }
    }
    return answer;
}
