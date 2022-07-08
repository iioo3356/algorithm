//boj 1966 프린터 큐
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int numTestCases;
    cin >> numTestCases;
    for (int t=0;t<numTestCases;t++){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> v;
        vector<int> c;
        for (int i=0;i<n;i++){
            int num;
            cin >> num;
            v.push_back(make_pair(i, num));
        }
        while (true){
            bool isHigh = true;
            for (int i=1;i<v.size();i++){
                if (v[i].second > v[0].second){
                    isHigh = false;
                    break;
                }
            }
            if (isHigh) {
                c.push_back(v[0].first);
                if (v[0].first == m){
                    cout << c.size() << endl;
                    break;
                }
            }
            else {
                v.push_back(v[0]);
            }
            v.erase(v.begin());
        }
    }
    return 0;
}
