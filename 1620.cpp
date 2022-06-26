//boj 1620 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <map>
#include <vector>
#include <string>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    fastio;
    int n, m;
    map<string, int> um_s;
    vector<string> v(100001);
    cin >> n >> m;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        v[i+1] = s;
        um_s[s] = i+1;
    }
    for (int j=0;j<m;j++){
        string s;
        cin >> s;
        if ('1'<=s[0] && '9'>=s[0]) cout << v[stoi(s)] << "\n";
        else cout << um_s[s] << "\n"; 
        // endl 
    }
    return 0;
}
