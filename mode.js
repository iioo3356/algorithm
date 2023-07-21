// 프로그래머스 최빈값 구하기
function solution(array) {
    var answer = -1;
    let arr = [];
    for (let i=0;i<1001;i++){
        arr.push([i, 0]);
    }
    for (let i=0;i<array.length;i++){
        arr[array[i]][1]++;
    }
    arr.sort((a, b)=>b[1]-a[1])
    if (arr[0][1] !== arr[1][1]) answer = arr[0][0];
    return answer;
}
