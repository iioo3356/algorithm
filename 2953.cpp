//boj 2953 나는 요리사다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v(5,0);
    int max_num = 0;
    int max_idx = 0;
    for (int i=0;i<5;i++){
        for (int j=0;j<4;j++){
            int n;
            cin >> n;
            v[i] += n;  
        }
    }
    for (int i=0;i<5;i++){
        if (max_num <= v[i]){
            max_num = v[i];
            max_idx = i;
        }
    }
    cout << max_idx+1 << " " << max_num;
    return 0;
}
