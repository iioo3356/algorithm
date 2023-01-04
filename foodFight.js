// 프로그래머스 스쿨 푸드 파이트 대회
function solution(food) {
    var answer = "";
    let leftStr = "";
    for (let i=1;i<food.length;i++){
        for (let j=1;j<=food[i]/2;j++){
            leftStr += i.toString();
        }
    }
    let rightStr = leftStr.split("").reverse().join("");
    answer = leftStr+"0"+rightStr
    return answer;
}
