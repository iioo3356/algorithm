// boj 1931 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int, int> b){
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main() {
    int n, st, et;
    vector<pair<int, int>> v;
    pair<int,int> c;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> st >> et;
        v.push_back(make_pair(st,et));
    }
    sort(v.begin(), v.end(), cmp);
    c = v[0];
    int answer = 1;
    for (int i=1;i<n;i++){
        if (c.second <= v[i].first){
            c = v[i];
            answer+=1;
        }
    }
    cout << answer << endl;
    return 0;
}
