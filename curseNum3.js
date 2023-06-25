// 프로그래머스 저주의 숫자 3
function solution(n) {
    var answer = 0;
    let arr = [];
    for (let i=0;i<n;i++){
        answer++;
        while (answer.toString().includes('3') || answer%3 === 0) {
            answer++;
        }
        arr.push(answer)
    }
    return answer;
}
