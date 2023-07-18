// 프로그래머스 연속된 부분 수열의 합
function solution(sequence, k) {
    var answer = [];
    let left=0, right=-1, sum=0;
    
    while (true) {
        if (sum < k) {
            right++;
            if (right === sequence.length) 
                break;
            sum += sequence[right];
        }
        else {
            sum -= sequence[left]
            if (left === sequence.length)
                break;
            left++;
        }
        if (sum === k){
            if (answer.length === 0) {
                answer.push(left);
                answer.push(right);
            }
            if (answer[1] - answer[0] > right - left || answer[0] > left){
                answer[0] = left;
                answer[1] = right;
            }
        }
    }
    return answer;
}
