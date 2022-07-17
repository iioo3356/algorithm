// boj 2506 점수계산
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    int num = 1;
    for (int i=0;i<n;i++){
        int correct;
        cin >> correct;
        if (correct == 0){
            num = 1;
        }
        else {
            answer += num;
            num++;
        }
    }
    cout << answer << endl;
    return 0;
}
