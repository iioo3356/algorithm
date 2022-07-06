//boj 11866 요세푸스 문제 0
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> peopleInCircle;
    vector<int> peopleOutCircle;
    for (int i=1;i<=n;i++){
        peopleInCircle.push_back(i);
    }
    int currentIdx = 0;
    while (!peopleInCircle.empty()){
        currentIdx = (currentIdx + k - 1) % n; // 원으로 둘러서 있음 + 1명씩 빠짐
        peopleOutCircle.push_back(peopleInCircle[currentIdx]);
        peopleInCircle.erase(peopleInCircle.begin() + currentIdx);
        n -= 1;
    }
    cout << "<";
    for (int i=0;i<peopleOutCircle.size();i++){
        cout << peopleOutCircle[i];
        if (i < peopleOutCircle.size()-1) cout << ", ";
    }
    cout << ">";

    return 0;
}
