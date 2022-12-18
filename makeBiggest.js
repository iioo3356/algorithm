// 프로그래머스 최댓값 만들기
function solution(numbers) {
let answer = -9999999999;
   for (let i=0;i<numbers.length-1;i++){
        for (let j=i+1;j<numbers.length;j++){
            answer = Math.max(answer, numbers[i]*numbers[j]);
        }
    }
    return answer;
}
