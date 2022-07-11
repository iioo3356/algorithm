//boj 11098 첼시를 도와줘!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<long long, string> a, pair<long long, string> b){
    return a.first > b.first;
}
int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int t=0;t<numTestCases;t++){
        int p;
        string name;
        long long price;
        vector<pair<long long, string>> v;
        cin >> p;
        for (int i=0;i<p;i++){
            cin >> price >> name;
            v.push_back(make_pair(price, name));
        }
        sort(v.begin(), v.end(), cmp);
        cout << v[0].second << endl;
    }
    return 0;
}
