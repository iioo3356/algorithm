// 프로그래머스 캐릭터의 좌표
function solution(keyinput, board) {
    var answer = [0,0];
    for (let i=0;i<keyinput.length;i++){
        let nx = answer[0];
        let ny = answer[1];
        if (keyinput[i] === "up") ny += 1;
        else if (keyinput[i] === "left") nx -= 1;
        else if (keyinput[i] === "right") nx += 1;
        else ny -= 1;
        
        if (nx >= -1 * board[0]/2 && nx <= board[0]/2 && ny >= -1 * board[1]/2 && ny <= board[1]/2){
            answer = [nx, ny];
        }
    }
    return answer;
}
