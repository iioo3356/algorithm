// 프로래머스 바탕화면 정리
function solution(wallpaper) {
    var answer = [];
    let lux = 51, luy = 51;
    let rdx = -1, rdy = -1;
    for (let x=0;x<wallpaper.length;x++){
        for (let y=0;y<wallpaper[x].length;y++){
            if (wallpaper[x][y] == "#"){
                lux = lux > x ? x : lux;
                luy = luy > y ? y : luy;
                rdx = rdx < x+1 ? x+1 : rdx;
                rdy = rdy < y+1 ? y+1 : rdy;
            }
        }
    }
    answer = [lux, luy, rdx, rdy];
    return answer;
}
