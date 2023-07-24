// 프로그래머스 특이한 정렬
function solution(numlist, n) {
    var answer = [];
    answer = numlist.sort((a, b)=>{
        if (Math.abs(a-n) === Math.abs(b-n))
            return b-a;
        return Math.abs(a-n)-Math.abs(b-n)
    })
    return answer;
}
