//  프로그래머스 짝지어 제거하기 js
class Stack {
    constructor() {
        this._arr = [];
    }
    push(item) {
        this._arr.push(item);
    }
    pop() {
        return this._arr.pop();
    }
    top() {
        return this._arr[this._arr.length-1];
    }
    empty() {
        return this._arr.length === 0;
    }
}

function solution(s) {
    var answer = -1;
    const st = new Stack();
    st.push(s[0]);
    for (let i=1;i<s.length;i++){
        if (st.empty()) st.push(s[i]);
        else if (st.top() == s[i]){
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    if (st.empty()) answer = 1;
    else answer = 0;
    return answer;
}
