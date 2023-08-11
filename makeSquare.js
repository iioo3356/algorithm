function solution(arr) {
    var answer = arr;
    const diff = answer.length - answer[0].length;
    if (diff>0){
        for (let i=0;i<answer.length;i++){
            for (let j=0;j<diff;j++)
                answer[i].push(0);
        }
    }
    else if (diff<0){
        for (let i=0;i<diff*-1;i++){
            answer.push(new Array(answer[0].length).fill(0));
        }
    }
    return answer;
}
