//boj 1269 대칭 차집합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    vector<long long int> s1;
    vector<long long int> s2;  
    cin >> n >> m;
    for (int i=0;i<n;i++){
        long long int num;
        cin >> num;
        s1.push_back(num);
    }
    for (int i=0;i<m;i++){
        long long int num;
        cin >> num;
        s2.push_back(num);
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    //set_union, set_intersection : 정렬된 집합이 전제.
    vector<long long int> us(n+m);
    vector<long long int> is(n+m);
    auto iter = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), us.begin());
    us.erase(iter, us.end()); // 합집합
    iter = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), is.begin());
    is.erase(iter, is.end()); // 교집합
    cout << us.size() - is.size() << endl;  
    return 0;
}
