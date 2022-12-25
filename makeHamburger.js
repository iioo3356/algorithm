// 프로그래머스 스쿨 햄버거 만들기
function solution(ingredient) {
    var answer = 0;
    let temp = []
    for (let i=0;i<ingredient.length;i++){
        temp.push(ingredient[i]);
        if (temp.length >= 4) {
            if (temp.slice(-4).join("") === "1231"){
                temp.pop();
                temp.pop();
                temp.pop();
                temp.pop();
                answer++;
            }
        
        }
    }
    return answer;
    
}
