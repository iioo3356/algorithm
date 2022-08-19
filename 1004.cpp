//boj 1004 어린 왕자
#include <iostream>
#include <vector>
using namespace std;

bool isInCircle(int x, int y, int cx, int cy, int r) {
    int d = (cx-x)*(cx-x)+(cy-y)*(cy-y);
    if (d <= r*r) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numTestCases;
    cin >> numTestCases;
    for (int test=0;test<numTestCases;test++){
        pair<int, int> start, end;
        int n;
        vector<vector<int>> v;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;
        cin >> n;
        for (int i=0;i<n;i++){
            vector<int> tmp(3);
            cin >> tmp[0] >> tmp[1] >> tmp[2];
            v.push_back(tmp);
        }

        int answer = 0;
        for (int i=0;i<n;i++){
            int cx = v[i][0];
            int cy = v[i][1];
            int r = v[i][2];
            if (isInCircle(start.first, start.second, cx, cy, r) && 
            isInCircle(end.first, end.second, cx, cy, r))
                continue; // 둘 다 같은 원 안에 있는 경우
            else if (!isInCircle(start.first, start.second, cx, cy, r) && 
            !isInCircle(end.first, end.second, cx, cy, r)) 
                continue; // 둘 다 같은 원 바깥에 있는 경우
            else answer++; // 두 점 사이에 경계가 존재하는 경우
        }
        cout << answer << endl;
    }
    return 0;
}
