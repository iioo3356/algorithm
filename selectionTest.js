// 프로그래머스 전국 대회 선발 고사
function solution(rank, attendance) {
    var answer = 0;
    rank = rank.map((r, idx)=>[idx, r])
    const filteredRank = rank.filter((item)=>attendance[item[0]] === true);
    filteredRank.sort((a, b)=>a[1]-b[1]);
    answer = 10000 * filteredRank[0][0] + 100 * filteredRank[1][0] + filteredRank[2][0];
    return answer;
}
