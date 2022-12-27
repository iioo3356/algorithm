// 프로그래머스 스쿨 가장 가까운 같은 글자
function solution(s) {
    var answer = [];
    let cDict = {};
    for (let i=0;i<s.length;i++){
        if (s[i] in cDict){
            answer.push(i-cDict[s[i]]);
        }
        else {
            answer.push(-1);
        }
        cDict[s[i]] = i;
    }
    return answer;
}
