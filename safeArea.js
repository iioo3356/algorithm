// 프로그래머스 안전지대
function solution(board) {
    var answer = 0;
    const dr = [0,1,1,0,-1,-1,1,-1];
    const dc = [1,1,0,-1,-1,0,-1,1];
    
    const bomb = [];
    for (let r=0;r<board.length;r++){
        for (let c=0;c<board[r].length;c++){
            if (board[r][c] === 1) bomb.push([r,c]) ;
        }
    }
    
    for (let i=0;i<bomb.length;i++){
        for (let j=0;j<8;j++){
            const nr = bomb[i][0] + dr[j];
            const nc = bomb[i][1] + dc[j];
            if (nr <  board.length && nr >=0 && nc < board.length && nc >=0){
                board[nr][nc] = 1;
            }
        }
    }
    
    for (let i=0;i<board.length;i++){
        for (let j=0;j<board.length;j++){
            if (board[i][j] === 0) answer++;
        }
    }
    return answer;
}
