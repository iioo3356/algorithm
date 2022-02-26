// 프로그래머스 최솟값 만들기
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    for (int i=0;i<A.size();i++){
        answer += A[i]*B[i];
    }
    return answer;
}
