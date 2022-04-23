// 프로그래머스 k진수에서 소수 개수 세기
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool prime(long long int n) {
    if(n < 2) return false;
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string convertS = "";
    vector<string> nums;
    while (n>0){
        convertS = to_string(n%k) + convertS;
        n /= k;
    }
    string tempS = "";

    for (int i=0;i<convertS.size();i++){    
        if (convertS[i] == '0'){
            nums.push_back(tempS);
            tempS = "";
        }
        else {
            tempS += convertS[i];
        }
    }
    nums.push_back(tempS);
    
    for (int i=0;i<nums.size();i++){
        if (!nums[i].empty()){
            if (prime(stoll(nums[i]))) answer++;
        }
    }
    return answer;
}
