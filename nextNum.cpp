// 프로그래머스 스쿨 다음에 올 숫자
function solution(common) {
    var answer = 0;
    let amount = common[1] - common[0];
    if (amount === common[2] - common[1]){
        // 등차수열
        answer = common[common.length-1] + amount;
    }
    else {
        answer = common[common.length-1] * ((common[2]-common[1])/amount);
    }
    return answer;
}
