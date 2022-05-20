//boj 2309 일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> dwarfs;
    int total_num = 0;
    int minus;
    for (int i=0;i<9;i++){
        int dwarf;
        cin >> dwarf;
        total_num += dwarf;
        dwarfs.push_back(dwarf);
    }
    minus = total_num - 100;
    for (int i=0;i<8;i++){
        bool isSuccess = false;
        for (int j=i+1;j<9;j++){
            if (dwarfs[i] + dwarfs[j] == minus){
                isSuccess = true;
                dwarfs.erase(dwarfs.begin()+i);
                dwarfs.erase(dwarfs.begin()+j-1);
                break;
            }
        }
        if (isSuccess) break;
    }
    sort(dwarfs.begin(), dwarfs.end());
    for (int i=0;i<7;i++){
        cout << dwarfs[i] << endl;
    }
    return 0;
}
