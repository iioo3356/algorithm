// 프로그래머스 연속된 수의 합
function solution(num, total) {
    var answer = [];
    for (let i=Math.ceil(total/num) - Math.floor(num/2);i<Math.ceil(total/num) + Math.ceil(num/2);i++){
            answer.push(i);
    }
    return answer;
}
