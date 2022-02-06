// 프로그래머스 약수의 개수와 덧셈
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<int> v;
    vector<int> p;
    vector<bool> q;
    for (int i=left;i<=right;i++){
        v.push_back(i);
        p.push_back(1);
    }
    for (int i=2;i<=right;i++){
        q.push_back(false);
    }
    for (int i=2;i<=right;i++){
        for (int j=i;j<=right;j*=i){
            if (q[j] == false){
                for (int k=0;k<p.size();k++){
                    if (v[k]%j==0) {
                        p[k] += 1;
                    }
                }
                q[j] = true;
            }

        }
    }
    for (int i=0;i<p.size();i++){
        if (p[i]%2==0) answer += v[i];
        else answer -= v[i];
    }
    return answer;
}
