function solution(k, tangerine) {
    // 각 종류별로 개수를 세서 박스에 담을 수 있는 가장 큰 거를 계속 담고 종류를 카운트

    var answer = 0;
    const sizeDict = {};
    
    // 귤 크기 별로 개수 세기
    for (let i=0;i<tangerine.length;i++){
        if (sizeDict[tangerine[i]]){
            sizeDict[tangerine[i]]++;
        }
        else {
            sizeDict[tangerine[i]] = 1;
        }
    }
    
    // 개수가 많은 순으로 정렬
    const sortedSizeDict = Object.keys(sizeDict)
    .map((key)=>[key, sizeDict[key]])
    .sort((a,b)=>b[1]-a[1]);

    // 박스에 담을 수 있는 같은 종류의 개수를 많은 것부터 계속해서 고름
    let idx = 0;
    while (k>0 && idx<sortedSizeDict.length){
        answer++;
        k -= sortedSizeDict[idx][1];
        idx++;
    }
    
    
    return answer;
}
