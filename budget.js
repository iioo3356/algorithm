function solution(d, budget) {
    var answer = 0;
    d.sort((a, b) => a-b);
    d.map((num)=>{
        if (num <= budget){
            budget -= num;
            answer += 1;
        }
    })
    return answer;
}
