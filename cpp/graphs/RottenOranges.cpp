/*
Problem: Rotten Oranges
Link: https://leetcode.com/problems/rotting-oranges/
Difficulty: Medium

Description:
You are given an m x n grid where each cell can have one of three values:
- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten
orange becomes rotten. Return the minimum number of minutes that must elapse
until no cell has a fresh orange. If this is impossible, return -1.

Approach:
This problem uses Breadth-First Search (BFS) to solve it efficiently.
1. First, we traverse the grid to find all initially rotten oranges and count
fresh oranges.
2. We add all rotten oranges to a queue along with time = 0.
3. We perform BFS where each rotten orange rots its adjacent fresh oranges.
4. For each rotten orange, we check all 4 directions (up, down, left, right).
5. If a fresh orange is found, it becomes rotten and is added to the queue with
time + 1.
6. We track the maximum time taken and decrease the count of fresh oranges.
7. Finally, if all fresh oranges are rotten, return the time; otherwise, return
-1.

Time Complexity: O(m * n) where m is rows and n is columns
Space Complexity: O(m * n) for the queue in worst case
*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Queue to store {row, col, time} for BFS traversal
    queue<vector<int>> q;
    int freshOranges = 0;

    // Step 1: Find all initially rotten oranges and count fresh oranges
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 2) {
          // Add rotten orange to queue with time = 0
          q.push({i, j, 0});
        } else if (grid[i][j] == 1) {
          // Count fresh oranges
          freshOranges++;
        }
      }
    }

    // If no fresh oranges exist, return 0
    if (freshOranges == 0)
      return 0;

    // Direction vectors for moving in 4 directions: up, down, left, right
    int dirRow[] = {-1, 1, 0, 0};
    int dirCol[] = {0, 0, -1, 1};

    int maxTime = 0;

    // Step 2: Perform BFS to rot adjacent fresh oranges
    while (!q.empty()) {
      vector<int> current = q.front();
      q.pop();

      int row = current[0];
      int col = current[1];
      int time = current[2];

      // Update the maximum time
      maxTime = max(maxTime, time);

      // Step 3: Check all 4 adjacent cells
      for (int i = 0; i < 4; i++) {
        int newRow = row + dirRow[i];
        int newCol = col + dirCol[i];

        // Check if the new position is valid and has a fresh orange
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
            grid[newRow][newCol] == 1) {

          // Rot the fresh orange
          grid[newRow][newCol] = 2;

          // Add the newly rotten orange to queue with incremented time
          q.push({newRow, newCol, time + 1});

          // Decrease the count of fresh oranges
          freshOranges--;
        }
      }
    }

    // Step 4: If all fresh oranges are rotten, return time; otherwise return -1
    return (freshOranges == 0) ? maxTime : -1;
  }
};
