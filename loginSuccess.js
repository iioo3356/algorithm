// 프로그래머스 로그인 성공?
function solution(id_pw, db) {
    var answer = '';
    for (let i=0;i<db.length;i++){
        if (db[i][0] === id_pw[0] && db[i][1] === id_pw[1]){
            answer = "login";
            break;
        }
        else if (db[i][0] === id_pw[0] && db[i][1] !== id_pw[1]){
            answer = "wrong pw";
        }
    }
    if (answer === "") answer = "fail";
    return answer;
}
