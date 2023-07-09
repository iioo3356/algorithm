// 프로그래머스 주사위 게임 3
function solution(a, b, c, d) {
    var answer = 0;
    let count = [0,0,0,0,0,0,0];
    let countDict = {};
    count[a]++;
    count[b]++;
    count[c]++;
    count[d]++;
    
    for (let i=0;i<count.length;i++){
        if (count[i] > 0) {
            if (countDict[count[i]]) {
                countDict[count[i]].push(i);
            }
            else {
                countDict[count[i]] = [i];
            }
        }
    }

    if (countDict[4]){
        answer = countDict[4][0] * 1111;
    }
    else if (countDict[3]){
        answer = countDict[3][0] * 10 + countDict[1][0];
        answer *= answer;
    }
    else if (countDict[2]){
        if (countDict[2].length === 2){
            answer = countDict[2][0] + countDict[2][1];
            answer *= Math.abs(countDict[2][0] - countDict[2][1]);
        }
        else {
            answer = countDict[1][0] * countDict[1][1];
        }
    }
    else {
        answer = Math.min(...countDict[1]);
    }
    return answer;
}
