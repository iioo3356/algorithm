#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int mst_prim(vector<vector<pair<int, int>>> G, int numNodes, int r){
    vector<int> dist(numNodes+1, INT_MAX);
    // priority_queue<pair<int,int>> q;
    vector<pair<int,int>> q;
    vector<bool> isAdded(numNodes+1, true);
    
    int sum = 0;
    // q.push({r,0});
    q.push_back({r,0});

    dist[r] = 0;

    // for (int node=0;node<numNodes+1;node++){
    //     cout << dist[node] << " ";
    // }
    // cout << endl;

    while(!q.empty()){
        int minIndex = min_element(q.begin(), q.end(), [] (const auto& lhs, const auto& rhs){
            return lhs.second < rhs.second;
        }) - q.begin();
        // int here = q.top().first;
        // int cost = q.top().second;
        int here = q[minIndex].first;
        int cost = q[minIndex].second;
        // cout << "here " << here << endl;
        q.erase(q.begin()+minIndex);
        isAdded[here] = false;

        for (int i=0;i<G[here].size();i++){
            int next = G[here][i].first;
            int nextDist = G[here][i].second;

            if (isAdded[next] == true && dist[next] > nextDist){
                // cout << "next " << next << endl;
                dist[next] = G[here][i].second;
                auto it = std::find_if( q.begin(), q.end(),[&next](const std::pair<int, int>& element){ return element.first ==next;} );
                if (it == q.end()) q.push_back(make_pair(next, dist[next]));
                else *it = make_pair(next, dist[next]); 
            }
        }
    }
    
    for (int node=1;node<numNodes+1;node++){
    //     cout << dist[node] << " ";
        sum += dist[node];
    }
    // cout << endl;
    // cout << sum << endl;
    return sum;
}

int main(){

    int numTestCases, numNodes, k, m, v, w;
    cin >> numTestCases;
    for (int test=0;test<numTestCases;test++){
        cin >> numNodes;
        vector<vector<pair<int, int>>> G(numNodes+1);
        // G.resize(numNodes+1);
        // cout << G.size()<<endl;
        for (int node=0;node<numNodes;node++){
            cin >> k >> m;
            for (int i=0;i<m;i++){
                cin >> v >> w;
                G[k].push_back(make_pair(v,w));
            }

        }

        // for (int i=0;i<numNodes+1;i++){
        //     for (int j=0;j<G[i].size();j++){
        //         cout << G[i][j].first << " " << G[i][j].second << endl;
        //     }
        //     cout << endl << endl;
        // }

        int sum = mst_prim(G, numNodes, 1);

        cout << sum << endl;
    
    }
    return 0;
}