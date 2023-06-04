// 프로그래머스 숫자 변환하기
function solution(x, y, n) {
    var answer = 0;
    let arr = [];
    for (let i=0;i<=y;i++){
        arr.push(Infinity);
    }
    arr[x] = 0;
    for (let i=x+1;i<=y;i++){
        if (i-n>=x){
            arr[i] = Math.min(arr[i], arr[i-n]+1);
        }
        if (i%2===0 && i/2>=x){
            arr[i] = Math.min(arr[i], arr[i/2]+1);
        }        
        if (i%3===0 &&i/3>=x){
            arr[i] = Math.min(arr[i], arr[i/3]+1);
        }
    }
    answer = arr[y] === Infinity ? -1 : arr[y];
    return answer;
}
