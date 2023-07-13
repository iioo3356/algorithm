// 프로그래머스 택배상자
function solution(order) {
    var answer = 0;
    let sub = [];
    
    for (let i=0;i<order.length;i++){
        sub.push(i+1);
        while (sub.length > 0 && sub[sub.length-1] === order[answer]){     
            answer++;
            sub.pop();
        }
        
    }
    return answer;
}
