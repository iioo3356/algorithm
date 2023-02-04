// 프로그래머스 둘만의 암호
function solution(s, skip, index) {
    var answer = '';
    const charArr = [];
    let charTemp = "a"

    for (let i=0;i<="z".charCodeAt()-"a".charCodeAt();i++){
        if (!skip.includes(charTemp) || s.includes(charTemp)){
            charArr.push(charTemp)
        }        
        charTemp = String.fromCharCode(charTemp.charCodeAt()+1);

    }
    
    for (let i=0;i<s.length;i++){
        const currentIndex = charArr.indexOf(s[i]);
        const newIndex = (currentIndex+index)%charArr.length
        answer += charArr[newIndex] 
    }
    return answer;
}
