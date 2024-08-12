# Array

## Array

### Ideas For Problems
- Two Pointer Technique: Two pointers is really an easy and effective technique that is typically used for searching pairs in a sorted array. Eg find a pair that sum to a K. even comes in handy in triple sum to a K.
- Sorting
- Searching
- DP
- Greedy
- Data Structures
- Summing


## Subarray
A subarray is a contiguous part of an array. It is essentially a slice from the array, meaning that all the elements in the subarray are in the same order as in the original array and are contiguous.

### Properties
- **Number of Subarrays** - The number of subarrays in an array of length \( n \) is given by the formula:
\[ \frac{n(n+1)}{2} \]

### Ideas for problems
- Summing:
    storing past sums in list, maps, sets. Its really tricky. Think about it. A common solution is turning an array into a binary array and calculating toatal subarrays that sum to K.
- SLiding Window: Sliding Window
    The sliding window technique is a powerful method used to solve array or list problems by maintaining a window that slides over the array to examine subarrays or sublists. It is especially useful for problems involving finding a subarray that meets specific criteria, such as a maximum sum or a minimum length. The secret of the sliding window technique is that the sum or window factor should increase when you increase the length of the window and should decrease when reducing the length of the window. This can make it tricky in certain types of arrays where managing these changes effectively is challenging. By efficiently moving the window and updating the relevant values, the sliding window technique helps optimize the solution and reduces time complexity compared to a naive approach.
    You can also simplify complex arrays or problems by converting the array or problem to a simpler problem that can be solved using Sliding WIndow.
- Reversing
- Sorting
- Data Structures: Use of a lot of varying data structure and ideas can come handy in some tricky questiona.


## Subsequence
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

### Properties
- **Number of Subsequences** - The number of subsequences in an array of length \( n \) is given by the formula:
\[ 2^n \] . This includes the empty subsequence.

### Ideas
- Summing
- Recursion i.e getting all possible subsequences
- Data Structures: we use a lot of varying data structure and ideas as questions invlolving subsequences are very diverse.
- Dynamic Programming: eg Longest common subsequence between two arrays - arr[n][m].
- Greedy Algorithms (while loop): 
     greedy algorithm is a problem-solving strategy that makes a series of choices, each of which looks the best at the moment. The idea is to build up a solution piece by piece, always choosing the next piece that offers the most immediate benefit (i.e., the "greediest" choice), with the hope that these local optimizations will lead to a globally optimal solution.
     When to Use Greedy Algorithms: Greedy algorithms work well when a problem exhibits the greedy-choice property and optimal substructure:
    - Greedy-Choice Property: This means that a locally optimal choice at each step leads to a globally optimal solution. If this property holds, then a greedy algorithm can solve the problem optimally.
    - Optimal Substructure: This means that the problem can be broken down into smaller subproblems, and the optimal solution to the problem can be constructed from optimal solutions to these subproblems.





