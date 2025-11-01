import java.util.*;

public class TwoSum {
    /**
     * Finds two numbers in an array that add up to a specific target.
     * Uses a HashMap for O(n) time complexity.
     *
     * @param nums The array of integers.
     * @param target The target sum.
     * @return An array containing the indices of the two numbers.
     * @throws IllegalArgumentException if no two sum solution is found.
     */

    public static int[] findTwoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        try {
            int[] result = findTwoSum(nums, target);
            System.out.println("Indices: [" + result[0] + ", " + result[1] + "]"); // Output: [0, 1]
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}
