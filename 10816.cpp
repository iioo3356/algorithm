//boj 10816 숫자 카드 2
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    fastio;
    int n, m;
    unordered_map<string, int> um;
    cin >> n;
    for (int i=0;i<n;i++){
        string num;
        cin >> num;
        if (um.find(num) != um.end()) um[num] += 1;
        else um[num] = 1;
    }
    cin >> m;
    for (int i=0;i<m;i++){
        string num;
        cin >> num;
        cout << um[num] << " ";
    }
    return 0;
}
