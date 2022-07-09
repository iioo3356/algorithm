//boj 5430 AC
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTestCases;
    cin >> numTestCases;
    for (int t=0;t<numTestCases;t++){
        bool isReverse = false, isError = false;
        string command, arrStr;
        int numArr;
        deque<int> dq;
        string num = "";
        cin >> command >> numArr >> arrStr;
        if (arrStr.size() > 2){
            for (int i=0;i<arrStr.size();i++){
                if (arrStr[i] == ',' || arrStr[i] == ']'){ 
                    dq.push_back(stoi(num));
                    num = "";
                }
                else if ('0'<=arrStr[i] && arrStr[i]<='9') num+=arrStr[i];
            }
        }
        for (int i=0;i<command.size();i++){
            if (command[i] == 'R'){
                isReverse = !isReverse;
            }
            else {
                if (dq.empty()) {
                    isError = true;
                    break;
                }
                else {
                    if (isReverse) {
                        dq.pop_back();
                    }
                    else {
                        dq.pop_front();
                    }
                }
            }
        }
        if (isError) {
            cout << "error" << endl;
            continue;
        }
        cout << "[";
        if (isReverse) {
            for (auto o=dq.rbegin();o!=dq.rend();o++){
                cout << *o;
                if (o < dq.rend()-1) cout << ",";
            }
        }
        else {
            for (auto o=dq.begin();o!=dq.end();o++){
                cout << *o;
                if (o < dq.end()-1) cout << ",";
            }
        }
        cout << "]" << endl;;
    }
    return 0;
}
