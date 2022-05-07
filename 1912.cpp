// 백준 1912 연속합
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    vector<int> nums;
    vector<int> memo;

    cin >> n;
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    int answer = nums[0];
    memo.push_back(nums[0]);
    for (int i=1;i<n;i++){
        answer = max(max(nums[i], memo[i-1]+nums[i]), answer);
        memo.push_back(max(nums[i], memo[i-1]+nums[i]));
    }

    cout << answer << endl;
    return 0;
}
