
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int check_par(vector<string> room, int r1, int c1, int r2, int c2){
    int min_r = min(r1, r2);
    int min_c = min(c1, c2);
    int max_r = max(r1, r2);
    int max_c = max(c1, c2);
    if(r1 == r2){
        if(room[r1][(c1+c2)/2] == 'X')
            return 1;
    }
    else if(c1 == c2){
        if(room[(r1+r2)/2][c1] == 'X')
            return 1;
    }
    else if(r2 == max_r && c2 == max_c){
        if(room[max_r-1][max_c] == 'X' && room[max_r][max_c-1] == 'X')
            return 1;
    }
    else if (r2 == max_r && c1 == max_c){
        if(room[min_r][min_c] == 'X' && room[max_r][max_c] == 'X')
            return 1;
    }
    return 0;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;  
    vector<pair<int, int>> person;
    int isOk = 1;
    for (int i=0;i<5;i++){
        person.clear();
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k] == 'P')
                    person.push_back(make_pair(j, k));;
            }
        }
        isOk = 1;
        for(int j=0;j<person.size();j++){
            for(int k=j+1; k<person.size(); k++){
                int dist=0;
                dist = abs(person[j].first - person[k].first) + abs(person[j].second-person[k].second);
                if(dist <= 2){
                    if(check_par(places[i], person[j].first, person[j].second, person[k].first, person[k].second) == 0){
                        isOk = 0;
                        break;
                    }
                }
            }
            if(isOk == 0) break;
        }
        answer.push_back(isOk);
    }   
    return answer;
}
