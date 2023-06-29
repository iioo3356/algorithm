// 프로그래머스 다항식 더하기 
function solution(polynomial) {
    var answer = '';
    const arr = polynomial.split(" ");

    let one = 0;
    let zero = 0;
    for (let i=0;i<arr.length;i++){
        if (arr[i][arr[i].length-1] === "x") {
            if (arr[i].length === 1) one++;
            else one += parseInt(arr[i].split("x")[0]);
        }
        else if (arr[i] !== "+"){
            zero += parseInt(arr[i]);
        }
    }
    if (one > 0 && zero > 0)
        answer = `${one === 1 ? "": one}x + ${zero}`;
    else if (one > 0)
        answer = `${one === 1 ? "": one}x`;
    else answer = zero.toString();
    return answer;
}
