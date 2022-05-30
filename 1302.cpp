#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main() {
    int n;
    cin >> n;
    unordered_map<string, int> um;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        if (um.find(s) == um.end()){
            um[s] = 0;
        }
        else {
            um[s] += 1;
        }
    }
    vector<pair<string,int>> vs(um.begin(), um.end());
    sort(vs.begin(), vs.end(), cmp);
    cout << vs[0].first << endl;

    return 0;
}
