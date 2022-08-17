// 프로그래머스 최소직사각형(js)
function solution(sizes) {
    let answer = 0;
    for (let i=0;i<sizes.length;i++){
        if (sizes[i][0]<sizes[i][1]){
            let temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }
    let width = [];
    let height = [];
    for (let i=0;i<sizes.length;i++){
        width.push(sizes[i][0]);
        height.push(sizes[i][1]);
    }
    width.sort(function(a,b) {return b-a});
    height.sort(function(a,b) {return b-a});
    answer = width[0] * height[0];
    return answer;
}
