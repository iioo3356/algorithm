#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v;
    for (int i=0;i<n;i++){
        vector<int> t(i+1,0);
        v.push_back(t);
    }
    int num = 1;
    int max = n*(n+1)/2;
    int top = 1;
    int bottom = n;
    int left = 1;
    int right = 0;
    int case = 0;

    while (num <= max){
        if (case == 0){                
            for (int i = top; i <= bottom; i++) v[i][left] = num;
            top += 1;
            left += 1;
            num += 1;
            case = 1;
        }
        else if (case == 1){
          for (int i = Left; i <= Bottom - Right; i++) MAP[Bottom][i] = Num++;
            Bottom--;
            State = 2;
            case = 2;
        }
        else {
            for (int i = Bottom; i >= Top; i--) MAP[i][i - Right] = Num++;
            Right++;
            Top++;
            case 3;
        }
        
    }
    return answer;
}
