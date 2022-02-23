// 프로그래머스 H-index
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> citations) {
    int answer = -1;
    for (int i=citations[0];i>=0;i--){
        int h = i;
        int left = 0;
        for (int j=0;j<citations.size();j++){
            if (h<=citations[j]) left += 1;
        }
        if (h<=left){
            if (answer<h) answer = h;
        }
    }
    return answer;
}
