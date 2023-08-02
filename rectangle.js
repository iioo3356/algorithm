// 프로그래머스 직사각형 넓이 구하기
function solution(dots) {
    var answer = 0;
    dots.sort((a, b)=>{
        if (a[0]-b[0] === 0)
            return a[1] - b[1];
        return a[0]-b[0];
    });
    answer = Math.abs(dots[1][0] - dots[2][0]) * Math.abs(dots[1][1] - dots[2][1]);
    return answer;
}
