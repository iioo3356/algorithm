//boj 10866 덱
#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    deque<int> dq;
    string s;
    int num;
    for (int i=0;i<n;i++){
        cin >> s;
        if (s=="push_front"){
            cin >> s;
            num = stoi(s);
            dq.push_front(num);
        }
        else if (s=="push_back"){
            cin >> s;
            num = stoi(s);
            dq.push_back(num);
        }
        else if (s=="pop_front"){
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (s=="pop_back"){
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (s=="size"){
            cout << dq.size() << "\n";
        }
        else if (s=="empty"){
            if (dq.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (s=="front"){
            if (dq.empty()) cout << "-1\n";
            else cout << dq.front() << "\n";
        }
        else if (s=="back"){
            if (dq.empty()) cout << "-1\n";
            else cout << dq.back() << "\n";
        }
    }
    return 0;
}
