function solution(numbers) {
    var answer = [];
    let s = new Set();
    for (let i=0;i<numbers.length-1;i++){
        for (let j=i+1;j<numbers.length;j++){
            s.add(numbers[i] + numbers[j]);
        }
    }
    answer = [...s];
    answer.sort((a,b)=>a-b)
    return answer;
}
