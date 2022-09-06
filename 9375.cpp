//boj 9375 패션왕 신해빈
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int numTestCases;
    cin >> numTestCases;
    for (int t=0;t<numTestCases;t++){
        int n;
        cin >> n;
        unordered_map<string, int> um;
        for (int i=0;i<n;i++){
            string name, type;
            cin >> name >> type;
            if (um.find(type) == um.end()) {
                um[type] = 1;
            }
            else {
                um[type] += 1;
            }
        }
        int answer = 1;
        for (auto iter=um.begin();iter!=um.end();++iter) {
            answer *= ((*iter).second + 1);
        }
        answer -= 1;
        cout << answer << "\n";
    }
    return 0;
}
