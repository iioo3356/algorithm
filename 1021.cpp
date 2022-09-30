//boj 1021 회전하는 큐
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, target;
    cin >> n >> m;
    deque<int> dq;
    for (int i=1;i<=n;i++){
        dq.push_back(i);
    }
    int left, right; // 왼쪽에 남은 수, 오른쪽에 남은 수
    int answer = 0;
    bool goLeft = false;
    for (int i=0;i<m;i++){
        cin >> target;
        if (i==0) {
            left = target-1;
            right = n-target;
        }
        else {
            int currentIndex = 0;
            for (int j=0;j<dq.size();j++){
                if (dq[j] == target){
                    currentIndex = j+1;
                    break;
                }
            }
            left = currentIndex-1;
            right = dq.size()-currentIndex;
        }

        while (dq.front() != target){
            answer++;
            if (left <= right){
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
            else {
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
        }
        dq.pop_front();
    }
    cout << answer << "\n";
    return 0;
}
