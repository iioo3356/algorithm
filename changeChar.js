const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = "";
let answer = "";

rl.on('line', function (line) {
    input = line;
}).on('close',function(){
    for (let i=0;i<input.length;i++){
        if ('a' <= input[i] && input[i] <= 'z') {
            answer += input[i].toUpperCase();
        }
        else {
            answer += input[i].toLowerCase();
        }
    }
    console.log(answer)
});
