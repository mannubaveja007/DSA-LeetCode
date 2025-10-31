public class MaxSubarraySum {
    public static int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        // 'max_so_far' stores the maximum subarray sum found up to the current point.
        int max_so_far = nums[0];
        // 'current_max' stores the maximum sum ending at the current position.
        int current_max = nums[0];

        for (int i = 1; i < nums.length; i++) {
            // Option 1: Start a new subarray at nums[i]
            // Option 2: Extend the previous subarray
            current_max = Math.max(nums[i], current_max + nums[i]);

            // Update the overall maximum sum found globally
            max_so_far = Math.max(max_so_far, current_max);
        }

        return max_so_far;
    }

    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int maxSum = maxSubArray(nums);
        System.out.println("Maximum contiguous subarray sum: " + maxSum); // Output: 6 (from [4, -1, 2, 1])
    }
}
