// 프로그래머스 코드 처리하기
function solution(code) {
    let ret = '';
    let mode = 0;
    for (let i=0;i<code.length;i++){
        if (code[i] === "1"){
            mode = mode === 0 ? 1 : 0;
        }
        else {
            if ((mode === 0 && i%2 === 0) ||( mode === 1 && i%2 !== 0))
                ret += code[i];
        }
    }
    if (ret === "") ret = "EMPTY";
    return ret;
}
