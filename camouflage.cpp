// 프로그래머스 위장
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (vector<string> a, vector<string> b){
    return a[1] < b[1];
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int num_same = 1;
    sort(clothes.begin(), clothes.end(), cmp);
    for (int i=1;i<clothes.size();i++){
        if (clothes[i][1] == clothes[i-1][1]){
            num_same += 1;
        }
        else {
            answer *= (num_same+1);
            num_same = 1;
        }
    }
    answer *= (num_same+1);
    answer -= 1;
    return answer;
}
