// 프로그래머스 겹치는 선분의 길이
function solution(lines) {
    var answer = 0;
    const xSum = {};
    for (let i=0;i<lines.length;i++){
        for (let j=lines[i][0];j<lines[i][1];j++){
            if (xSum[`(${j},${j+1})`]) xSum[`(${j},${j+1})`]+=1;
            else xSum[`(${j},${j+1})`] = 1;
        }
    }
    const xSumValues = Object.values(xSum);
    for (let i=0;i<xSumValues.length;i++){
        if (xSumValues[i] >=2) answer++;
    }
    return answer;
}
