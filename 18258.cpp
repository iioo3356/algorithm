//boj 18258 큐 2
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int> q;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        if (s == "push"){
            string num;
            cin >> num;
            int x = stoi(num);
            q.push(x);
        }
        else if (s == "pop") {
            if (q.size() == 0) cout << "-1\n";
            else {
                cout << q.front() << "\n"; 
                q.pop();
            }
        }
        else if (s == "size") {
            cout << q.size() << "\n";
        }
        else if (s == "empty") {
            if (q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (s == "front") {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else if (s == "back") {
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }
    return 0;
}
