// 프로그래머스 카드 뭉치
function solution(cards1, cards2, goal) {
    var answer = '';
    let index1 = 0, index2 = 0;
    for (let i=0;i<goal.length;i++){
        if (cards1[index1] === goal[i]){
            index1++;
        }
        else if (cards2[index2] === goal[i]){
            index2++;
        }
        else {
            answer = "No";
            break;
        }
    }
    if (answer !== "No"){
        answer = "Yes";
    }
    return answer;
}
