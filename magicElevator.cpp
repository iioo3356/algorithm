// 마법의 엘리베이터
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    int flag = -1;
    while (storey > 0) {
        int num = storey % 10;   
        
        if (num < 5) {
            flag = -1;
        }
        else if (num > 5) { 
            num = 10 - num;
            flag = 1;
        }    
        else {
            int left = (storey / 10) % 10;
            if (left< 5) {
                flag = -1;
            } else {
                flag = 1;
            }
        
        }
        answer += num;
        storey += num * flag;
        storey /= 10;
    }
   
    return answer;
}
