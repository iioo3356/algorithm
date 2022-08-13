#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=n;i>0;i--){
        string s;
        for (int j=0;j<i;j++){
            s += "*";
        }
        cout << s << endl;
    }
    return 0;
}
