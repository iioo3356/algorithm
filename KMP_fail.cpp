#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> getFail(string pattern){
    int m = pattern.size();
    int j= 0;
    vector<int> fail(m, 0);
    for (int i=1;i<m;i++){
        while (j>0 && pattern[i]!=pattern[j])
            j = fail[j-1];
        if (pattern[i] == pattern[j])
            fail[i] = ++j;
        else fail[i] = j;
    }
    return fail;

}
int main(){
    int numTestCases;
    cin >> numTestCases;
    for (int i=0;i<numTestCases;i++){
        string pattern;
        string text;
        cin >> pattern >> text;
        vector<int> fail = getFail(pattern);
        for (int j=0;j<fail.size();j++){
            cout << fail[j] <<" ";
        }
        cout << endl;
        int ans = 0;
        int n = text.size();
        int m = pattern.size();
        int j= 0;
        for (int k=0;k<n;k++){
            while(j>0&& text[k] != pattern[j])
                j = fail[j-1];
            if (text[k] == pattern[j]){
                if (j==m-1){
                    ans += 1;
                    j = fail[j];
                }
                else j++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}