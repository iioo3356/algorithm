#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    for (int i=0;i<new_id.size();i++){
        if (new_id[i] != '-' && new_id[i] != '.' && new_id[i] != '_'){
            new_id[i] = ' ';
        }
    }
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());

    if (new_id.size() >=16) {
        if (new_id[14] == '.'){
            
            new_id = new_id.substr(0, 13);
        }
        else {
            
            new_id = new_id.substr(0, 14);
        }
    }
    else if (new_id.size() <= 2){
        while (new_id.size() < 3){
            new_id += new_id[new_id.size()-1];
        }
    }
    cout << new_id << endl;
    return answer;
}
