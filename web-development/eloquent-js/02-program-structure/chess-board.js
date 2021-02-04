const size = 10;

for (i = 0; i < size; i++) {
    let chessLine = "";
    for(j = 0; j < size; j++){
        (i + j) % 2 === 0
            ? chessLine += " "
            : chessLine += "#";
    }
    console.log(chessLine);
}
