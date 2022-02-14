// 프로그래머스 소수 만들기
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<bool> isPrime(3000, true);
    vector<int> sumArr;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i=2;i<isPrime.size();i++){
        if (isPrime[i]){
            for (int j=i*2;j<isPrime.size();j+=i){
                isPrime[j] = false;
            }
        }
    }
    for (int i=0;i<nums.size();i++){
        for (int j=i+1;j<nums.size();j++){
            for (int k=j+1;k<nums.size();k++){
                int sumN = nums[i] + nums[j] + nums[k];
                if (isPrime[sumN]) answer += 1;
            }
        }
    }
    
    return answer;
}
