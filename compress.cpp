#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    int num = 1;
    unordered_map<string, int> um;

    for (char i='A';i<='Z';i++){
        string s = "";
        s = i;
        um[s] = num;
        num++;
    }
    string current;
    while (msg.size() > 0) {
        current = msg[0];
        int i=1;
        while (um.find(current) != um.end()){
            current += msg[i];
            i++;
        }
        string findStr = current.substr(0, i-1);
        answer.push_back(um[findStr]);
        um[current] = num;
        num++;
        if (i<msg.size()){
            msg = msg.substr(i-1, msg.size());
        }
        else {
            break;
        }
   
    }
    return answer;
}
