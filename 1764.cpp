//boj 1764 듣보잡
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    unordered_map<string, bool> um; // 듣도 못한 사람이면 TRUE
    vector<string> v; // 듣보잡 배열
    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        string person;
        cin >> person;
        um[person] = true;
    }
    for (int i=0;i<m;i++){
        string person;
        cin >> person;
        if (um.find(person) != um.end()) v.push_back(person);
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }
    return 0;
}
