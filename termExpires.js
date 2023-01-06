// 프로그래머스 스쿨 카카오 블라인드 - 개인정보 수집 유효기간 
function solution(today, terms, privacies) {
    var answer = [];
    const termDict = {};
    const todayDate = today.split(".").map((item)=>parseInt(item));
    const todayNum = todayDate[0]*28*12 + todayDate[1]*28 + todayDate[2];

    for (let i=0;i<terms.length;i++){
        const termSplit = terms[i].split(" ");
        termDict[termSplit[0]] = parseInt(termSplit[1]);
    }
    for (let i=0;i<privacies.length;i++){
        const privacySplit = privacies[i].split(" ");
        const registerDate = privacySplit[0].split(".").map((item)=>parseInt(item));
        const termMonth = termDict[privacySplit[1]];
        // 파기될 날 계산
        const isLastMonth = (registerDate[1] + termMonth) % 12 === 0;
        const destroyedDate = [0,0,0];
        if (isLastMonth) {
            destroyedDate[0] = registerDate[0] + Math.floor((registerDate[1] + termMonth)/12) - 1;
            destroyedDate[1] = 12;
            destroyedDate[2] = registerDate[2];
        }
        else {
            destroyedDate[0] = registerDate[0] + Math.floor((registerDate[1] + termMonth)/12);
            destroyedDate[1] = (registerDate[1] + termMonth) % 12;
            destroyedDate[2] = registerDate[2];
        }
            // 파기될 날과 오늘 날짜 비교 -> 파기될 날보다 같거나 크면 파기 대상
        const destroyNum = destroyedDate[0]*28*12 + destroyedDate[1]*28 + destroyedDate[2];
        // console.log(todayNum)
        // console.log(destroyNum)
        // console.log(todayNum >= destroyNum)
        if (todayNum >= destroyNum) {
            answer.push(i+1)
        };
        
    }
    return answer;
}
