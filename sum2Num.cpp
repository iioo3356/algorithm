// 프로그래머스 두 개 뽑아서 더하기
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    for (int i=0;i<numbers.size()-1;i++){
        for (int j=i+1;j<numbers.size();j++){
            s.insert(numbers[i]+numbers[j]);
        }
    }
    set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        answer.push_back(*iter);
    }
    return answer;
}
