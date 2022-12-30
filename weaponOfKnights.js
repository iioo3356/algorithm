// 프로그래머스 스쿨 기사단원의 무기
function solution(number, limit, power) {
    var answer = 0;
    for (let i=1;i<=number;i++){
        let count = 0;
        for (let j=1;j<=Math.sqrt(i);j++){
            if (i%j===0){
                count++;
                if (i / j !== j) count++;
            }
        }
        if (count > limit) answer+=power;
        else answer += count;
    }
    return answer;
}
