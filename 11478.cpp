//boj 11478 서로 다른 부분 문자열의 개수
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    string s;
    set<string> sc;
    cin >> s;
    // for (int i=0;i<s.size();i++){
    //     for (int k=0;k<s.size()-i;k++){
    //         string substring = "";
    //         for (int j=i;j<=i+k;j++){
    //             substring += s[j];
    //         }        
    //         sc.insert(substring);
    //     }
    // } // 시간 초과

    for (int i=0;i<s.size();i++){
        for (int j=1;j<=s.size()-i;j++){
            string substring = s.substr(i,j);
            sc.insert(substring);
        }
    }
    cout << sc.size() << endl;
    return 0;
}
