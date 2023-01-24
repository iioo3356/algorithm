// 카카오 테크 인턴십 - 성격 유형 검사하기
function solution(survey, choices) {
    var answer = '';
    const answerNum = [0, 3, 2, 1, 0, 1, 2, 3];
    const indexList = [["R", "T"], ["C", "F"], ["J", "M"], ["A", "N"]];
    let sumDict = {R: 0, T: 0, C: 0, F: 0, J: 0, M: 0, A: 0, N: 0};
    for (let i=0;i<survey.length;i++){
        if (choices[i] < 4){
            sumDict[survey[i][0]] += answerNum[choices[i]];
        }
        else {
            sumDict[survey[i][1]] += answerNum[choices[i]];
        }
    }
    for (let i=0;i<indexList.length;i++){
        if (sumDict[indexList[i][0]] >= sumDict[indexList[i][1]])
            answer += indexList[i][0];
        else
            answer += indexList[i][1];
    }
    return answer;
}
