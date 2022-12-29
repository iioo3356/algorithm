// 프로그래머스 스쿨 OX 퀴즈
function solution(quiz) {
    var answer = [];
    for (let i=0;i<quiz.length;i++){
        let temp = quiz[i].split("=");
        let rightA = eval(temp[0]);
        if (rightA === parseInt(temp[1])) {
            answer.push("O");
        }
        else answer.push("X");
    }
    return answer;
}
