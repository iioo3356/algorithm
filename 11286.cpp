// boj 11286 절댓값 힙
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct cmp {
    bool operator()(long long int a, long long int b){
        if (abs(a) == abs(b)){
            return a > b;
        }
        else {
            return abs(a) > abs(b);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<long long int, vector<long long int>,  cmp> pq;
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        long long int x;
        cin >> x;
        if (x == 0){
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
    return 0;
}
