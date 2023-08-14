function solution(arr, k) {
    var answer = [];
    arr = arr.sort()
    for (let i=0;i<arr.length;i++){
        if (i==0) answer.push(arr[i]);
        else {
            if (arr[i-1] !== arr[i]) answer.push(arr[i]);
        }
    }
    if (answer.length > k) {
        answer = answer.slice(0, k);
    }
    else if (answer.length < k) {
        for (let i=answer.length;i<k;i++){
            answer.push(-1);
        }
    }
    return answer;
}
