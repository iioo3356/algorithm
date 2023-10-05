// 프로그래머스 정수 삼각형
function solution(triangle) {
    var answer = 0;
    for (let i=1;i<triangle.length;i++){
        for (let j=0;j<i+1;j++){
            if (j===0){
                triangle[i][j] += triangle[i-1][j];
            }
            else if (j===triangle[i].length-1){
                triangle[i][j] += triangle[i-1][j-1];
            }
            else {
                triangle[i][j] += Math.max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }
    answer = Math.max(...triangle.flat());
    return answer;
}
