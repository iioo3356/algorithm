// 프로그래머스 스쿨 크기가 작은 부분 문자열
function solution(t, p) {
    var answer = 0;
    let ss = "";
    for (let i=0;i<t.length;i++){
        ss += t[i];
        if (ss.length < p.length){
            continue;
        }
        else {
            if (Number(ss)<=Number(p)) answer++;
            ss = ss.substring(1);
        }
    }
    return answer;
}
