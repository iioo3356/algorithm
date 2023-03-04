// 프로그래머스 대충 만든 자판
function solution(keymap, targets) {
    var answer = [];
    const minCountDict = {}
    for (let i=0;i<keymap.length;i++){
        for (let j=0;j<keymap[i].length;j++){
            if (minCountDict[keymap[i][j]]) {
                if (minCountDict[keymap[i][j]]>j+1){
                    minCountDict[keymap[i][j]]=j+1;    
                }
            }
            else {             
                minCountDict[keymap[i][j]]=j+1;
            }
        }
    }    
    for (let i=0;i<targets.length;i++){
        let sum = 0;
        for (let j=0;j<targets[i].length;j++){
            if (minCountDict[targets[i][j]]) {
                sum += minCountDict[targets[i][j]];
            }
            else {
                sum = -1;
                break;
            }
        }
        answer.push(sum);
    }
    return answer;
}
