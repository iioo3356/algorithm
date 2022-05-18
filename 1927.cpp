// boj 1927 최소힙
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <stdio.h>
using namespace std;

int main(){
    priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> pq;
    int n;
    unsigned int num;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d", &num);
        if (num == 0){
            if (pq.empty()){
                printf("0\n");
            }
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else {
            pq.push(num);
        }
    }
    return 0;
}
