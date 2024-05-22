#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    string cvt = "";
    cin >> str;

    for (int i=0;i<str.size();i++){
        if (str[i] >= 'a' && str[i] <= 'z') {
            cvt += (str[i] - 'a' + 'A');
        }
        else {
            cvt += (str[i] - 'A' + 'a');
        }

    }
    cout << cvt;
    return 0;
}
