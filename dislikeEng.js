function solution(numbers) {
    var answer = "";
    for (let i=0;i<numbers.length;i++){
        if (numbers[i] === "z"){
            answer += "0";
            i+=3;
        }
        else if (numbers[i] === "o"){
            answer += "1";
            i+=2;
        }
        else if (numbers[i] === "t"){
            if (numbers[i+1] === "w"){
                answer += "2";
                i+=2;
            }
            else {
                answer += "3";
                i+=4;
            }
        }
        else if (numbers[i] === "f"){
            if (numbers[i+1] === "o"){
                answer += "4";
            }
            else {
                answer += "5";
            }
            i+=3;
        }
        else if (numbers[i] === "s") {
            if (numbers[i+1] === "i") {
                answer += "6";
                i+=2;
            }
            else {
                answer += "7";
                i+= 4;
            }
        }
        else if (numbers[i]==="e"){
            answer += "8";
            i+=4;
        }
        else {
            answer += "9";
            i+=3;
        }
    }
    return Number.parseInt(answer);
}
