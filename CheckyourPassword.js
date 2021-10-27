function runProgram(input) {
    // Write code here
    var input = input.trim().split("\n");

    for (let i = 2; i < input.length; i += 2) {
        var str = input[i].trim()
        // console.log(str)
        let count = 0
        for (let j = 0; j < str.length; j++) {
            if (str[j] < 10 && str[j] >= 0) {
                count++
            }
        }
        // console.log(count)
        if (count < str.length / 2 && count > 0) {
            console.log("Strong")
        }
        else {
            console.log("Weak")
        }
    }

}
if (process.env.USERNAME === "ranus") {
    runProgram(`2
    6
    aa1234
    6
    abcd12
    4
    pjfj`);
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