// 프로그래머스 수식 최대화
#include <string>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

long long evaluate(long long a, long long b, char oper) {
    if (oper == '+')
        return a + b;
    else if (oper == '-')
        return a - b;
    else if (oper == '*')
        return a * b;
}

long long solution(string expression) {
    vector<char> oper = { '*', '+', '-' };
    long long answer = LONG_LONG_MIN;
    long long now = 0;
    vector<long long> nums;
    vector<char> ops;
    string numStr;
    for (int i=0;i<expression.size();i++){
        if ('0'<=expression[i] && expression[i]<='9'){
            numStr += expression[i];
        }
        else {
            nums.push_back(stoi(numStr));
            numStr = "";
            ops.push_back(expression[i]);
        }
    }
    nums.push_back(stoi(numStr));
    do {
        vector<long long> temp_nums = nums;
        vector<char> temp_ops = ops;

        for (int i = 0; i < oper.size(); i++) {
            for (int j = 0; j < temp_ops.size(); j++) {
                if (temp_ops[j] == oper[i]) {
                    temp_nums[j] = evaluate(temp_nums[j], temp_nums[j+1], oper[i]);
                    temp_nums.erase(temp_nums.begin() + j + 1);
                    temp_ops.erase(temp_ops.begin() + j);
                    j--;
                }
            }
        }

        if (abs(temp_nums.front()) > answer)
            answer = abs(temp_nums.front());
    } while (next_permutation(oper.begin(), oper.end()));
    return answer;
}
