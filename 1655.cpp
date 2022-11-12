// boj 1655 가운데를 말해요
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i=0;i<N;i++){
        int num;
        cin >> num;
        if (i==0){
            max_heap.push(num);
        }
        else {
            if (max_heap.size() <= min_heap.size()){
                max_heap.push(num);
            }
            else {
                min_heap.push(num);
            }

            if (max_heap.top() > min_heap.top()){
                int max_top = max_heap.top();
                int min_top = min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(min_top);
                min_heap.push(max_top);
            }
        }
        cout << max_heap.top() << "\n";
    }
    return 0;
}
