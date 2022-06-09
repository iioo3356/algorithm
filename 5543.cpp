#include <iostream>
#include <vector>
using namespace std;

int main() {
    int min_bu = 3000;
    int min_be = 3000;
    for (int i=0;i<3;i++){
        int bu;
        cin >> bu;
        min_bu = min(bu, min_bu);
    }
    for (int i=0;i<2;i++){
        int be;
        cin >> be;
        min_be = min(be, min_be);
    }
    cout << min_bu + min_be -50 << endl;
    return 0;
}
