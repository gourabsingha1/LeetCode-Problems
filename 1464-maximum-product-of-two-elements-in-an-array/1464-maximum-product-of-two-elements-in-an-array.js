var maxProduct = function(nums) {
    nums = nums.sort(function(a, b) {
        return a - b
    });
    
    let n = nums.length;
    return (nums[n - 1] - 1) * (nums[n - 2] - 1);
};