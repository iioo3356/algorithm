// 프로그래머스 달리기 경주
function solution(players, callings) {
    var answer = players;
    const playersIndex = {};
    for (let i=0;i<players.length;i++){
        playersIndex[players[i]] = i;
    }
    for (let i=0;i<callings.length;i++){
        let currentIndex = playersIndex[callings[i]];
        let beforeName = answer[currentIndex-1];
        answer[currentIndex-1] = callings[i];
        answer[currentIndex] = beforeName;
        playersIndex[callings[i]] = currentIndex - 1;
        playersIndex[beforeName] += 1;
    }
    return answer;
}
