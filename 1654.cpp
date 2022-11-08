//boj 1654 랜선 자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K, N;
    cin >> K >> N;
    for(int i=0;i<K;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    // 1부터 가장 큰 값으로 자른 개수를 이분탐색
    long long left = 1;
    long long right = v[K-1];

    long long answer;

    while (left <= right) {
        long long mid = (left+right)/2;
        long long current = 0;
        for (int i=0;i<K;i++){
            current += (v[i]/mid);
        }

        if (current >= N){
            // 더 크게 잘라도 됨
            left = mid+1;
            answer = mid;
        }
        else {
            // 크기를 줄여야함
            right = mid-1;
        }
    }
    cout << answer << "\n";
    return 0;
}
