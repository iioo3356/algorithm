// 백준 1476 날짜계산
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;
    vector<vector<int>> v = {{0,0,0}};
    int current = 0;
    while (!(v[current][0] == e && v[current][1] == s && v[current][2] == m)){
        vector<int> tmp = {v[current][0] + 1, v[current][1] +1, v[current][2] +1};
        if (tmp[0] > 15){
            tmp[0] = 1;
        }
        if (tmp[1] > 28){
            tmp[1] = 1;
        }
        if (tmp[2] > 19) {
            tmp[2] = 1;
        }
        v.push_back(tmp);
        current += 1;
    }
    cout << current << endl;
    return 0;
}
