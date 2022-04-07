#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (true){
        vector<pair<int, int>> remove_idx;
        for (int i=0;i<m-1;i++){
           for (int j=0;j<n-1;j++){
                if (board[i][j] != '!' && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]){
                    remove_idx.push_back(make_pair(i, j));
                    remove_idx.push_back(make_pair(i, j+1));
                    remove_idx.push_back(make_pair(i+1, j));
                    remove_idx.push_back(make_pair(i+1, j+1));
                }
            }            
        }
        if (remove_idx.size() == 0) break;
        remove_idx.erase(unique(remove_idx.begin(),remove_idx.end()),remove_idx.end());

        for (int i=0;i<remove_idx.size();i++){
            answer++;
            board[remove_idx[i].first][remove_idx[i].second] = '!';
        }
        for (int i=m-1; i>= 0; i--) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '!') {
                    for (int k = i; k >= 0; k--) {
                        if (board[k][j] != '!') {
                            board[i][j] = board[k][j];
                            board[k][j] = '!';
                            break;
                        }
                    }
                }
            }
        }
    }
    return answer;
}
