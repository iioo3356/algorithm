//boj 24060 알고리즘 수업 - 병합 정렬 1
#include <iostream>
using namespace std;
long long int  a[500001]={0};
long long int k;
long long int count;
long long int num;

void merge(int p, int q, int r){
    int i = p;
    int j = q+1;
    int t = 0;
    long long int tmp[r-p];
    while (i<=q && j<=r){
        if (a[i] <= a[j]){
            tmp[t] = a[i];
            t++;
            i++;
        }
        else {
            tmp[t] = a[j];
            t++;
            j++;
        }
    }
    while (i<=q) {
        tmp[t] = a[i];
        t++;
        i++;
    }
    while (j<=r) {
        tmp[t] = a[j];
        t++;
        j++;
    }
    i = p;
    t = 0;
    while (i<=r){
        a[i] = tmp[t];
        if (count < k) {
            num = tmp[t];
        } 
        i++;
        t++;
        count++;
    }
}

void merge_sort(int p, int r){
    if (p<r){
        int q = (p+r)/2;
        merge_sort(p, q);
        merge_sort(q+1, r);
        merge(p,q,r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> a[i];
    merge_sort(0, n-1);
    if (count >= k) cout << num;
    else cout << -1;
    return 0;
}
