// 프로그래머스 그림 확대
function solution(picture, k) {
    var answer = [];
    for (let i=0;i<picture.length;i++){
        let current = "";
        for (let j=0;j<picture[i].length;j++){
            current += picture[i][j].repeat(k);
        }
        answer.push(...Array(k).fill(current))
    }
    return answer;
}
