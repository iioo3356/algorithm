//프로그래머스 최소직사각형
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for (int i=0;i<sizes.size();i++){
        if (sizes[i][0]<sizes[i][1]){
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }
    vector<int> width;
    vector<int> height;
    for (int i=0;i<sizes.size();i++){
        width.push_back(sizes[i][0]);
        height.push_back(sizes[i][1]);
    }
    sort(width.begin(), width.end(), greater<int>());
    sort(height.begin(), height.end(), greater<int>());
    answer = width[0] * height[0];
    
    return answer;
}
