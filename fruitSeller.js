// 프로그래머스 과일 장수
function solution(k, m, score) {
    var answer = 0;
    score.sort((a,b)=>b-a);
    for (let i=0;i<score.length;i++){
        if ((i+1)%m === 0) 
            answer += score[i]*m;
    }
    return answer;
}
