//boj 10773 제로
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int k, num;
    int answer = 0;
    vector<int> v;
    cin >> k;
    for (int i=0;i<k;i++){
        cin >> num;
        if (num == 0){
            v.erase(v.end()-1);
        }
        else {
            v.push_back(num);
        }
    }
    for (int i=0;i<v.size();i++){
        answer += v[i];
    }
    cout << answer << endl;
    return 0;
}
