// 프로그래머스 숫자 짝꿍
function solution(X, Y) {
    var answer = '';
    const strX = X.toString();
    const strY = Y.toString();
    let dictX = [0,0,0,0,0,0,0,0,0,0];
    let dictY = [0,0,0,0,0,0,0,0,0,0];
    for (let i=0;i<strX.length;i++){
        dictX[parseInt(strX[i])] += 1;
    }
    for (let i=0;i<strY.length;i++){
        dictY[parseInt(strY[i])] += 1;
    }
    for (let i=9;i>=0;i--){
        if (dictX[i] && dictY[i]){
            for (let j=0;j<Math.min(dictX[i], dictY[i]);j++)
                answer += i.toString();
        }
    }
    if (answer === "") answer = "-1"
    else if (answer.replaceAll("0","") === "") answer = "0";
    return answer;
}
