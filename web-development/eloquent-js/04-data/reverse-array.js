var reverseArray = function(array){
    newArray = [];

    for(i = 0; i < array.length; i++){
        newArray.unshift(array[i]);
    }
    return newArray;
};

var reverseArrayInPlace = function(array){
    var storeElement = 0;

    for (i = 0; i < Math.floor(array.length/2); i++){
        storeElement = array[i];
        array[i] = array[array.length - 1 - i];
        array[array.length - 1 - i] = storeElement;
    };
};

console.log(reverseArray(["A", "B", "C"]));
var arrayValue = [1, 2, 3, 4, 5];
reverseArrayInPlace(arrayValue);
console.log(arrayValue);
