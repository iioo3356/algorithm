#include <vector>
#include <iostream>
#include <climits>
using namespace std;
int memoized_cut_rod_aux(vector<int> &p, int n, vector<int> &r);

// top down
void memoized_cut_rod(vector<int> &p, vector<int> &r, int n){
    for (int i=0;i<n+1; i++){
        r[i] = INT_MIN;
    }
    memoized_cut_rod_aux(p, n, r);
}

int memoized_cut_rod_aux(vector<int> &p, int n, vector<int> &r){
    int q;
    if (r[n] >= 0){
        return r[n];
    }
    if (n==0){
        q=0;
    }
    else {
        q = INT_MIN;
        for (int i=0;i<n;i++){
            q = max(q, p[i]+memoized_cut_rod_aux(p, n-i-1, r));
        }
    }
    r[n] = q;
    return q;
}

//bottom up
void bottom_up_cut_rod(vector<int> &p,vector<int> &r,vector<int> &s, int n){
    r[0] = 0;
    int q;
    for (int j=1;j<=n;j++){
        q = INT_MIN;
        for (int i=0;i<j;i++){
            if (q<p[i]+r[j-i-1]){
                q = p[i]+r[j-i-1];
                s[j] = i+1;
            }
        }
        r[j] = q;
    }
}

void print_cut_rod_solution(vector<int> &s, int n){
    while (n>0){
        cout << s[n]<<endl;
        n = n-s[n];
    }
}
int main(){
    vector<int> p = {1,5,8,9,10,17,17,20,24,30};
    int n = p.size();
    vector<int> r(n+1);
    vector<int> s(n+1);
    bottom_up_cut_rod(p, r, s, n);

    for (int i=0;i<r.size();i++){
        cout << r[i] << " ";
    }
    cout << endl;

    for (int i=0;i<r.size();i++){
        cout << s[i] << " ";
    }
    cout << endl;

    print_cut_rod_solution(s, 9);

    vector<int> r2(n+1);

    memoized_cut_rod(p, r2, n);
    for (int i=0;i<r2.size();i++){
        cout << r2[i] << " ";
    }
    cout << endl;


    return 0;
}
