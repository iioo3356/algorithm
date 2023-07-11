// 프로그래머스 롤케이크 자르기
function solution(topping) {
    var answer = 0;
    const brother = new Set(topping);
    const cheolsu = new Set()

    const toppingDict = {};
    for (let i=0;i<topping.length;i++){
        if (toppingDict[topping[i]]) toppingDict[topping[i]]++;
        else toppingDict[topping[i]] = 1;
    }
    for (let i=0;i<topping.length;i++){
        if (toppingDict[topping[i]] > 1) toppingDict[topping[i]]--;
        else brother.delete(topping[i]);
        
        cheolsu.add(topping[i]);
        if (brother.size === cheolsu.size){
            answer++;
        }
    }
    return answer;
}
