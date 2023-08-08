function solution(my_string, queries) {
    var answer = my_string;
    for (let i=0;i<queries.length;i++){
        const left  = answer.substring(0, queries[i][0]);
        const middle = answer.substring(queries[i][0], queries[i][1]+1);
        const right = answer.substring(queries[i][1]+1);
        const middleReverse = middle.split("").reverse().join("");
        answer = left
            .concat(middleReverse)
            .concat(right);
    }
    return answer;
}
