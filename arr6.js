// 프로그래머스 배열 만들기 6
function solution(arr) {
    let stk = [];
    for (let i=0;i<arr.length;i++){
        if (stk.length === 0){
            stk.push(arr[i])
        }
        else {
            if (stk[stk.length-1] === arr[i]){
                stk.pop();
            } 
            else {
                stk.push(arr[i]);
            }
        }
    }
    if (stk.length === 0) return [-1]
    return stk;
}
