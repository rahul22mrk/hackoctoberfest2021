function runProgram(input) {
    // Write code here
    var input = input.trim().split("\n")

    for (let i = 1; i < input.length; i++) {
        let str = input[i].trim()
        console.log(str);
        // console.log(str.charCodeAt(0) - 64)
        if (str.length == 1) {
            console.log(str.charCodeAt(0) - 64)
        } else {
            let res = 0
            for (let j = 0; j < str.length; j++) {
                // console.log(str.charCodeAt(j) - 64)
                res = res * 26 + ((str.charCodeAt(j) - 64))
            }
            console.log(res)
        }
    }

}

if (process.env.USERNAME === "ranus") {
    runProgram(`3
    A
    AB
    ZY`);
} else {
    process.stdin.resume();
    process.stdin.setEncoding("ascii");
    let read = "";
    process.stdin.on("data", function (input) {
        read += input;
    });
    process.stdin.on("end", function () {
        read = read.replace(/\n$/, "");
        read = read.replace(/\n$/, "");
        runProgram(read);
    });
    process.on("SIGINT", function () {
        read = read.replace(/\n$/, "");
        runProgram(read);
        process.exit(0);
    });
}