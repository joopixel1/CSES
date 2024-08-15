# Array

## Array

### Ideas For Problems
- Two Pointer Technique: Two pointers is really an easy and effective technique that is typically used for searching pairs in a sorted array. Eg find a pair that sum to a K. even comes in handy in triple sum to a K.
- Sorting: 
    Sorting is the process of rearranging elements in an array or list according to a comparison operator. This is crucial for making data easier to manage and search, especially when dealing with large, unordered datasets.Sorting algorithms can be broadly classified into two types:
    1. **Comparison-based Sorting:** Algorithms that sort data by comparing elements.
    2. **Non-comparison-based Sorting:** Algorithms that sort data without direct comparisons between elements.

    #### Common Sorting Algorithms
    1. Selection Sort: Selection Sort works by repeatedly finding the minimum element from an unsorted subarray and moving it to the beginning. It divides the array into a sorted and an unsorted subarray.

    2. Bubble Sort: Bubble Sort repeatedly swaps adjacent elements if they are in the wrong order. It is simple but inefficient for large datasets due to its high time complexity.

    3. Insertion Sort: Insertion Sort is similar to sorting playing cards. The array is divided into a sorted and an unsorted part, and elements from the unsorted part are inserted into their correct position in the sorted part.

    4. Merge Sort: Merge Sort is a divide-and-conquer algorithm that splits the array into two halves, sorts them recursively, and then merges them into a sorted array.

    5. Quick Sort: Quick Sort also follows the divide-and-conquer approach. It selects a pivot element and partitions the array into subarrays, sorting them recursively.

    6. Heap Sort: Heap Sort is a comparison-based algorithm that uses a binary heap data structure. It transforms the array into a max heap and then repeatedly extracts the maximum element.

    7. Counting Sort: Counting Sort is a non-comparative algorithm that counts the occurrences of each element to determine their position in the sorted array.
- Searching
    - Linear [O(n)]: inear search is the simplest search algorithm that checks each element in a list sequentially until the desired element is found or the list ends. It has a time complexity of \(O(n)\) because, in the worst case, it needs to check every element.

    - Divide and Conquer and Recursion Methods [O(log n)]: 
        - Binary Search: inary search works on a sorted array by repeatedly dividing the search interval in half. If the value of the target is less than the middle element, the search continues in the lower half; otherwise, it continues in the upper half. It has a time complexity of O(logn).
        - Ternary Search: Similar to binary search but divides the array into three parts instead of two. It checks two mid-points and determines which section to continue searching in. It also has a time complexity of O(logn).
        - Fibonnacci Search: This search technique uses Fibonacci numbers to divide the array into sections. It has a similar performance to binary search but can be more efficient in specific scenarios where the data is uniformly distributed.
        - Interpolation Search: An improved variant of binary search for instances where the values in a sorted array are uniformly distributed. It attempts to predict the position of the target using linear interpolation. The average time complexity is O(loglogn), but in the worst case, it can degrade to O(n).

    - MultiStep Methods: 
        - Jump Search: Jump search works on sorted arrays by jumping ahead by fixed steps and then performing a linear search in the identified block. It balances the linear and binary search, offering a time complexity of O(root(n)).
        - Exponential Search: This search algorithm works by first finding a range where the target might be located and then performing a binary search within that range. It has a time complexity of O(logn), and it is particularly effective when dealing with unbounded or very large arrays.
- DP:
    - Essentially, it is a simple idea, after solving a problem with a given input, save the result as a reference for future use, so you won’t have to re-solve it.. briefly ‘Remember your Past’ :). 
    - It is a big hint for DP if the given problem can be broken up into smaller sub-problems, and these smaller subproblems can be divided into still smaller ones, and in this process, you see some overlapping subproblems. 
    - Additionally, the optimal solutions to the subproblems contribute to the optimal solution of the given problem (referred to as the Optimal Substructure Property).
    - The solutions to the subproblems are stored in a table or array (memoization) or in a bottom-up manner (tabulation) to avoid redundant computation.
    - The solution to the problem can be constructed from the solutions to the subproblems.
    - Dynamic programming can be implemented using a recursive algorithm, where the solutions to subproblems are found recursively, or using an iterative algorithm, where the solutions are found by working through the subproblems in a specific order.

    Techniques to solve Dynamic Programming Problems:
    1. Top-Down(Memoization): Break down the given problem in order to begin solving it. If you see that the problem has already been solved, return the saved answer. If it hasn’t been solved, solve it and save it. This is usually easy to think of and very intuitive, This is referred to as Memoization.

    2. Bottom-Up(Tabulation): Analyze the problem and see in what order the subproblems are solved, and work your way up from the trivial subproblem to the given problem. This process ensures that the subproblems are solved before the main problem. This is referred to as Dynamic Programming.

    How to classify a problem as a Dynamic Programming algorithm Problem?
    1. Typically, all the problems that require maximizing or minimizing certain quantities or counting problems that say to count the arrangements under certain conditions or certain probability problems can be solved by using Dynamic Programming.
    2. All dynamic programming problems satisfy the overlapping subproblems property and most of the classic Dynamic programming problems also satisfy the optimal substructure property. Once we observe these properties in a given problem be sure that it can be solved using Dynamic Programming.
- Recursion:
    - There are two types of cases in recursion i.e. recursive case and a base case.
    - The base case is used to terminate the recursive function when the case turns out to be true.
    - Each recursive call makes a new copy of that method in the stack memory.
    - Examples of Recursive algorithms: Merge Sort, Quick Sort, Tower of Hanoi, Fibonacci Series, Factorial Problem, etc.
    - Tail recursion is better optimized by compiler than non-tail compilation.
- Greedy:
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





