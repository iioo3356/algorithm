//boj 10798 세로읽기
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s, answer = "";
    vector<string> v;
    int max_l = -1;
    for (int i=0;i<5;i++){
        cin >> s;
        int s_l = s.size();
        max_l = max(max_l, s_l);
        v.push_back(s);
    }
    for (int i=0;i<max_l;i++){
        for (int j=0;j<5;j++){
            if (v[j].size() > i){
                answer += v[j][i];  
            }
        }
    }
    cout << answer << endl;
    return 0;
}
