// 프로그래머스 무인도 여행
function solution(maps) {
    var answer = [];

    const strMap = maps.map((item)=>item.split(""))
    const dfs = (r, c) => {
        if (r >= strMap.length || r < 0 || c >= strMap[0].length || c < 0) {
            return 0;
        }
        if (strMap[r][c] === "X") return 0
        const food = strMap[r][c];
        strMap[r][c] = "X";
        return parseInt(food) + dfs(r+1, c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1);
    }

    
    for (let r=0;r<strMap.length;r++){
        for (let c=0;c<strMap[r].length;c++){
            if (strMap[r][c] !== "X") 
                answer.push(dfs(r, c))
        }
    }
    if (answer.length === 0) {
        return [-1];
    }
    return answer.sort((a, b)=>a-b);
}
