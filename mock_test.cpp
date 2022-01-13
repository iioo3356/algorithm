// 프로그래머스 모의고사
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers_list) {
    vector<int> answer;
    vector<int> first_supoja;
    vector<int> second_supoja;
    vector<int> third_supoja;
    for (int i=0;i<8;i++){
        for (int j=1;j<6;j++){
            first_supoja.push_back(j);
        }
    }
    for (int i=0;i<5;i++){
        second_supoja.push_back(2);
        second_supoja.push_back(1);
        second_supoja.push_back(2);
        second_supoja.push_back(3);
        second_supoja.push_back(2);
        second_supoja.push_back(4);
        second_supoja.push_back(2);
        second_supoja.push_back(5);
        
    }
    for (int i=0;i<4;i++){
        third_supoja.push_back(3);
        third_supoja.push_back(3);
        third_supoja.push_back(1);
        third_supoja.push_back(1);
        third_supoja.push_back(2);
        third_supoja.push_back(2);
        third_supoja.push_back(4);
        third_supoja.push_back(4);
        third_supoja.push_back(5);
        third_supoja.push_back(5);
    }
    vector<int> scores = {0,0,0};
    for (int i=0;i<answers_list.size();i++){
        if (answers_list[i] == first_supoja[i-40*(i/40)]) scores[0]+=1;
        if (answers_list[i] == second_supoja[i-40*(i/40)]) scores[1]+=1;
        if (answers_list[i] == third_supoja[i-40*(i/40)]) scores[2]+=1;
    }
    
    int max_0_1 =  max(scores[0], scores[1]);
    int allMax = max(max_0_1, scores[2]);
    
    for (int i=0;i<3;i++){
        if (scores[i]==allMax){
            answer.push_back(i+1);
        }
    }
      
    return answer;
}
