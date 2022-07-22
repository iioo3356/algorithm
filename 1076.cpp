//boj 1076 저항
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<string, pair<int,long long int>> um;
    um["black"] = make_pair(0,1);
    um["brown"] = make_pair(1,10);
    um["red"] = make_pair(2,100);
    um["orange"] = make_pair(3,1000);
    um["yellow"] = make_pair(4,10000);
    um["green"] = make_pair(5,100000);
    um["blue"] = make_pair(6,1000000);
    um["violet"] = make_pair(7,10000000);
    um["grey"] = make_pair(8,100000000);
    um["white"] = make_pair(9,1000000000);
    long long int answer = 0;
    vector<string> v;
    for (int i=0;i<3;i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    answer = (um[v[0]].first*10) + um[v[1]].first;
    answer *= um[v[2]].second;
    cout << answer << endl;
    return 0;
} 
