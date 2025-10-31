import java.util.*;
public class RemoveDuplicates {
     /**
     * Removes duplicates from a sorted array in-place.
     * Uses the Two Pointers technique for an efficient O(n) time solution.
     * The method returns the new length of the array without duplicates.
     *
     * @param nums The sorted array of integers. The array is modified in-place.
     * @return The new length of the array after removing duplicates.
     */
    public static int removeDuplicates(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        // 'writeIndex' tracks the position where the next unique element should be placed.
        // It starts at 1 because the element at index 0 is always unique in a non-empty array.
        int writeIndex = 1;
        
        // 'readIndex' iterates through the entire array.
        for (int readIndex = 1; readIndex < nums.length; readIndex++) {
            // Check if the current element (readIndex) is different from the previous unique element (readIndex - 1)
            if (nums[readIndex] != nums[readIndex - 1]) {
                // If they are different, it means we found a new unique element.
                nums[writeIndex] = nums[readIndex];
                writeIndex++; // Move the unique pointer forward.
            }
            // If they are the same, we just skip (i.e., we don't increment writeIndex, effectively 'removing' the duplicate).
        }
        return writeIndex;
    }

    public static void main(String[] args) {
        int[] nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int newLength = removeDuplicates(nums);
        System.out.println("New array length: " + newLength); 
        System.out.print("Modified array (first " + newLength + " elements): ");
        for (int i = 0; i < newLength; i++) {
            System.out.print(nums[i] + (i < newLength - 1 ? ", " : ""));
        }
        System.out.println();
    }
}
