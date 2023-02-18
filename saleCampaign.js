// 프로그래머스 스쿨 할인 행사
function solution(want, number, discount) {
    var answer = 0;
    const wantSet = {};
    for (let i=0;i<want.length;i++){
        wantSet[want[i]] = i+1;
    }
    for (let i=0;i<=discount.length-10;i++){
        const copyNumber = number.map((num)=>num);
        for (let j=i;j<i+10;j++){
            if (wantSet[discount[j]]){
                copyNumber[wantSet[discount[j]]-1]--;
            }
        }
        let isGood = true;
        for (let j=0;j<number.length;j++){
            if (copyNumber[j] > 0){
                isGood = false;
                break;
            }
        }
        if (isGood) answer++;
    }
    return answer;
}
