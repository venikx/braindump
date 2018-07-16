var countChar = function(string, letter){
    var count = 0;

    for(var i = 0; i < string.length; i++){
        if(string.charAt(i) === letter) count++;
    }
    return count;
};

console.log(countChar("Hello, Javascript", "a"));
