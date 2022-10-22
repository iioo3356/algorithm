#include <queue>
#include <iostream>
using namespace std;
 

int main() {
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
