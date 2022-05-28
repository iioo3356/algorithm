//boj 13458 시험감독
#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long int n, b, c;
    long long int answer = 0;
    vector<long long int> a;
    cin >> n;
    for (long long int i=0;i<n;i++){
        long long int ai;
        cin >> ai;
        a.push_back(ai);
    }
    cin >> b >> c;
    for (long long int i=0;i<n;i++){
        a[i] -= b;
        answer += 1;
        if (a[i] <= 0) {
            continue;
        }
        if (a[i] % c == 0) {
            answer += a[i]/c;
        }
        else {
            answer += (a[i]/c)+1;
        }
    }
    cout << answer << endl;
    return 0;
}
