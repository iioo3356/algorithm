#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void move_plate(int n, unsigned long long int k, int a, int b, int c){
    int numPlate = -1;
    bitset<64> bs(k);
    // cout << "binary: "<< bs<<endl;
    for (int i=1;i<=bs.size();i++){
        if (bs.test(i-1)){
            numPlate = i;
            break;
        }
    }
    bs >>= numPlate;
    // cout << numPlate << "가 이동한 횟수: "<< bs.to_ullong()<<endl;
    unsigned long long int moveCount =  bs.to_ullong();

    if ((n%2 == 0 && numPlate%2==0)||(n%2==1)&&(numPlate%2==1)){
        if (moveCount%3 ==0){
            cout << a << " " << c << endl;
        }
        else if (moveCount%3==1){
            cout << c << " " << b << endl;
        }
        else{
            cout << b << " " << a << endl;
        }
    }
    else{
        if (moveCount%3 ==0){
            cout << a << " " << b << endl;
        }
        else if (moveCount%3==1){
            cout << b << " " << c << endl;
        }
        else{
            cout << c << " " << a << endl;
        }
    }

}

// void hanoi_tower(int n, int a, int b, int c, unsigned long long & move, unsigned long long int k){
//     if (n > 0){
//         hanoi_tower(n-1, a, c, b, move, k);
//         move += 1;
//         // if (move == k){
//             cout <<move<<"번 시행 "<<move_plate(move)<<": " << a << " -> " << c << endl;
//             // return;
//         // }
//         // cout << move<<" " << a << " -> " << c << endl;
//         hanoi_tower(n-1, b, a, c, move, k);
//     }
// }


int main(){
    int numTestCase;
    cin >> numTestCase;
    for (int i=0;i<numTestCase;i++){
        int n;
        unsigned long long int k;
        unsigned long long int move = 0;
        cin >> n >> k;
        int num_disks = n;
        // hanoi_tower(num_disks, 1, 2, 3, move, k);

        move_plate(n, k,1,2,3);
    }
    return 0;
}