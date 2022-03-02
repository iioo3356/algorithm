// 프로그래머스 파일명 정렬
#include <string>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
using namespace std;

bool cmp(string a, string b){
    int a_idx_f=-1;
    int b_idx_f=-1;
    int a_idx_s=-1;
    int b_idx_s=-1;
    for (int i=0;i<a.size();i++){
        if (a_idx_f > -1 && ((a[i]>='a' && a[i]<='z')|| (a[i]>='A' && a[i]<='Z') || a[i]=='.'||a[i]=='-'||a[i]==' ')){
            a_idx_s = i;
            break;
        }
        else if (a_idx_f == -1 && a[i]>='0' && a[i]<='9'){
            a_idx_f = i;
        }
    }
    for (int i=0;i<b.size();i++){
        if (b_idx_f > -1 && ((b[i]>='a' && b[i]<='z')|| (b[i]>='A' && b[i]<='Z') || b[i]=='.'||b[i]=='-'||b[i]==' ')){
            b_idx_s = i;
            break;
        }
        else if (b_idx_f == -1 && b[i]>='0' && b[i]<='9'){
            b_idx_f = i;
        }
    }
    string a_head = a.substr(0, a_idx_f);
    string b_head = b.substr(0, b_idx_f);
    boost::algorithm::to_lower(a_head);
    boost::algorithm::to_lower(b_head);
    int a_number = stoi(a.substr(a_idx_f, a_idx_s-a_idx_f));
    int b_number = stoi(b.substr(b_idx_f, b_idx_s-b_idx_f));
    if (a_head == b_head){
        return a_number<b_number;
    }
    else {
        return a_head < b_head;
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer = files;
    stable_sort(answer.begin(), answer.end(), cmp);
    return answer;
}
