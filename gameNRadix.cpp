// 프로그래머스 n진수 게임
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string full_str = "0";
    int current_num = 1;
    while (true){
        int num = current_num;
        string s = "";
        while (num > 0){
            if (num%n < 10) {
                s = to_string(num%n)+s;
            }
            else {
                s = char(num%n+55) +s;
            }
            num /= n;
        }
        current_num += 1;
        full_str += s;
        if (full_str.size()>t*m-1) break;
    }
    for (int i=0;i<t;i++){
        int tube_idx = m*i+p-1;
        answer += full_str[tube_idx];
    }
    return answer;
}
