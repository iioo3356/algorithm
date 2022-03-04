// 프로그래머스 소수찾기
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(string numbers) {
    int answer = 0;
    vector<int> seq;
    sort(numbers.begin(), numbers.end());
    int len = 1;
    vector<bool> check(pow(10,numbers.size()), false);
    while (len<=numbers.size()){
        do {
            int n = stoi(numbers.substr(0,len));
            if (!check[n]) seq.push_back(n);
            check[n] = true;
            reverse(numbers.begin()+len,numbers.end());
        } while (next_permutation(numbers.begin(), numbers.end()));
        len += 1;
    }
    
    vector<bool> b(seq[seq.size()-1]+1,true);
    b[0] = false;
    b[1] = false;
    for (int i=2;i<=seq[seq.size()-1];i++){
        if (b[i]){
            for (int j=i*2;j<=seq[seq.size()-1];j+=i){
                b[j] = false;
            }
        }
    }
    for (int i=0;i<seq.size();i++){
        if (b[seq[i]]) {
            answer += 1;
        }
    }

    return answer;
}
