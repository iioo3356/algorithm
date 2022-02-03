// 프로그래머스 카카오 블라인드 채용 1차 비밀지도
#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> bArr1;
    vector<string> bArr2;
    for (int i=0;i<n;i++){
        bitset<16> b1(arr1[i]);
        bitset<16> b2(arr2[i]);
        bArr1.push_back(b1.to_string().substr(b1.to_string().size()-n));
        bArr2.push_back(b2.to_string().substr(b1.to_string().size()-n));
    }
    for (int i=0;i<n;i++){
        string row = "";
        for (int j=0;j<n;j++){
            if (bArr1[i][j]=='0' && bArr2[i][j]=='0'){
                row += " ";
            }
            else{
                row += "#";
            }
        }
        answer.push_back(row);
    }
    return answer;
}
