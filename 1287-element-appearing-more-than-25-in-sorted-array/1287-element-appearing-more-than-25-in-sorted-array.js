var findSpecialInteger = function(arr) {
    let res = 0, cnt = 1, limit = arr.length / 4;
    for (let i = 1; i < arr.length; i++)
    {
        if(arr[i - 1] == arr[i]) {
            cnt++;
        }
        else {
            cnt = 1;
        }
        if(cnt > limit) {
            return arr[i];
        }
    }
    return arr[0];
};