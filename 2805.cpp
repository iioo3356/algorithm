//boj 2805 나무 자르기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<unsigned long long> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned long long N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        unsigned long long num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    // 1부터 가장 큰 값으로 자른 개수를 이분탐색
    unsigned long long left = 0;
    unsigned long long right = v[N-1];

    unsigned long long answer;

    while (left < right) {
        unsigned long long mid = (left+right)/2;
        unsigned long long current = 0;
        for (int i=0;i<N;i++){
            current += v[i] <= mid?0:v[i]-mid;
        }

        if (current >= M){
            // 더 크게 잘라도 됨
            left = mid+1;
            answer = mid;
        }
        else {
            // 크기를 줄여야함
            right = mid;
        }
    }
    cout << answer << "\n";
    return 0;
}
