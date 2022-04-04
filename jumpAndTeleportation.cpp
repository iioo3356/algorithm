// 프로그래머스 점프와 순간이동
using namespace std;

int solution(int n)
{
    int ans = 0;  
    while (n>0){
        if (n%2 == 1) {
            n-=1;
            ans++;
        }
        else {
            n/=2;
        }
    }
    
    return ans;
}
