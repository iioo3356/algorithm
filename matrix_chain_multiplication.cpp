#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int main(void) {
    int n;
    vector<int> v;

    cin >>  n;
    for (int i=0; i<n+1; i++){
        int d;
        cin >> d;
        v.push_back(d);
    }
    
    // solve here and print the result using cout
    n = v.size() - 1;
    vector<vector<unsigned long long int>> m(n,vector <unsigned long long int>(n,0));
    
    for (int l=1;l<n;l++){
        for (int i=0;i<n-l;i++){
            int j = i + l;
            m[i][j] = ULLONG_MAX;
            for (int k=i;k<j;k++){
                unsigned long long int q = m[i][k] + m[k+1][j] + v[i]*v[k+1]*v[j+1];
                if (q < m[i][j]){
                    m[i][j] = q;
                }
            }
        }
    }
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<n;j++){
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << m[0][n-1] <<endl;
    return 0;
}
