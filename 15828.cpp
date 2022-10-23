//boj 15828 Router
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int> router;
    int N;
    cin >> N;

    int X;
    while (true) {
        cin >> X;
        if (X == -1){
            break;
        }
        
        if (X>0){
            if (router.size() < N)
                router.push(X);
            continue;
        }

        if (X==0){
            router.pop();
        }
    }
    if (router.empty()) cout << "empty";
    while (!router.empty()){
        cout << router.front() << " ";
        router.pop();
    }
    return 0;
}
