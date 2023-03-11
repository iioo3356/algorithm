// 프로그래머스 덧칠하기
function solution(n, m, section) {
    var answer = 0;
    const wall = Array.from({length: n+1}, ()=>1);
    for (let i=0;i<section.length;i++){
        wall[section[i]] = 0;
    }
    for (let i=0;i<wall.length;i++){
        if (wall[i] === 0){
            answer++;
            for (let j=i;j<i+m;j++){
                wall[j] = 1;
            }
            i+=m-1;
        }
    }
    return answer;
}
