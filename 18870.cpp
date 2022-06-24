//boj 18870 좌표압축
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    vector<int> v;    
    vector<int> v2;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        int num;
        scanf("%d", &num);
        v.push_back(num);
        v2.push_back(num);
    }    
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (int i=0;i<n;i++){
        int pos = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
        // find를 사용해도 같은 결과지만 lower_bound(이진탐색, 정렬 필수) 로 사용해야 시간복잡도가 줄어든다.
        printf("%d ", pos);
    }
    return 0;
}
