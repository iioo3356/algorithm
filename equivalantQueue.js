function solution(queue1, queue2) {
    var answer = -2;
    let sum_1 = queue1.reduce((a, b) => a+b, 0);
    let sum_2 = queue2.reduce((a, b) => a+b, 0);
    
    if ((sum_1 + sum_2) %2 === 1) return -1;
    
    while (true) {
        if (answer === 4 * queue1.length) {
            answer = -1;
            break;
        }
        if (sum_1 > sum_2){
            const item = queue1.shift();
            queue2.push(item);
            sum_1 -= item;
            sum_2 += item;
        }
        else if (sum_1 < sum_2) {
            const item = queue2.shift();
            queue1.push(item);
            sum_1 += item;
            sum_2 -= item;
        }
        else {
            break;
        }
        answer++;
    }
    return answer;
}
