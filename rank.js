// 프로그래머스 등수 매기기
function solution(score) {
    var answer = [];
    const rank = {}
    const averageScore = score.map((item)=>((item[0]+item[1])/2)).sort((a,b)=>b-a);
    let current = 1;
    for (let i=0;i<averageScore.length;i++){
        if (!rank[averageScore[i]]){
            rank[averageScore[i]] = current;        
        }            
        current++;

    }
    for (let i=0;i<score.length;i++){
        const average = (score[i][0]+score[i][1])/2;
        answer.push(rank[average]);
    }
    return answer;
}
