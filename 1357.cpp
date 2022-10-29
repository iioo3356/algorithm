// boj 1357 뒤집힌 덧셈
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string x, y;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    string answer = to_string(stoi(x) + stoi(y));
    reverse(answer.begin(), answer.end());
    cout << stoi(answer) << "\n";
    return 0;
}
