// 프로그래머스 스쿨 2차원으로 만들기
function solution(num_list, n) {
    var answer = [];
    for (let i=0;i<num_list.length;i++){
        if (i%n==0){
            answer.push([num_list[i]]);
        }
        else {
            answer[answer.length-1].push(num_list[i]);
        }
    }
    return answer;
}
