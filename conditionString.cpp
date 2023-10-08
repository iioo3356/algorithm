// 프로그래머스 조건 문자열
#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
 int answer = 0;
    if (ineq == ">"){
        if (eq == "="){            
            if (n >= m)
                answer = 1; 
            else 
                answer = 0;
        }
        else {
            if (n > m) answer = 1;
            else answer = 0;
        }
    }
    else {
        if (eq == "=") {
            if (n<=m) answer = 1;
            else answer = 0;
        }
        else {
            if (n<m) answer = 1;
            else answer = 0;
        }

    }    
    return answer;
}
