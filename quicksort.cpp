#include <iostream>
#include <vector>
using namespace std;

int lomuto_swap = 0;
int hoare_swap = 0;
int lomuto_comp = 0;
int hoare_comp = 0;


int partition_Hoare(vector<int> &A, int low, int high){
    int pivot = A[low];
    int i = low-1;
    int j = high+1;
    while (true)
    {
        do
        {
            i++;
            hoare_comp++;
        } while (A[i]<pivot);
        do
        {
            j--;
            hoare_comp++;
        } while (A[j]>pivot);
        if (i<j){
            hoare_swap++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        else{
            return j;
        }
    }
}

int partition_Lomuto(vector<int> &A, int low, int high){
    int pivot = A[low];
    int j = low;
    for (int i=low+1; i<=high; i++){
        lomuto_comp++;
        if (A[i]<pivot){
            j++;
            lomuto_swap++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int pivot_pos = j;
    lomuto_swap++;
    int temp = A[pivot_pos];
    A[pivot_pos] = A[low];
    A[low] = temp;
    return pivot_pos;
} 


void quicksort_hoare(vector<int> &A, int low, int high) {
    if (low >= high){
        return;
    }
    int p = partition_Hoare(A, low, high);
    
    quicksort_hoare(A,low, p);
    quicksort_hoare(A, p+1, high);
}


void quicksort_lomuto(vector<int> &A, int low, int high) {
    if (low >= high){
        return;
    }
    int p = partition_Lomuto(A, low, high);
    quicksort_lomuto(A,low, p-1);
    quicksort_lomuto(A, p+1, high);
}


int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int l, num;
        vector<int> A;
        vector<int> B;
        cin >> l;
        for (int j=0;j<l;j++){
            cin >> num;
            A.push_back(num);
            // B.push_back(num);
        }
        B = A;
        lomuto_swap = 0;
        lomuto_comp = 0;
        hoare_comp = 0;
        hoare_swap = 0;
        quicksort_hoare(A, 0, A.size()-1);
        quicksort_lomuto(B,0, B.size()-1);

        // for (int i=0;i<A.size();i++){
        //     cout << A[i] << " " ;
        // }
        // cout << endl;


        // for (int i=0;i<A.size();i++){
        //     cout << B[i] << " " ;
        // }
        // cout << endl;


        cout << hoare_swap <<" "<< lomuto_swap<<" "<<hoare_comp<<" "<<lomuto_comp<<endl;

    }
    return 0;
}