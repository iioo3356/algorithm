#include <vector>
#include <iostream>
#include <stack>
using namespace std;

#define MAX 987654321
#define NIL -1

int n, m, x;
vector<vector<pair<int,int>>> fw;
stack<int> path;

int main(){
    scanf("%d %d %d", &n, &m, &x);

    fw.resize(n+1);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            fw[i].push_back(make_pair(MAX, NIL));
            if (i==j) fw[i][j].first = 0;
        }
    }

    for (int i=0;i<m;i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        fw[u-1][v-1].first = w;
        fw[u-1][v-1].second = u-1;
    }

    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (fw[i][j].first > fw[i][k].first + fw[k][j].first){
                    fw[i][j].first = fw[i][k].first + fw[k][j].first;
                    fw[i][j].second = fw[k][j].second;
                }
            }
        }
    }
}