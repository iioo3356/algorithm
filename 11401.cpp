// boj 11401  이항 계수 3
#include <iostream>
#include <cmath>
using namespace std;

unsigned long long MOD = 1000000007;

unsigned long long power(unsigned long long x, unsigned long long y) {
	unsigned long long answer = 1;
	x %= MOD;
	while (y) {
		if (y & 1) answer = (answer * x) % MOD;
		y /= 2;
		x = (x * x) % MOD;
	}
	return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long N, K;
    cin >> N >> K;

    // C(N, K)%MOD
    //  = ((N!/(N-K)!)/K!)%MOD 
    //  = ((N!/(N-K)!)%MOD) * ((K!^-1)%MOD) (모듈러 연산은 나눗셈에서 분배 법칙 불가)
    // MOD 가 소수이므로 서로소 관계가 성립되어 페르마의 소정리 사용 가능
    // => ((K!)^(MOD-1)) = 1 (mod MOD)
    //  ((N!/(N-K)!)%MOD) * ((K!^-1)%MOD) 
    //  = ((N!/(N-K)!)%MOD) * ((K!^-1*K!^(MOD-1))%MOD)
    //  = ((N!/(N-K)!)%MOD) * ((K!^(MOD-2))%MOD)
    // 구해야 하는 값: N!/(N-K)! ,  K!

    unsigned long long a = 1;
    for (unsigned long long i=N-K+1;i<=N;i++){
        a = (a * i) % MOD;
    }

    unsigned long long b=1;
    for (unsigned long long i=1;i<=K;i++){
        b = (b * i) % MOD;
    }

    unsigned long long answer;
    answer =  (a * power(b, MOD-2)) % MOD;
    
    cout << answer << "\n";
    return 0;
}
