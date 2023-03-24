// 프로그래머스 공원 산책
function solution(park, routes) {
    var answer;
    let currentR, currentC;
    for (let i=0;i<park.length;i++){
        for (let j=0;j<park[i].length;j++){
            if (park[i][j] === 'S'){
                currentR = i;
                currentC = j;
            }
        }
    }
    for (let i=0;i<routes.length;i++){
        const routeSplit = routes[i].split(" ");
        let diffR = 0, diffC = 0;
        if (routeSplit[0] === "N")
            diffR = -parseInt(routeSplit[1]);
        else if (routeSplit[0] === "S")
            diffR = parseInt(routeSplit[1]);
        else if (routeSplit[0] === "W")
            diffC = -parseInt(routeSplit[1]);
        else diffC = parseInt(routeSplit[1]);
        if (currentR + diffR >= park.length || currentR + diffR < 0 || currentC + diffC >= park[0].length || currentC + diffC < 0){
            continue;
        }
        else {
            let isPossible = true;
            if (diffR > 0 || diffC > 0)
                for (let r=currentR;r<=currentR+diffR;r++){
                    for (let c=currentC;c<=currentC+diffC;c++){
                        if (park[r][c] === "X"){
                            isPossible = false;
                            break;
                        }
                    }
                }
            else 
                for (let r=currentR;r>=currentR+diffR;r--){
                    for (let c=currentC;c>=currentC+diffC;c--){
                        if (park[r][c] === "X"){
                            isPossible = false;
                            break;
                        }
                    }
                } 
            if (isPossible) {
                currentR += diffR;
                currentC += diffC;
            }
            else continue;
        }
    }
    answer = [currentR, currentC];
    return answer;
}

