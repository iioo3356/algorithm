//boj 10808 알파벳 개수
#include <iostream>
using namespace std;

int main(){
    int alphabet[26] = {0,};
    string s;
    cin >> s;
    for (int i=0;i<s.size();i++){
        alphabet[s[i]-97] += 1;
    }
    for (int i=0;i<26;i++){
        cout << alphabet[i] << " ";
    }
    return 0;
}
