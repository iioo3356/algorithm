// 프로그래머스 2개 이하로 다른 비트
function makeProperBit(num) {
    let binaryNum = num.toString(2);

    if (num%2 === 0){
        binaryNum = binaryNum.slice(0,binaryNum.length-1) + "1";
    }
    else {
        binaryNum = "0"+binaryNum
        const last0Index = binaryNum.lastIndexOf("0");
        binaryNum = binaryNum.slice(0, last0Index)+"10"+binaryNum.slice(last0Index+2);
    }

    return parseInt(binaryNum,2);
}

function solution(numbers) {
    var answer = [];
    for (let i=0;i<numbers.length;i++){
        answer.push(makeProperBit(numbers[i]));
    }
    return answer;
}
