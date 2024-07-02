#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/**-----------------------------------------------------------------------------------------------------------------------
 * *                                DETAILS
 * Given an array of n numbers, our task is to calculate the maximum subarray sum, 
 * i.e., the largest possible sum of a sequence of consecutive values in the array. 
 * The problem is interesting when there may be negative values in the array.
 *   
 * *                                SOLUTION: INDUCTION
 * Suprisingly an o(n) solution exists when you begin to think of things in INDUCTION.
 * The idea is to calculate, for each array position, the maximum sumof a subarray that ends at that position. 
 * After this, the answer for the problem is the maximum of those sums.
 * Consider the subproblem of finding the maximum-sum subarray that ends at position k. There are two possibilities:
 * 1. The subarray only contains the element at position k.
 * 2. The subarray consists of a subarray that ends at position k 1, followed by the element at position k.
 *  In the latter case, since we want to find a subarray with maximum sum, 
 * the subarray that ends at position k 1 should also have the maximum sum. 
 * Thus, we can solve the problem efficiently by calculating the maximum subarray sum for each ending position from left to right.
 *
 *-----------------------------------------------------------------------------------------------------------------------**/
int max_subarray_sum(vector<int> list){
    int best = 0, max_sum = 0;
    for(int i=0; i<list.size(); i++){
        max_sum = max(list[i], list[i] + max_sum);
        best = max(max_sum, best);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
        
    cout << "Starting..." << "\n";

    vector<int> list;
    cout << max_subarray_sum(list);
 
    return (0);
}
