// 프로그래머스 뒤에 있는 큰 수 찾기
function solution(numbers) {
    const answer = Array.from({length: numbers.length}, ()=>-1);
    const stack = [];
    for (let i=0;i<numbers.length;i++){            
       while (stack.length && numbers[stack[stack.length-1]] < numbers[i]) {
           answer[stack.pop()] = numbers[i];
       }
       stack.push(i);
    }
    return answer;
}
