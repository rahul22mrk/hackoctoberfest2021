  function pairLessK(arr,K){
     var left =0;
     var rigth=arr.length-1;
     var max= -1;

      while(left<rigth){
          var sum=arr[left]+arr[rigth]
          if(sum<K){
              if(sum>max){
                  max=sum
                  left++;
              }
            
             
          }
          else{
              rigth--;
          }
          return(max);
      }
    
  }
  
  
  
  function runProgram(input) {
    var newInput = input.trim().split("\n");
    for(var i=1;i<newInput.length;i+=3){
        var len= +newInput[i]
        var arr= newInput[i+1].trim().split(" ").map(Number)
        var k=  +newInput[i+2]

        // console.log(k);
        // console.log(arr);
       console.log( pairLessK(arr,k));


    }
    
  }
  if (process.env.USERNAME === "ranus") {
    runProgram(`2
    5
    1 2 3 4 5
    7
    3
    30 10 20
    15`);
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
  