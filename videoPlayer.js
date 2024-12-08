// [PCCP 기출문제] 1번 / 동영상 재생기
function getSeconds (str) {
    let [minutes_str, seconds_str] = str.split(":")
    return parseInt(minutes_str) * 60 + parseInt(seconds_str)
}

function getRightPosition (video_seconds, pos_seconds, op_start_seconds, op_end_seconds) {
    let pos = pos_seconds
    if (pos <= 0) {
        pos = 0
    }
    if (pos >= video_seconds) {
        pos = video_seconds
    }
    if (pos >= op_start_seconds && pos <= op_end_seconds) {
        pos = op_end_seconds
    }
    return pos
}

function solution(video_len, pos, op_start, op_end, commands) {
    var answer = '';
    
    const video_seconds = getSeconds(video_len)
    let pos_seconds = getSeconds(pos)
    const op_start_seconds = getSeconds(op_start)
    const op_end_seconds = getSeconds(op_end)
    
    pos_seconds = getRightPosition(video_seconds, pos_seconds, op_start_seconds, op_end_seconds)
    for (let i=0;i<commands.length;i++){
        if (commands[i] == "next") {
            pos_seconds += 10
        }
        else {
            pos_seconds -= 10
        }
        pos_seconds = getRightPosition(video_seconds, pos_seconds, op_start_seconds, op_end_seconds)


    }
    answer = String(Math.floor(pos_seconds / 60)).padStart(2, '0') + ":" + String((pos_seconds % 60)).padStart(2, '0')
    return answer;
}
