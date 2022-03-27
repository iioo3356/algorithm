#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;
    for (int i=0;i<numTestCases;i++){
        int change, coinTypeSize;
        vector<int> coin;
        cin >> change >> coinTypeSize;
        for (int j=0;j<coinTypeSize;j++){
            int value;
            cin >> value;
            coin.push_back(value);
        }
        vector<int> dp(change+1);
        dp[0] = 1; // 거스름돈이 0인 경우의 수는 1
        for (int j=0;j<=change;j++){
            dp[j] = 1; // 항상 잔돈 1짜리로 채울 수 있음
        }

        for (int j=1;j<coinTypeSize;j++){
            for (int k=coin[j];k<=change;k++){ //거스름돈이 그 다음으로 작은 잔돈 값과 같아질 때부터 경우의 수 추가됨
                dp[k] += dp[k-coin[j]];//k=4일 때 2원짜리 하나를 쓰면 나머지 2원이었을 때 가짓수를 더해야함 
                //해당 잔돈으로 거스른 경우의 나머지 잔돈의 가짓수와 더해줌
            }
        }
        cout << dp[change] <<endl;
    }
    return 0;
}
