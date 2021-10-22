#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void max_heap_push(vector<int>& v, int d){
    int i = v.size();
    // cout << i <<"번 index "<< d << " value"<< endl;
    v.push_back(d);
    int parentIdx=0;
    while (i!=0){
        if (i%2 == 0) parentIdx = i/2-1;
        else parentIdx = i/2;
        // cout << "부모 index "<< parentIdx<<endl;
        if (d>v[parentIdx]){
            int temp = v[i];
            v[i] = v[parentIdx];
            v[parentIdx] = temp;
            i = parentIdx;
            // cout << i << " swap " << parentIdx << endl;
        }
        else{
            break;
        }
    }
}

void max_heap_pop(vector<int>& v){
    // int largest = v[0];
    v[0] = v[v.size()-1];
    // cout << v[v.size()-1] <<endl;
    v.pop_back();

        //     for (int j=0;j<v.size();j++){
        //     cout << v[j] <<" ";
        // }

        // cout << endl;

    int i = 0;
    while (true){
        int left = i*2 +1;
        int right = i*2 +2;
        int big;
        if (left>v.size()-1 && right>v.size()-1){
            break;
        }
        (v[left] > v[right])? big=left:big=right;
        // cout << big << endl;
        if (v[i]>v[big]){
            break;
        }
        int temp = v[i];
        v[i] = v[big];
        v[big] = temp;
        i = big;
    }
}


void min_heap_push(vector<int>& v, int d){
    int i = v.size();
    // cout << i <<"번 index "<< d << " value"<< endl;
    v.push_back(d);
    int parentIdx=0;
    while (i!=0){
        if (i%2 == 0) parentIdx = i/2-1;
        else parentIdx = i/2;
        // cout << "부모 index "<< parentIdx<<endl;
        if (d<v[parentIdx]){
            int temp = v[i];
            v[i] = v[parentIdx];
            v[parentIdx] = temp;
            i = parentIdx;
            // cout << i << "swap" << parentIdx << endl;
        }
        else{
            break;
        }
    }
}


void min_heap_pop(vector<int>& v){
    // int largest = v[0];
    v[0] = v[v.size()-1];
    v.pop_back();
    int i = 0;
        while (true){
        int left = i*2 +1;
        int right = i*2 +2;
        int small;
        if (left>v.size()-1 && right>v.size()-1){
            break;
        }
        (v[left] < v[right])? small=left:small=right;
        // cout << big << endl;
        if (v[i]<=v[small]){
            break;
        }
        int temp = v[i];
        v[i] = v[small];
        v[small] = temp;
        i = small;
    }
}


int main(){
    int numTestCase;
    cin >> numTestCase;
    for (int i=0;i<numTestCase;i++){
        int n;
        int median;
        unsigned int sum = 0;
        cin >> n;
        vector<int> max_heap;
        vector<int> min_heap;
        for (int j=0;j<n;j++){
            int num;
            cin >> num;
            if (j==0) {
                median = num;
                max_heap.push_back(num);
            }
            else {
                if (num <= median){
                    max_heap_push(max_heap, num);
                }
                else{
                    min_heap_push(min_heap, num);
                }
                // cout<<"max_heap"<<endl;
                // for (int p=0;p<max_heap.size();p++){
                //     cout << max_heap[p] <<" ";
                // }
                // cout << endl;

                // cout<<"min_heap"<<endl;
                // for (int p=0;p<min_heap.size();p++){
                //     cout << min_heap[p] <<" ";
                // }
                // cout << endl;
                if (max_heap.size()-min_heap.size()==2){
                    // cout << "max에서 min으로 이동 "<<endl;
                    min_heap_push(min_heap, max_heap[0]);
                    max_heap_pop(max_heap);
                }
                if (min_heap.size()-max_heap.size()==2){
                    // cout << "min에서 max으로 이동 "<<endl;
                    max_heap_push(max_heap, min_heap[0]);
                    min_heap_pop(min_heap);
                }

                if (min_heap.size() == max_heap.size()){
                    median = (min_heap[0] + max_heap[0])/2;
                }
                else if (min_heap.size() > max_heap.size()){
                    median = min_heap[0];
                }
                else median = max_heap[0];
            }
            // cout << "median: "<< median << endl;
            sum += median;
        }
        cout << sum%10 << endl;
    
    }
    return 0;
}