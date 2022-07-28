#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> v(10,0);
    string n;
    cin >> n;
    int answer = 0;
    for (int i=0;i<n.size();i++){
        int ni = n[i] - '0';
        if (n[i] == '6' || n[i] == '9') v[6] += 1;
        else v[ni] += 1;
    }
    v[6] = (v[6]+1) / 2;
    for (int i=0;i<10;i++){
        answer = max(answer, v[i]);
    }
    cout << answer;
    return 0;
}
