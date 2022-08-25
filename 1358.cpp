//boj 1358 하키
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w,h,x,y,p;
    cin >> w >> h >> x >> y >>p;
    int arr[p];
    int answer = 0;
    for (int i=0;i<p;i++) {
        int px, py;
        cin >> px >> py;
        if (x<=px && px<=x+w){
            if (y<=py && py<=y+h) answer++;
        }
        else if (px<x) {
            if ((px-x)*(px-x) + (py-(y+h/2))*(py-(y+h/2)) <= (h/2)*(h/2)) answer++;
        }
        else {
            if ((px-(x+w))*(px-(x+w)) + (py-(y+h/2))*(py-(y+h/2)) <= (h/2)*(h/2)) answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}
