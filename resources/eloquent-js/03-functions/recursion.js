var isEven = function(a){
    if(a === 0) return true;
    if(a === 1) return false;
    return isEven(Math.abs(a-2));
};

console.log(isEven(-10));
