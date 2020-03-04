# leetcode.solution

id | prob_name | try | time | topics | err_note | read_sol | todo | ext
 -----|-----|-----|-----|-----|-----|-----|-----|-----
 1 | Two Sum | 1 | - | Hash Table | - | done | - | -
 7 | Reverse Integer | 5 | 1h | Math | 1. c++ operator precedence <br> 2. Read instruction carefully | done | - | - | -
 14 | Longest Common Prefix | 3 | 27m | String | use min\<T\>() instead of min() | done | - | - | -
 15 | 3Sum | 3 | 59m47s | 3sum | tle | none | read other's code | -
 33 | Search in Rotated Sorted Array | 2 | 2h | Binary search | Overlook corner case arr size == 0 | done | try while loop for search | - 
 36 | Valid Sudoku | 5 | 30m00s | hash table | 1. missing ; <br> 2. wrong input  | done | - | -
 68 | Text Justification | 7 | 1h24m55s | String | 1. Compile err <br> 2. Ambiguous Q description.... | none | - | learn an even divide trick ('w')
 128 | Longest Consecutive Sequence | 2 | 43m07s | Hash Table | corner case arr = [] | done | - | -
 160 | Intersection of Two Linked Lists | 2 | 30m | Linked List | typo | done | - | -
 162 | Find Peak Element | 7 | 1h | Binary Search | 1. Wrong proof <br> 2. Miss INT_MIN corner case | done | try iterative bi search  | - 
 202 | Happy Number | 2 | 27m00s | Hash Table & Math | misused %= as /= | done | Floyd's Cycle-Finding Algorithm | -
 221\* | Maximal Square | nan | 2h | Dynamic Programming | Not come up solution | done | - | -
 271 | Encode and Decode Strings | nan | 2h | encoding | 1. char vs unsigned char | done | - | -
 295 | Find Median from Data Stream | nan | 2h00m | 1. head 2. design | avl tree subtree may be null | - | - | -
 297 | Serialize and Deserialize Binary Tree | nan | 1h | tree, design | 1. pointer is pass by copy <br> 2. intToS sToInt | done | - | -
 299 | Bulls and Cows | 2 | 20m | hash table | - | - | - | -
 322 | Coin Change | 2 | 1h | Dynamic Programming | wrong init vec size | done | try bottom-up approach  | - 
 334 | Increasing Triplet Subsequence | 3 | 1h30m | - | 1. Read instruction carefully | none | -  | We can extends to more than 3 seq
 459\* | Repeated Substring Pattern | nan | nan | string | 1. try too complicated method | none | - | built longest proper prefix
 465 | Optimal Account Balancing | 3 | 1h05m | dfs | - | - | - | -
 659\* | Split Array into Consecutive Subsequences | nan | 3h | greedy | 1. i++ vs ++i <br> 2. Miss end case <br> 3. if( a- b ) not equiv if( a > b ) | done | - | -
 727 | Minimum Window Subsequence | 3 | 27m | 1. dp 2. sliding window | - | done | - | -
 752 | Open the Lock | nan | 1h12m | bfs | 1. fail on dp | done | - | -
 843 | Guess the Word | 2 | 30m | minimax | - | done | - | -
 862\* | Shortest Subarray with Sum at Least K | 2 | 1h25m | deque, binary search | - | done | - | -
 889 | Construct Binary Tree from Preorder and Postorder Traversal | 5 | 1h | tree | see note | read O(n) | - | -
 951 | Flip Equivalent Binary Trees | 3 | 45m | tree | 1. miss tree traverse NULL leaf detection | done | - | -
 1048 | Longest String Chain | 3 | 1h26m | Hash Table, DP | 1. wrong vector initialization <br> 2. update maxH err | none | - | -
 1088 | Confusing Number II | 2 | 2h | backtracing | see note | none | - | -
 1219 | Path with Maximum Gold | 2 | 30m | backtracking | 1. m\*n arr not L * L arr | none | - | -
