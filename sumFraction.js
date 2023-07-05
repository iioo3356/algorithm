// 분수의 덧셈
function gcd(num1, num2) {
    if (num2 === 0) return num1;
    else return gcd(num2, num1 % num2)
}
function solution(numer1, denom1, numer2, denom2) {
    var answer = [];
    let gcdNum = gcd(Math.max(denom1, denom2), Math.min(denom1, denom2));
    numer1 *= denom2 / gcdNum;
    numer2 *= denom1 / gcdNum;
    answer = [numer1 + numer2, denom1*denom2/gcdNum];
    gcdNum = gcd(Math.max(answer[0], answer[1]), Math.min(answer[0], answer[1]));
    answer[0] /= gcdNum;
    answer[1] /= gcdNum;
    return answer;
}
