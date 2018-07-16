var arrays = [[1, 2, 3], [4, 5], [6]];

var flat = function (nestedArray) {
    return nestedArray.reduce(function (prev, curr) {
        return prev.concat(curr);
    }, []);
}

console.log(flat(arrays))
