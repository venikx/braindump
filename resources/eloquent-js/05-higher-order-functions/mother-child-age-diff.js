var differences = ancestry.filter(function (person) {
    return byName[person.mother] != null;
}).map(function (person) {
    return person.born - byName[person.mother].born;
});