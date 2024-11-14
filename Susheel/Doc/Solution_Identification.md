# Search Techniques Overview

## 1. Binary Search on a Sorted Array
- **Description**: This is the classic binary search, where you halve the search space to find a target element in a sorted list or array.
- **When to Use**:
  - The array is already sorted.
  - You’re looking for an exact match (e.g., finding the presence of a value or the position of a value in a list).
  - Problems may specify looking for an element’s position or whether an element exists.
- **Hints**:
  - Check if the array is sorted or can be sorted. This is a strong signal.
  - The problem may be phrased in a way that asks for a specific item, such as “find if X exists in the array” or “find the first/last occurrence of X.”
- **Examples**:
  - Find a target element in a sorted list.
  - Find the boundary point where a condition changes (e.g., first index where a value exceeds a threshold).

## 2. Binary Search on the Answer (Optimization Binary Search)
- **Description**: Binary search is applied over a range of possible answers (like a numerical range) to find the minimum or maximum that satisfies a condition.
- **When to Use**:
  - The problem involves minimizing a maximum or maximizing a minimum.
  - There is a clear range for the answer (e.g., 1 to total_products).
  - You can create a feasibility check for each potential answer.
- **Hints**:
  - Phrases like “minimize the maximum”, “maximize the minimum”, or anything that asks for a balance in distribution.
  - Look for optimization across a range rather than finding an exact match.
- **Examples**:
  - Minimize maximum workload across workers, minimize maximum distance in a distribution problem, or maximize minimum length of rope cuts.

## 3. Breadth-First Search (BFS)
- **Description**: BFS explores all possible states level-by-level, ideal for shortest-path problems in unweighted graphs or grids.
- **When to Use**:
  - You need the shortest path or minimum steps to reach a target state or position in an unweighted graph or grid.
  - The problem involves exploring multiple states systematically (like each level in a tree or maze).
- **Hints**:
  - Problems often involve grids or graphs where the solution is found by expanding outward from a start point.
  - You’re asked for the minimum number of steps or shortest path in a maze, tree, or graph without weights.
- **Examples**:
  - Shortest path in a maze, minimum moves to reach a target, or levels in a tree.

## 4. Depth-First Search (DFS)
- **Description**: DFS explores each path to its full depth before backtracking, ideal for problems that need all possible solutions or finding paths in recursive structures.
- **When to Use**:
  - The problem requires exploring all possible configurations or paths, often in search of all solutions, not just one.
  - It’s useful for problems that can be framed as traversing nodes in a graph/tree or recursively generating solutions.
- **Hints**:
  - Problems may involve finding all paths or checking for cycles.
  - You might need to explore every possible combination or subset (backtracking problems).
- **Examples**:
  - Finding all possible paths in a maze, solving puzzles that need full exploration, generating all subsets or permutations.

## 5. Ternary Search
- **Description**: Ternary search divides the search space into three parts rather than two, ideal for unimodal functions where the function value has a single peak (maximum or minimum).
- **When to Use**:
  - The problem involves finding the maximum or minimum of a unimodal function (a function that has a single peak or valley).
  - Typically used in continuous search spaces or where we can divide the function into three parts to locate a peak or valley.
- **Hints**:
  - Phrases like “find the maximum/minimum in a range” when the range behaves like a single smooth hill or valley.
- **Examples**:
  - Finding the maximum or minimum point in a unimodal array or continuous function.

## 6. Exponential Search
- **Description**: Exponential search is useful for unbounded or infinite sorted arrays. It doubles the search range to quickly "home in" on the range where the target might be, then switches to binary search.
- **When to Use**:
  - You need to search in a sorted, infinite, or unbounded list (e.g., data streams where the end is unknown).
  - When the array is very large, and you’re not given explicit bounds.
- **Hints**:
  - The array is sorted but unbounded or infinite, and a target must be found without knowing the length of the array.
- **Examples**:
  - Searching in data streams or extremely large sorted datasets.

## 7. Interpolation Search
- **Description**: Interpolation search is an improvement over binary search for uniformly distributed arrays. It estimates where the target might be based on the values in the array, narrowing the search more efficiently.
- **When to Use**:
  - The array is sorted and uniformly distributed (the values have a consistent range).
  - It is useful for finding elements quickly in arrays with evenly spaced values.
- **Hints**:
  - Uniform distribution is a strong signal; also, when elements in the array increase linearly, this may be faster than binary search.
- **Examples**:
  - Large datasets with evenly distributed values, where interpolation search can reduce steps.
