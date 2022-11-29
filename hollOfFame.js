// 프로그래머스 스쿨 명예의 전당
function solution(k, score) {
    let answer = [];
    let hof = [];
    for (let i=0;i<score.length;i++){
        hof.sort((a,b)=>b-a);
        if (i < k){
            hof.push(score[i]);
        }
        else {
            if (score[i] > hof[k-1]){
                hof[k-1] = score[i];
            }
        }
        hof.sort((a,b)=>b-a);
        answer.push(hof[hof.length-1]);
    }
    return answer;
}
