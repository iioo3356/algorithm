// boj 11066 파일 합치기
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int numTestCases;
    cin >> numTestCases;
    for (int t=0;t<numTestCases;t++){
        int k;//소설의 장의 수
        cin >> k;
        vector<int> s; // 파일 합칠 떄의 비용
        for (int i=0;i<k;i++){
            int num;
            cin >> num;
            if (i==0) s.push_back(num);
            else s.push_back(s[i-1]+num);
        }
        int dp[501][501] = {0,}; 
        // dp[i][j] : 인덱스 i에서 j까지의 파일들을 합쳤을 때의 최소비용
        // 그룹을 두 개로 나누고 각 그룹에서의 최솟값을 더해야함
        for (int i=1;i<k;i++){ // 범위
            for (int j=0;j<k-i;j++){ //시작값
                int e = i+j; // 끝값
                int ps = s[e] -s[j-1]; // 비용계산
                dp[j][e] = INT_MAX;
                for (int n=j;n<e;n++){ //두 개로 나눈 구역 중 최소값 계산
                    dp[j][e] = min(dp[j][e], dp[j][n]+dp[n+1][e]+ps);
                }
            }
        }
        cout << dp[0][k-1] << endl;
    }
    return 0;
}
