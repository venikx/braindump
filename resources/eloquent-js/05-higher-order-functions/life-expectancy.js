var groupBy = function (array, groupOf) {
    var groups = {};

    array.forEach(function (el) {
        var groupName = groupOf(el);
        if (groupName in groups) {
            groups[groupName].push(el);
        } else {
            groups[groupName] = [el];
        }
    });
    return groups;
}

var groupByCentury = groupBy(ancestry, function (ancestor) {
    return Math.ceil(ancestor.died / 100);
});

for (century in groupByCentury) {
    var ages = groupByCentury[century].map(function (ancestor) {
        return ancestor.died - ancestor.born;
    });
    console.log(century, ": ", average(ages));
}