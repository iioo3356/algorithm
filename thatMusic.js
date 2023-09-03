// 프로그래머스 방금그곡
function convertMelody(melody) {
    melody = melody.replaceAll("C#", "c").replaceAll("D#", "d").replaceAll("F#", "f").replaceAll("G#", "g").replaceAll("A#", "a");
    return melody;
}

function solution(m, musicinfos) {
    var answer = '';
    let answerList = [];
    const findMelody = convertMelody(m);
    for (let i=0;i<musicinfos.length;i++){
        let allMusic = ""
        const splitMusicInfos = musicinfos[i].split(",");
        const musicName = splitMusicInfos[2];
        const startTime = parseInt(splitMusicInfos[0].split(":")[0]) * 60 + parseInt(splitMusicInfos[0].split(":")[1]);
        const endTime = parseInt(splitMusicInfos[1].split(":")[0]) * 60 + parseInt(splitMusicInfos[1].split(":")[1]);
        const playTime = endTime - startTime;
        const music = convertMelody(splitMusicInfos[3]);        
        if (playTime / music.length >= 1)
            for (let j=0;j<playTime / music.length;j++){
                allMusic += music;
            }
        for (let j=0;j<playTime % music.length;j++){
            allMusic += music[j];
        }
        console.log(allMusic)
        const mIndex = allMusic.indexOf(findMelody);
        if (mIndex !== -1){
            answerList.push({index: i, playTime: playTime, musicName: musicName});            
        }
    }
    if (answerList.length === 0) answer = "(None)"
    else {
        answerList.sort((a, b) =>{
            if (a.playTime === b.playTime){
                return a.index - b.index
            }
            return b.playTime - a.playTime;
        })
        answer = answerList[0].musicName;
    }
    return answer;
}
