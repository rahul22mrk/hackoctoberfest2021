function Alltwice(arr){
    let obj={}
    for(let i=0;i<arr.length;i++){
       if(obj[arr[i]]==undefined){
           obj[arr[i]] =1
       }
       else{
           obj[arr[i]]+=1
       }
    }

    for (key in obj){
        if(obj[key]==1)
        console.log(key);
    }

}


function runProgram(input) {
     let newInput=input.trim().split("\n");
     for(let i=1;i<newInput.length;i+=2){
         let len =  +newInput[i]
         let num= newInput[i+1].trim().split(" ")
        //  console.log(num);
        Alltwice(num);

     }
   
 }
 if (process.env.USERNAME === "ranus") {
    runProgram(`2
    1
    5
    5
    1 2 1 3 2`);
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