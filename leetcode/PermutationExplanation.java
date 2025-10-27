import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * PermutationExplanation.java
 * ------------------------------------------------------------
 * Contains:
 * 1. In-place swap based permutation generator (distinct elements)
 * 2. Used[] (boolean) based permutation generator (alternative pattern)
 * 3. Recursion tree printer (for learning) for array {1,2,3}
 * 4. Dry run + recursion tree (documented below)
 * 5. Time & Space Complexity analysis
 * 6. Edge cases & notes
 *
 * ------------------------------------------------------------
 * DRY RUN (In-Place Swap Method) FOR arr = [1,2,3]
 * Function: permuteSwap(arr, idx)
 * Start: permuteSwap([1,2,3], 0)
 * Depth 0 (idx=0): loop i=0..2
 *   i=0: swap(0,0) -> [1,2,3]
 *       permuteSwap([1,2,3],1)
 *         Depth 1 (idx=1): loop i=1..2
 *           i=1: swap(1,1) -> [1,2,3]
 *               permuteSwap([1,2,3],2)
 *                 Depth 2 (idx=2): loop i=2..2
 *                   i=2: swap(2,2) -> [1,2,3]
 *                       permuteSwap([1,2,3],3)  // idx==n => output [1,2,3]
 *                   backtrack swap(2,2) -> [1,2,3]
 *               backtrack swap(1,1) -> [1,2,3]
 *           i=2: swap(1,2) -> [1,3,2]
 *               permuteSwap([1,3,2],2)
 *                 i=2: swap(2,2) -> [1,3,2]
 *                     permuteSwap([1,3,2],3) => output [1,3,2]
 *                 backtrack -> [1,3,2]
 *               backtrack swap(1,2) -> [1,2,3]
 *         exit depth 1
 *       backtrack swap(0,0) -> [1,2,3]
 *   i=1: swap(0,1) -> [2,1,3]
 *       permuteSwap([2,1,3],1)
 *         i=1: swap(1,1) -> [2,1,3]
 *             permuteSwap([2,1,3],2)
 *               i=2: swap(2,2) -> [2,1,3]
 *                   permuteSwap(...,3) => [2,1,3]
 *               backtrack
 *         i=2: swap(1,2) -> [2,3,1]
 *             permuteSwap([2,3,1],2)
 *               i=2: swap(2,2) -> [2,3,1]
 *                   permuteSwap(...,3) => [2,3,1]
 *               backtrack
 *             backtrack -> [2,1,3]
 *         exit depth 1
 *       backtrack swap(0,1) -> [1,2,3]
 *   i=2: swap(0,2) -> [3,2,1]
 *       permuteSwap([3,2,1],1)
 *         i=1: swap(1,1) -> [3,2,1]
 *             permuteSwap([3,2,1],2)
 *               i=2: swap(2,2) -> [3,2,1]
 *                   permuteSwap(...,3) => [3,2,1]
 *               backtrack
 *         i=2: swap(1,2) -> [3,1,2]
 *             permuteSwap([3,1,2],2)
 *               i=2: swap(2,2) -> [3,1,2]
 *                   permuteSwap(...,3) => [3,1,2]
 *               backtrack
 *             backtrack -> [3,2,1]
 *         exit depth 1
 *       backtrack swap(0,2) -> [1,2,3]
 * Exit depth 0
 * OUTPUT ORDER: [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,2,1] [3,1,2]
 *
 * ------------------------------------------------------------
 * RECURSION TREE (each node shows idx + array state entering node)
 *                          (idx=0,[1,2,3])
 *             /-------------------|--------------------\
 *      (i=0) /                    | (i=1)              \ (i=2)
 *  (idx=1,[1,2,3])        (idx=1,[2,1,3])         (idx=1,[3,2,1])
 *       /     \               /     \                /     \
 * [1,2,3] [1,3,2]      [2,1,3] [2,3,1]       [3,2,1] [3,1,2]
 * (idx=3 leaves / outputs)  (idx=3 leaves / outputs) (idx=3 leaves / outputs)
 *
 * Note: Leaves correspond to idx == n and produce each permutation.
 *
 * ------------------------------------------------------------
 * TIME COMPLEXITY (Swap Method):
 *   - There are n! permutations. For each leaf we copy/collect O(n) elements.
 *   - Total T(n) = n * n! (output cost dominates). Recurrence roughly: T(n) = n * T(n-1) + O(n) => O(n * n!).
 * SPACE COMPLEXITY:
 *   - Recursion depth: O(n)
 *   - In-place so no extra per-branch arrays beyond O(n) call stack.
 *   - If collecting results: O(n * n!) storage. Streaming print avoids this cost.
 *   - Auxiliary (used[] version): O(n) for boolean + path list.
 *
 * ------------------------------------------------------------
 * WHEN TO USE WHICH:
 *   - In-place swap: fastest, minimal extra memory, order unspecified unless controlled.
 *   - used[] + path: easier when original array must remain unmodified at each level or when selecting k < n positions.
 *
 * EDGE CASES:
 *   - Empty array => one permutation: []
 *   - Single element => itself
 *   - Duplicates => need extra logic (not covered directly here) or frequency map method.
 *
 */
public class PermutationExplanation {

    // 1. In-place swap based generation (distinct elements)
    public static List<int[]> permuteSwap(int[] nums) {
        List<int[]> out = new ArrayList<>();
        backtrackSwap(nums, 0, out);
        return out;
    }

    private static void backtrackSwap(int[] a, int idx, List<int[]> out) {
        if (idx == a.length) {
            out.add(a.clone()); // capture permutation
            return;
        }
        for (int i = idx; i < a.length; i++) {
            swap(a, idx, i);
            backtrackSwap(a, idx + 1, out);
            swap(a, idx, i); // backtrack
        }
    }

    // 2. Alternative: used[] + path list (works well for k-permutations too)
    public static List<List<Integer>> permuteUsed(int[] nums) {
        List<List<Integer>> out = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        List<Integer> path = new ArrayList<>();
        backtrackUsed(nums, used, path, out);
        return out;
    }

    private static void backtrackUsed(int[] nums, boolean[] used, List<Integer> path, List<List<Integer>> out) {
        if (path.size() == nums.length) {
            out.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            used[i] = true;
            path.add(nums[i]);
            backtrackUsed(nums, used, path, out);
            path.remove(path.size() - 1);
            used[i] = false; // backtrack
        }
    }

    // 3. Recursion tree printer for educational visualization
    public static void printRecursionTree(int[] nums) {
        System.out.println("Recursion Tree (swap method):");
        recurseTree(nums, 0, 0);
    }

    private static void recurseTree(int[] a, int idx, int depth) {
        char[] indent = new char[depth * 2];
        Arrays.fill(indent, ' ');
        System.out.println(new String(indent) + "idx=" + idx + " -> " + Arrays.toString(a));
        if (idx == a.length) return;
        for (int i = idx; i < a.length; i++) {
            swap(a, idx, i);
            recurseTree(a, idx + 1, depth + 1);
            swap(a, idx, i);
        }
    }

    private static void swap(int[] a, int i, int j) {
        if (i != j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    // 4. Demo main
    public static void main(String[] args) {
        int[] arr = {1, 2, 3};

        System.out.println("=== In-place Swap Permutations ===");
        List<int[]> perms = permuteSwap(arr.clone());
        for (int[] p : perms) System.out.println(Arrays.toString(p));
        System.out.println("Total: " + perms.size());

        System.out.println("\n=== used[] Pattern Permutations ===");
        List<List<Integer>> perms2 = permuteUsed(arr);
        for (List<Integer> p : perms2) System.out.println(p);
        System.out.println("Total: " + perms2.size());

        System.out.println("\n=== Recursion Tree (Educational) ===");
        printRecursionTree(arr.clone());

        System.out.println("\nTime Complexity: O(n * n!)  |  Space Complexity: O(n) recursion (excluding output)");
    }
}
