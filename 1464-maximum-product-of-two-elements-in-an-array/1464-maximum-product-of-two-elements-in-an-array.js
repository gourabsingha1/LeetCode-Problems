var maxProduct = function(nums) {
    let max = 0, secondMax = 0;
    for(let i = 0; i < nums.length; i++) {
        if(max < nums[i]) {
            secondMax = max;
            max = nums[i];
        }
        else if(secondMax < nums[i]) {
            secondMax = nums[i];
        }
    }
    return (max - 1) * (secondMax - 1);
};