// 프로그래머스 스쿨 옹알이(2)
function solution(babbling) {
    var answer = 0;
    const possibleList = ["aya", "ye", "woo", "ma"];

    for (let i=0;i<babbling.length;i++){
        if (babbling[i].includes("ayaaya") || babbling[i].includes("yeye") || babbling[i].includes("woowoo") || babbling[i].includes("mama")){
            continue;
        }
        else {
            for (let j=0;j<possibleList.length;j++){
               if (babbling[i].includes(possibleList[j])){
                   babbling[i] = babbling[i].replaceAll(possibleList[j]," ");
               }
            }
            babbling[i] = babbling[i].replaceAll(" ", "");
            if (babbling[i] == "") {
                answer++;
            }
        }
    }
    return answer;
}
