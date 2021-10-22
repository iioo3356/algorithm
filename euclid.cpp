#include <iostream>
using namespace std;
int euclid(int a, int b){
    if (b==0){
        return a;
    }
    else {
        return euclid(b, a % b);
    }
}

int main(){
    int numTestCase;
    cin >> numTestCase;
    for (int i=0;i<numTestCase;i++){
        int m, n;
        cin >> m >> n;
        int answer = euclid(m, n);
        cout << answer << endl;
    }
    return 0;
}