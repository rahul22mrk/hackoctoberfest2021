const arr = [
    [3,7,8],
    [9,11,13],
    [15,16,17]
 ];
 const luckyNumbers = (arr, res = []) => {
    let M = arr.length, N = arr[0].length;
    let min = Array(M).fill( Infinity);
    let max = Array(N).fill(-Infinity);
    for (let i = 0; i < M; ++i)
    for (let j = 0; j < N; ++j)
    min[i] = Math.min(min[i], arr[i][j]),
    max[j] = Math.max(max[j], arr[i][j]);
    for (let i = 0; i < M; ++i)
    for (let j = 0; j < N; ++j)
    if (min[i] == max[j])
    res.push(arr[i][j]);
    return res;
 };
 console.log(luckyNumbers(arr));