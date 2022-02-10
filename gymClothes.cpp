// 프로그래머스 체육복
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> students(n, 1);
    for (int i=0;i<reserve.size();i++){
        students[reserve[i]-1] += 1;
    }
    for (int i=0;i<lost.size();i++){
        students[lost[i]-1] -= 1;
    }
    sort(lost.begin(), lost.end());
    for (int i=0;i<lost.size();i++){
        if (students[lost[i]-1] == 0){
            if (lost[i]-1 == 0){
                if (students[lost[i]]==2){
                    students[lost[i]] -= 1;
                    students[lost[i]-1] += 1;
                }
            }
            if (lost[i]-1 >0 && lost[i]-1 < n){
                if (students[lost[i]-2]==2) {
                    students[lost[i]-2] -= 1;
                    students[lost[i]-1] += 1;
                }
                else if (students[lost[i]]==2){
                    students[lost[i]] -= 1;
                    students[lost[i]-1] += 1;
                }
            }
            else{
                if (students[lost[i]-2]==2) {
                    students[lost[i]-2] -= 1;
                    students[lost[i]-1] += 1;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        if (students[i] == 0) answer -= 1;
    }
    return answer;
}
