function solution(score) {
    var answer = [];
    const rank = {}
    const rankScore = new Array(...score).sort((a, b)=> (b[0]+b[1])/2 - (a[0]+a[1])/2);
    for (let i=0;i<rankScore.length;i++){
        rank[rankScore[i]] = i+1;
    }
    for (let i=0;i<score.length;i++){
        answer.push(rank[score[i]]);
    }
    return answer;
}
