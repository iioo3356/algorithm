// 프로그래머스 평행
function solution(dots) {
    var answer = 0;
    const arr = [];
    for (let i=0;i<dots.length;i++){
        for (let j=i+1;j<dots.length;j++){
            const a = (dots[j][1] - dots[i][1])/(dots[j][0] - dots[i][0]);
            if (arr.includes(a)){
                answer = 1;
                break;
            }
            arr.push(a);
        }
    }
    return answer;
}
