for (i = 0; i <= 100; i++) {
    let output = "";

    output += i % 3 === 0 ? "Fizz" : "";
    output += i % 5 === 0 ? "Buzz" : "";

    console.log(output || i);
}
