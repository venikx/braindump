var range = function(start, end, step){
    var range = [];
    if(step == undefined) step = 1;

    for(var i = start; i <= end; i+= step){
        range.push(i);
    }
    return range;
};
console.log(range(1, 10, 2));

var sum = function(array){
    var sum = 0;

    for(var i = 0; i < array.length; i++){
        sum += array[i];
    }
    return sum;
};
console.log(sum(range(1, 10, 2)));
