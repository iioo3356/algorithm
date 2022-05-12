// boj 2480 주사위 세 개
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int answer;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end(), greater<int> ());
    int same_count = 1;
    for (int i=1;i<3;i++){
        if (v[i-1] == v[i]) {
            same_count+=1;
            answer = v[i];
            }
        else if (i==1) same_count = 1;
    }
    if (same_count == 3){
        answer = 10000 + answer * 1000;
    }
    else if (same_count == 2){
        answer = 1000 + answer * 100;
    }
    else {
        answer = v[0] * 100;
    }
    cout << answer << endl;;
    return 0;
}
