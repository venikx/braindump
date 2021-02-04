var deepEqual = function(obj1, obj2){
    if(typeof obj1 == "object" && obj1 != null
       && typeof obj2 == "object" && obj2 != null){

        var countObj1 = 0, countObj2 = 0;
        for(var x in obj1){
            countObj1++;
        }

        for (var y in obj2) {
            countObj2++;
            if(!(y in obj1) || !deepEqual(obj1[y], obj2[y])) return false;
        }
        return countObj2 === countObj1;
    } else {
        return obj1 === obj2;
    }
};

var obj = {here: {is: "an"}, object: 2};
console.log(deepEqual(obj, obj));
console.log(deepEqual(obj, {here: 1, object: 2}));
console.log(deepEqual(obj, {here: {is: "an"}, object: 2}));
