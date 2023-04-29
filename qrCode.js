// 프로그래머스 qr code
function solution(q, r, code) {
    var answer = '';
    for (let i=0;i<code.length;i++){
        if (i%q===r){
            answer += code[i];
        }
    }
    return answer;
}
