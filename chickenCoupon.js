// 프로그래머스 치킨 쿠폰
function solution(chicken) {
    var answer = 0;
    while (chicken >= 10) {
        answer += Math.floor(chicken / 10);
        chicken = Math.floor(chicken / 10) + chicken % 10;
    }
    return answer;
}
