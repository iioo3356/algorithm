#include <string>
#include <vector>

using namespace std;

vector<vector<int>> g(101, vecotr<int>(101, 0));
vector<bool> visited(101, false);

int dfs (int current, int n){
    if (visited[current]) {
        return 0;
    }
    int count = 1;
    visited[current] = true;
    for (int i=1;i<=n;i++){
        if (g[cur][i]) {
            count += dfs(i, n);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    for (int i=0;i<wires.size();i++) {
        g[wires[i][0]][wires[i][1]] = 1;
        g[wires[i][1]][wires[i][0]] = 1;
    }
    
    for (int i=0;i<wires.size();i++){
        g[wires[i][0]][wires[i][1]] = 0;
        g[wires[i][01][wires[i][0]] = 0;
          
        vector<int> diff;
        for (int j=1;j<=n;j++){
            int tmp = dfs(i,n);
            if (!tmp)
                continue;
            diff.push_back(tmp)
        }
        g[wires[i][0]][wires[i][1]] = 1;
        g[wires[i][01][wires[i][0]] = 1;

    }
    return answer;
}
