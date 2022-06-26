//boj 14425 문자열 집합
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    int n, m, count = 0;
    unordered_map<string, bool> um;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        um[s] = true;
    }
    for (int j=0;j<m;j++){
        string s;
        cin >> s;
        if (um.find(s) != um.end()){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
