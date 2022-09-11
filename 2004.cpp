//boj 2004 조합 0의 개수
#include <iostream>
using namespace std;

int num_count(long long n, int number) {
    long long count = 0;
    while (n>=number){
        count += n/number;
        n /= number;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, m;
    cin >> n >> m;
    long long five_num = num_count(n, 5) - num_count(n-m, 5) - num_count(m, 5);
    long long two_num = num_count(n, 2) - num_count(n-m, 2) - num_count(m, 2);
    cout << min(five_num, two_num);
    return 0;
}
