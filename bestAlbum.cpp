// 베스트앨범
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmpGenres (pair<string,vector<pair<int,int>>> a, pair<string,vector<pair<int,int>>> b) {
    int suma = 0;
    int sumb = 0;
    for (int i=0;i<a.second.size();i++){
        suma += a.second[i].second;
    }
    for (int i=0;i<b.second.size();i++){
        sumb += b.second[i].second;
    }
    return suma > sumb;
}

bool cmpPlays (pair<int,int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> m;
    for (int i=0;i<plays.size();i++){
        if (m.find(genres[i]) != m.end()){
            m[genres[i]].push_back(make_pair(i, plays[i]));
        }
        else {
            vector<pair<int, int>> v;
            v.push_back(make_pair(i, plays[i]));
            m[genres[i]] = v;
        }
    }
    vector<pair<string,vector<pair<int,int>>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmpGenres);
    for (int i=0;i<v.size();i++){
        string g = v[i].first;
        sort(m[g].begin(),m[g].end(), cmpPlays);
        for (int j=0;j<m[g].size() && j<2;j++){
            answer.push_back(m[g][j].first);
        }
    }
    return answer;
}
