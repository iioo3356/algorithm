// 프로그래머스 두 큐 합 같게 만들기
function solution(queue1, queue2) {
    var answer = 0;
    let n = queue1.length;
    
    let sum_1 = queue1.reduce((a, b) => a+b, 0);
    let sum_2 = queue2.reduce((a, b) => a+b, 0);
    
    let start_1 = 0;
    let start_2 = 0;
    
    if ((sum_1 + sum_2) %2 === 1) return -1;
    
    while (true) {
        if (answer === 4 * n) {
            return -1;
        }
        if (sum_1 > sum_2){
            const item =queue1[start_1];
            queue2.push(item);
            start_1 += 1;
            sum_1 -= item;
            sum_2 += item;
        }
        else if (sum_1 < sum_2) {
            const item = queue2[start_2];            
            queue1.push(item);
            start_2 += 1;
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
