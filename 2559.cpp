// boj 2559 수열
#include <iostream>
#include <climits>
using namespace std;

int arr[100002];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int max_sum = INT_MIN;
    for (int i=1;i<=n;i++){
        cin >> arr[i];
        sum += arr[i];
        if (i >= k) {
            max_sum = max(max_sum, sum);
            sum -= arr[i-k+1];
        } 
    }
    cout << max_sum << endl;
    return 0;
}
