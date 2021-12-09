#include <iostream>
#include <string>
#include <vector>
using namespace std;
int patLength;
int DFA[3][1001];
int R = 3;

void constructDFA(string pattern){
    patLength = pattern.size();
    for (int i=0;i<3;i++){
        for (int j=0;j<patLength+1;j++){
            DFA[i][j] = 0;
        }
    }
    DFA[int(pattern[0])-65][0] = 1;
    for (int X=0, j=1;j<patLength+1;j++){
        for (int c=0;c<R;c++){
            DFA[c][j] = DFA[c][X];
        }
        if (j < patLength){
            X = DFA[int(pattern[j])-65][X];
            DFA[int(pattern[j])-65][j] = j+1;
        }
    }
}
int DFAmatching(string text){
    int i, j, txtLength;
    int ans = 0;
    j = 0;
    txtLength = text.size();
    for (i=0; i<txtLength && j<=patLength;i++){
        j = DFA[int(text[i])-65][j];
        if (j==patLength){
            ans += 1;
        }

    }
    return ans;
}

int main(){
    int numTestCases;
    cin >> numTestCases;
    for (int test=0;test<numTestCases;test++){
        string text, pattern;
        cin >> pattern >> text;
        patLength = pattern.size();
        constructDFA(pattern);
        int non_zero = 0;
        for (int i=0;i<3;i++){
            for (int j=0;j<patLength+1;j++){
                if (DFA[i][j]!=0) non_zero+=1;
            }
        }
        cout << non_zero << " " << DFAmatching(text) << endl;
    }
    return 0;
}