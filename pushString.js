// 프로그래머스 문자열 밀기
function solution(A, B) {
    var answer = 0;
    if (A === B) return 0;
    for (let i=0;i<A.length;i++){
        const temp = A[A.length - 1] + A.slice(0, A.length-1);
        answer++;
        A = temp;
        if (A === B) {
            break;
        }
    }
    if (A !== B) answer = -1;
    return answer;
}
