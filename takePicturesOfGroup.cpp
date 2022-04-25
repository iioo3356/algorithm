// 프로그래머스 단체사진 찍기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    do{
        bool flag = true;
        for (int i=0;i<data.size();i++){
            char first = data[i][0];
            char second = data[i][2];
            char cmp = data[i][3];
            int num = data[i][4] - '0';
			int dis = abs(find(friends.begin(), friends.end(), first) - find(friends.begin(), friends.end(), second) ) - 1;
            
            if (cmp == '=' && dis != num) {
                flag = false;
                break;
            } 
            else if (cmp == '>' && dis <= num) {
                flag = false;
                break;
            }
            else if (cmp == '<' && dis >= num) {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}
