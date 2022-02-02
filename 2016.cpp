// 프로그래머스 2016년
#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    string day[] = {"FRI", "SAT","SUN", "MON", "TUE", "WED","THU"};
    int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int sumDay = 0;
    for (int i=0;i<a-1;i++){
        sumDay += month[i];
    }
    sumDay += b-1;
    answer = day[sumDay%7];
    return answer;
}
