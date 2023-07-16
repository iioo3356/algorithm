// 프로그래머스 정수를 나선형으로 배치하기
function solution(n) {
    var answer = new Array();
    const dx = [1,0,-1,0];
    const dy = [0,1,0,-1];
    let idx = 0, cx=0,cy=0;
    for (let i=0;i<n;i++){
        let arr = [];
        for (let j=0;j<n;j++){
            arr.push(0);
        }
        answer.push(arr);
    }
    
    for (let i=1;i<=n*n;i++){
        answer[cy][cx] = i;        
        cx += dx[idx];
        cy += dy[idx]; 
        if ((idx === 2 && cx === 0) || 
             (idx === 0 && cx=== n-1) || 
             (idx === 3 && cy === 0) || 
             (idx === 1 && cy === n-1) ||
            answer[cy+dy[idx]][cx+dx[idx]] !== 0){
            idx = (idx + 1)%4;
        }    
    
    }
    return answer;
}
