// 프로그래머스 피로도
#include <string>
#include <vector>
using namespace std;

int result;
vector<bool> isVisit;

void dfs(int n, int k, vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        if (!isVisit[i] && v[i][0]<=k){
            isVisit[i]=true;
            dfs(n+1,k-v[i][1], v);
            isVisit[i]=false;
        }
    }
    result = max(result,n);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    for (int i=0;i<dungeons.size();i++){
        isVisit.push_back(false);
    }
    dfs(0, k, dungeons);
    answer = result;
    return answer;
}
