// 프로그래머스 연속 부분 수열 합의 개수
function solution(elements) {
    var answer = 0;
    const sumSet = new Set();
    for (let i=1;i<=elements.length;i++){            
        let sum = 0;
        for (let j=0;j<elements.length;j++){
            if (j === 0) {
                for (let k=0;k<i;k++) {
                    sum += elements[k];
                }
            }
            else {
                sum -= elements[j-1];
                sum += elements[(j+i-1)%elements.length];
            }
            sumSet.add(sum)
        }
    }
    answer = sumSet.size;
    return answer;
}
