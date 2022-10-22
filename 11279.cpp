// boj 11279 최대힙
#include <queue>
#include <iostream>
using namespace std;
 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<long long int> pq;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        long long int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()){ cout << 0 <<"\n"; continue;}
            cout << pq.top() << "\n";
            pq.pop();
        }
        else pq.push(num);
    }
    return 0;
}
