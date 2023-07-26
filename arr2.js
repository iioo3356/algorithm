function solution(l, r) {
    const answer = [];
    for (let i=l;i<=r;i++) {
        if (i%5 !== 0) continue;
        const iStr = i.toString();
        if ([...iStr].every(a => a === '5' || a === '0')) 
            answer.push(i)
    }
    if (answer.length === 0) 
        answer.push(-1);
    return answer;
}
