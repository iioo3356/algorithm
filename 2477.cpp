//boj 2477 참외밭
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num, max_i, min_s;
    int max_s = 0;
    vector<int> lengths;
    cin >> num;
    for (int i=0;i<6;i++){
        int d, l;
        cin >> d >> l;
        lengths.push_back(l);
    }
    for (int i=0;i<6;i++){
        if (max_s < lengths[i]*lengths[(i+1)%6]){
            max_i = i;
            max_s = lengths[i]*lengths[(i+1)%6];
        }
    }
    min_s = lengths[(max_i+3)%6] * lengths[(max_i+4)%6];
    cout <<(max_s - min_s) * num << endl;
    return 0;
}
