//boj 11759 ccw
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<pair<int,int>> v;
    int x, y;
    for (int i=0;i<3;i++){
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    int s = (v[1].first - v[0].first) * (v[2].second - v[1].second) - (v[1].second - v[0].second) * (v[2].first - v[1].first);

    if (s > 0) cout << 1;
    else if (s < 0) cout << -1;
    else cout << 0;
    return 0;
}
// CCW 알고리즘 참조 https://travelbeeee.tistory.com/45
