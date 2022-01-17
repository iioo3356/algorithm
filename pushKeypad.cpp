// 프로그래머스 키패드 누르기
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    vector<pair<int, int>> keypads;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            keypads.push_back(make_pair(i, j));
        }
    }
    
    keypads.push_back(make_pair(3,1));
    
    pair<int, int> left = make_pair(3,0);
    pair<int, int> right = make_pair(3,2);
    
    string answer = "";
    for (int i=0;i<numbers.size();i++){
        pair<int, int> position;
        if (numbers[i] == 0) position = keypads[9];
        else position = keypads[numbers[i]-1];
        if (position.second == 0){
            answer += "L";
            left = position;
        }
        else if (position.second == 2){
            answer += "R";
            right = position;
        }
        else {
            int left_dist = abs(left.first-position.first) + abs(left.second-position.second);
            int right_dist = abs(right.first-position.first) + abs(right.second-position.second);
            if (left_dist<right_dist) {
                answer += "L";
                left = position;
            }
            else if (left_dist>right_dist){
                answer += "R";
                right = position;
            }
            else {
                if (hand == "right"){
                    answer += "R";
                    right = position;
                }
                else{
                    answer += "L";
                    left = position;
                }
            }
            
        }
    }
    return answer;
}
