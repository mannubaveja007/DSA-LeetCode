/*
 * LeetCode #326: Power of Three
 * ------------------------------------------------------------
 * Problem:
 *   Given an integer n, return true if it is a power of three.
 *
 *   A number is a power of three if there exists an integer x
 *   such that n == 3^x.
 *
 * ------------------------------------------------------------
 * Approach 1: Iterative Division
 *   - Keep dividing n by 3 while it’s divisible by 3.
 *   - If we end up at 1, n is a power of 3.
 *
 * Approach 2: Mathematical Check
 *   - The largest power of 3 within 32-bit integer is 3^19 = 1162261467.
 *   - If n > 0 and 1162261467 % n == 0, then n is a power of 3.
 *
 * ------------------------------------------------------------
 * Complexity:
 *   Time  → O(log₃ n)
 *   Space → O(1)
 */

public class PowerOfThree {

    // ✅ Method 1: Iterative Division
    public static boolean isPowerOfThreeIterative(int n) {
        if (n <= 0) return false;

        // Divide until n is no longer divisible by 3
        while (n % 3 == 0) {
            n /= 3;
        }

        // If n becomes 1 → it's a power of 3
        return n == 1;
    }

    // ✅ Method 2: Mathematical Constant Check
    public static boolean isPowerOfThreeMath(int n) {
        // Largest power of 3 in 32-bit integer = 3^19 = 1162261467
        return n > 0 && 1162261467 % n == 0;
    }

    // ✅ Method 3: Recursive Approach (for understanding)
    public static boolean isPowerOfThreeRecursive(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 3 != 0) return false;
        return isPowerOfThreeRecursive(n / 3);
    }

    // 🚀 Test the methods
    public static void main(String[] args) {
        int[] testCases = {1, 3, 9, 27, 45, 81, 0, -3, 1162261467};

        System.out.println("=== Power of Three Checker ===");
        for (int n : testCases) {
            System.out.printf("n = %-10d | Iterative: %-5s | Math: %-5s | Recursive: %-5s%n",
                    n,
                    isPowerOfThreeIterative(n),
                    isPowerOfThreeMath(n),
                    isPowerOfThreeRecursive(n));
        }

        /*
         * Expected Output:
         * n = 1          | Iterative: true  | Math: true  | Recursive: true
         * n = 3          | Iterative: true  | Math: true  | Recursive: true
         * n = 9          | Iterative: true  | Math: true  | Recursive: true
         * n = 27         | Iterative: true  | Math: true  | Recursive: true
         * n = 45         | Iterative: false | Math: false | Recursive: false
         * n = 81         | Iterative: true  | Math: true  | Recursive: true
         * n = 0          | Iterative: false | Math: false | Recursive: false
         * n = -3         | Iterative: false | Math: false | Recursive: false
         * n = 1162261467 | Iterative: true  | Math: true  | Recursive: true
         */
    }
}
