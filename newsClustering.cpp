// 프로그래머스 뉴스 클러스터링
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> u1;
    unordered_map<string, int> u2;
    string current;
    set<string> s;
    int min_num = 0;
    int max_num = 0;
    for (int i=0;i<str1.size()-1;i++){
        current = str1.substr(i,2);
        if ((('a'<=current[0] && current[0]<='z') || 'A'<=current[0] && current[0] <='Z')&& ('a'<=current[1] && current[1] <='z' || 'A'<=current[1] && current[1] <='Z')) {
            current[0] = tolower(current[0]);
            current[1] = tolower(current[1]);
            s.insert(current);
            if (u1.find(current) != u1.end()) u1[current] += 1;
            else u1[current] = 1;
            if (u2.find(current) == u2.end()) u2[current] = 0;
        }
    }
    for (int i=0;i<str2.size()-1;i++){
        current = str2.substr(i,2);
        if ((('a'<=current[0] && current[0]<='z') || 'A'<=current[0] && current[0] <='Z')&& ('a'<=current[1] && current[1] <='z' || 'A'<=current[1] && current[1] <='Z')) {
            current[0] = tolower(current[0]);
            current[1] = tolower(current[1]);
            if (u2.find(current) != u2.end()) u2[current] += 1;
            else u2[current] = 1;
            if (u1.find(current) == u1.end()) u1[current] = 0;
            s.insert(current);
        }
    }
    set<string>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        min_num += min(u1[*iter], u2[*iter]);
        max_num += max(u1[*iter], u2[*iter]);
    }
    if (min_num == 0 && max_num == 0) return 65536;
    answer = ((double)min_num/max_num) * (int)65536;
    
    return answer;
}
