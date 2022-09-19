//boj 25501 재귀의 귀재
#include <iostream>
#include <string>
using namespace std;

string s;
int count;

int recursion(int l, int r){
    count++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(l+1, r-1);
}

int isPalindrome(){
    count = 0;
    return recursion(0, s.size()-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> s;
        cout << isPalindrome() << " " << count << "\n";
    }
    return 0;
}
