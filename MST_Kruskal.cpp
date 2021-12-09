#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>

using namespace std;
int root[999999];

int parent(int a)                                                       //find the parent of the given node
{
    while(root[a] != a)
    {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void union_set(int a, int b)                                         //check if the given two vertices are in the same “union” or not
{
    int d = parent(a);
    int e = parent(b);
    root[d] = root[e];
}


struct Edge{
    int start;
    int w;
    int end;

    bool operator<(const Edge& a) const{
        return w < a.w;
    }
};

void mst_kruskal(vector<Edge>& weights, int numNodes){
    unsigned long long int sum = 0;
    // set<int> A;
    // vector<set<int>> B;
    // set<int>::iterator iter;

    // for (int i=0;i<numNodes+1;i++){
    //     set<int> k;
    //     k.insert(i);
    //     B.push_back(k);
    // }

    sort(weights.begin(), weights.end());

    for (int i=0;i<weights.size();i++){
        // if (A.size() == numNodes){
        //     break;
        // }
        int u = weights[i].start;
        int v = weights[i].end;
        int w = weights[i].w;
        // set<int> u_index = B[u];
        // set<int> v_index = B[v];
        // cout << u << " " << v << " "<< w << endl;
        // if (u_index != v_index){
        if (parent(u) != parent(v)){
            // A.insert(u);
            // A.insert(v);
            // B[v].insert(u);
            // B[u].insert(v);
            union_set(u, v);

            // for (int i=1;i<B.size();i++){
            //     set<int>::iterator iter_u;
            //     set<int>::iterator iter_v;
            //     iter_u = B[i].find(u);
            //     iter_v = B[i].find(v);
            //     set<int> bigger;
            //     if (B[u].size() >= B[v].size()){
            //         bigger = B[u];
            //     }
            //     else{
            //         bigger = B[v];
            //     }
            //     if (iter_u!=B[i].end()){
            //         B[i] = bigger;
            //     }
            //     else if (iter_v!=B[i].end()){
            //         B[i] = bigger;
            //     }
            //     for(iter = B[i].begin(); iter != B[i].end(); iter++){
            //         cout << *iter << " " ;
            //     }
            //     cout << endl;
            // }
            
            sum += w;
        }

    }
    cout << sum << endl;
}

int main(){

    int numTestCases, numNodes, k, m, v, w;
    cin >> numTestCases;
    for (int test=0;test<numTestCases;test++){
        cin >> numNodes;
        // vector<vector<pair<int, int>>> G(numNodes+1);
        vector<Edge> weights;
        for (int node=0;node<numNodes;node++){
            cin >> k >> m;
            for (int i=0;i<m;i++){
                cin >> v >> w;
                if (k<v){
                    Edge edge;
                    edge.start = k;
                    edge.end = v;
                    edge.w = w;
                    weights.push_back(edge);
                }
            }

        }

        for (int i=0;i<99999;i++){
            root[i] = i;
        }

        mst_kruskal(weights, numNodes);
        // cout << sum << endl;
    
    }
    return 0;
}