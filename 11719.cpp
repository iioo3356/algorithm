// boj 11719 그대로 출력하기 2
#include <iostream>
#include <string>
using namespace std;

int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (!cin.eof()){
        string s;
        getline(cin, s);
        cout << s << "\n";
    }
    return 0;
}
