// 프로그래머스 스쿨 옹알이 (1)
let possibleList = ["aya", "ye", "woo", "ma"];

function solution(babbling) {
    let answer = 0;
    for (let i=0;i<babbling.length;i++){
        let temp = babbling[i];
        
        for (let j=0;j<possibleList.length;j++){
            if (temp.includes(possibleList[j])){
                temp = temp.replace(possibleList[j]," ");
            }
        }
        temp = temp.replaceAll(" ", "");
        if (temp == "") {
            answer++;
        }
    }
    return answer;
}
