var arrayToList = function(array) {
    var list = null;

    for (var i = array.length - 1; i >= 0; i--) {
        list = {
            value: array[i],
            rest: list
        };
    };
    return list;
};

var listToArray = function(list) {
    var arrayList = [];

    for (var listEl = list; listEl; listEl = listEl.rest) {
        arrayList.push(listEl.value);
    };
    return arrayList;
};

var prependList = function(element, list) {
    return {
        value: element,
        rest: list
    };
};

var nth = function(list, n) {
    if (!list) {
        return undefined;
    } else if (n === 0) {
        return list.value;
    } else {
        return nth(list.rest, n - 1);
    }
};

var list = arrayToList([10, 30, "b"]);
console.log(list);
console.log(listToArray(list));
console.log(prependList(67, list));
console.log(nth(list, 1));
