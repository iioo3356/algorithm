// 프로그래머스 추억 점수
function solution(name, yearning, photo) {
    var answer = [];
    const yearningDict = {};
    for (let i=0;i<name.length;i++){
        yearningDict[name[i]] = yearning[i];
    }
    
    for (let i=0;i<photo.length;i++){
        let sumYearning = 0;
        for (let j=0;j<photo[i].length;j++){
            if (yearningDict[photo[i][j]])
                sumYearning += yearningDict[photo[i][j]];
        }
        answer.push(sumYearning);
    }
    return answer;
}
