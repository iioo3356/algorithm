// 프로그래머스 외계어 사전
function solution(spell, dic) {
    var answer = 0;
    for (let i=0;i<dic.length;i++){
        const countSpell = {};
        for (let j=0;j<dic[i].length;j++){
            if (countSpell[dic[i][j]]){
                countSpell[dic[i][j]]++;
            }
            else {
                countSpell[dic[i][j]] = 1;
            }
        }
   
        if (Object.keys(countSpell).sort().join("") === spell.sort().join("")) {
            let isOk = true
            for (let j=0;j<spell.length;j++){
                if (countSpell[spell[j]] !== 1) {
                    isOk = false;
                    break;
                }
            }
            if (isOk) {
                answer = 1;
                break;
            }
        }
    }
    if (answer !== 1) answer = 2;
    return answer;
}
