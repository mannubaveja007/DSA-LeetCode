
import java.util.ArrayList;

/*
Multiple Recursion Example: Generating Subsequences (Subsets)

Functions:
1. SubSeq(ArrayList<Integer> arr, ArrayList<Integer> ans, int idx)
   - Uses backtracking with in-place mutation (add / remove last).
   - Explores two branches at each index: include current element, exclude current element.
2. Subs(String str, String ans, int idx)
   - Same logical structure, but uses String concatenation (immutable) instead of mutation.

Recursion Tree (SubSeq) for arr = [1,2,3]:
(idx, ans)
SubSeq(0, [])
├─ include 1 -> SubSeq(1, [1])
│  ├─ include 2 -> SubSeq(2, [1,2])
│  │  ├─ include 3 -> SubSeq(3, [1,2,3])  print [1, 2, 3]
│  │  └─ exclude 3 -> SubSeq(3, [1,2])    print [1, 2]
│  └─ exclude 2 -> SubSeq(2, [1])
│     ├─ include 3 -> SubSeq(3, [1,3])    print [1, 3]
│     └─ exclude 3 -> SubSeq(3, [1])      print [1]
└─ exclude 1 -> SubSeq(1, [])
   ├─ include 2 -> SubSeq(2, [2])
   │  ├─ include 3 -> SubSeq(3, [2,3])    print [2, 3]
   │  └─ exclude 3 -> SubSeq(3, [2])      print [2]
   └─ exclude 2 -> SubSeq(2, [])
      ├─ include 3 -> SubSeq(3, [3])      print [3]
      └─ exclude 3 -> SubSeq(3, [])       print []

Print (preorder with include-first):
[1, 2, 3]
[1, 2]
[1, 3]
[1]
[2, 3]
[2]
[3]
[]

Dry Run Highlights (SubSeq):
- At each level: add element -> recurse -> remove element (backtrack) -> recurse without element.
- Leaves (idx == n) output current subset.
- Total leaves = 2^n, total calls = 2^{n+1} - 1.
- Time: O(2^n); Space: O(n) stack + O(n) for current list.

Recursion Tree (Subs) for str = "abc": (format Subs(idx, ans))
Subs(0, "")
├─ include 'a' -> Subs(1, "a")
│  ├─ include 'b' -> Subs(2, "ab")
│  │  ├─ include 'c' -> Subs(3, "abc") print abc
│  │  └─ exclude 'c' -> Subs(3, "ab")  print ab
│  └─ exclude 'b' -> Subs(2, "a")
│     ├─ include 'c' -> Subs(3, "ac")  print ac
│     └─ exclude 'c' -> Subs(3, "a")   print a
└─ exclude 'a' -> Subs(1, "")
   ├─ include 'b' -> Subs(2, "b")
   │  ├─ include 'c' -> Subs(3, "bc")  print bc
   │  └─ exclude 'c' -> Subs(3, "b")   print b
   └─ exclude 'b' -> Subs(2, "")
      ├─ include 'c' -> Subs(3, "c")   print c
      └─ exclude 'c' -> Subs(3, "")    print (empty)

Print order:
abc
ab
ac
a
bc
b
c
<empty line>

Complexity (Subs): Same as SubSeq — O(2^n) time, O(n) stack. No explicit removal needed because Strings are immutable and new ones are built for the include branch.

General Pattern (Binary Choice Recursion):
For each position i:
  branch1 = choose element i
  branch2 = skip element i
Depth = n, branching factor ~2 => number of leaves 2^n.

*/


public class SubsequenceProblem {
    public static void main(String[] args) {
        // Example run for integer subsequences:
        // ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(1, 2, 3));
        // ArrayList<Integer> ans = new ArrayList<>();
        // SubSeq(arr, ans, 0);

        // Example run for string subsequences:
        String str = "abc";
        String ans = "";
        Subs(str, ans, 0);
    }

    // Generates all subsequences of the integer list using backtracking (mutate + undo)
    public static void SubSeq(ArrayList<Integer> arr, ArrayList<Integer> ans, int idx) {
        // Base case: processed all elements -> output current collected subset
        if(idx == arr.size()){
            System.out.println(ans);
            return;
        }
        // Include current element
        ans.add(arr.get(idx));
        SubSeq(arr, ans, idx+1);
        // Backtrack (undo inclusion)
        ans.remove(ans.size()-1);
        // Exclude current element
        SubSeq(arr, ans, idx+1);
    }

    // Generates all subsequences of the string. Uses string concatenation (immutable) so no undo needed.
    public static void Subs(String str, String ans, int idx) {
        // Base case: all characters considered
        if(idx == str.length()){
            System.out.println(ans);
            return;
        }
        // Include current character
        Subs(str, ans+str.charAt(idx), idx+1);
        // Exclude current character
        Subs(str, ans, idx+1);
    }
}
