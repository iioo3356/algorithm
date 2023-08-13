function solution(arr, queries) {
    var answer = [];
    for (let j=0;j<queries.length;j++){            
        let kOverMin = 10000000;
        for (let i=queries[j][0];i<=queries[j][1];i++){
            if (arr[i] > queries[j][2]){
                kOverMin = kOverMin > arr[i] ? arr[i] : kOverMin; 
            }
        }
        answer.push(kOverMin === 10000000 ? -1 : kOverMin);
    }
    return answer;
}
