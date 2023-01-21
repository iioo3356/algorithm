// 프로그래머스 콜라 문제
let coke = 0;
function refund(a, b, n) {
    if (n<a){
        return coke;
    }
    else {
        coke += Math.floor(n/a)*b;
        return refund(a, b, Math.floor(n/a)*b+n%a)
    }
}
function solution(a, b, n) {
    let answer = refund(a, b, n);
    return answer;
}
