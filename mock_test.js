// 프로그래머스 스쿨 모의고사
function solution(answers) {
    var ans = [];
    let scores = [[1,0],[2,0],[3,0]];
    let first = "12345";
    let second = "21232425";
    let third = "3311224455";
    while (true) {
        first += "12345";
        if (first.length > answers.length) break;
    }
    while (true) {
        second += "21232425";
        if (second.length > answers.length) break;
    }
    while (true) {
        third += "3311224455";
        if (third.length > answers.length) break;
    }
    for (let i=0;i<answers.length;i++){
        if (answers[i] == first[i]) scores[0][1]++;
        if (answers[i] == second[i]) scores[1][1]++;
        if (answers[i] == third[i]) scores[2][1]++;
    }
    scores.sort((a,b)=>b[1]-a[1]);
    ans.push(scores[0][0]);  
    if (scores[0][1] == scores[1][1]) {
        ans.push(scores[1][0]);
        if (scores[1][1] == scores[2][1]) {
            ans.push(scores[2][0]);
        }
    }
    ans.sort((a,b)=> a-b);
    return ans;
}
