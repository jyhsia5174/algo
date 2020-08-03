# leetcode.solution

id | prob_name | try | time | topics | err_note | read_sol | todo | ext
 -----|-----|-----|-----|-----|-----|-----|-----|-----
 1 | Two Sum | 1 | - | Hash Table | - | done | - | -
 7 | Reverse Integer | 5 | 1h | Math | 1. c++ operator precedence <br> 2. Read instruction carefully | done | - | - | -
 14 | Longest Common Prefix | 3 | 27m | String | use min\<T\>() instead of min() | done | - | - | -
 15 | 3Sum | 3 | 59m | 3sum | tle | none | read other's code | -
 33 | Search in Rotated Sorted Array | 2 | 2h | Binary search | Overlook corner case arr size == 0 | done | try while loop for search | - 
 36 | Valid Sudoku | 5 | 30m | hash table | 1. missing ; <br> 2. wrong input  | done | - | -
 68 | Text Justification | 7 | 1h24m | String | 1. Compile err <br> 2. Ambiguous Q description.... | none | - | learn an even divide trick ('w')
 128 | Longest Consecutive Sequence | 2 | 43m | Hash Table | corner case arr = [] | done | - | -
 160 | Intersection of Two Linked Lists | 2 | 30m | Linked List | typo | done | - | -
 162 | Find Peak Element | 7 | 1h | Binary Search | 1. Wrong proof <br> 2. Miss INT_MIN corner case | done | try iterative bi search  | - 
 202 | Happy Number | 2 | 27m | Hash Table & Math | misused %= as /= | done | Floyd's Cycle-Finding Algorithm | -
 221\* | Maximal Square | nan | 2h | Dynamic Programming | Not come up solution | done | - | -
 222 | Count Complete Tree Nodes | 2 | 30m | 1. binary search <br> 2. tree | - | done | - | -
 271 | Encode and Decode Strings | nan | 2h | encoding | 1. char vs unsigned char | done | - | -
 295 | Find Median from Data Stream | nan | 2h00m | 1. head 2. design | avl tree subtree may be null | - | - | -
 297 | Serialize and Deserialize Binary Tree | nan | 1h | tree, design | 1. pointer is pass by copy <br> 2. intToS sToInt | done | - | -
 299 | Bulls and Cows | 2 | 20m | hash table | - | - | - | -
 322 | Coin Change | 2 | 1h | Dynamic Programming | wrong init vec size | done | try bottom-up approach  | - 
 329 | Longest Increasing Path in a Matrix | 5 | 45m | dfs, topological sort, memorization | 1. Class does not support pass ref object to member object. 2. Invalid array access | done | DP (Peeling Onion) | -
 334 | Increasing Triplet Subsequence | 3 | 1h30m | - | 1. Read instruction carefully | none | -  | We can extends to more than 3 seq
 336 | Palindrome Pairs | nan | 1h | string | missing cases | done | try trie tree | -
 359 | Logger Rate Limiter | 3 | 45min | 1. hash table <br> 2. design | 1. priority queue use "push" <br> 2. class mycmp{ bool operator()() const {}} | done | - | -
 362 | Design Hit Counter | nan | ?? | Design | array indexing | none | - | -
 459\* | Repeated Substring Pattern | nan | nan | string | 1. try too complicated method | none | - | built longest proper prefix
 465 | Optimal Account Balancing | 3 | 1h05m | dfs | - | - | - | -
 489 | Robot Room Cleaner | 1 | 1h | dfs | - | done | - | -
 552 | Student Attendance Record II | 5 | 1h30m | dp | 1. miss understand Q | - | - | -
 659\* | Split Array into Consecutive Subsequences | nan | 3h | greedy | 1. i++ vs ++i <br> 2. Miss end case <br> 3. if( a- b ) not equiv if( a > b ) | done | - | -
 727 | Minimum Window Subsequence | 3 | 27m | 1. dp 2. sliding window | - | done | - | -
 752 | Open the Lock | nan | 1h12m | bfs | 1. fail on dp | done | - | two-end bfs speed up
 767 | Reorganize String | nan | 1h30m | 1. greedy 2. string | no idea | done | - | -
 809 | Expressive Words | 1 | 30m | string | 1. vector use push_back... | done | try 2 pointer | -
 833 | Find And Replace in String | 2 | 30m | string | index update rule miss | done | - | -
 843 | Guess the Word | 2 | 30m | minimax | - | done | - | -
 862\* | Shortest Subarray with Sum at Least K | 2 | 1h25m | deque, binary search | - | done | - | -
 889 | Construct Binary Tree from Preorder and Postorder Traversal | 5 | 1h | tree | see note | read O(n) | - | -
 951 | Flip Equivalent Binary Trees | 3 | 45m | tree | 1. miss tree traverse NULL leaf detection | done | - | -
 1007 | Minimum Domino Rotations For Equal Row | 3 | 25m | greedy | 1. miss the Q requirement | done | - | -
 1031\* | Maximum Sum of Two Non-Overlapping Subarrays | nan | 3h | array | 1. segmentation tree implementation 2. indexing array | done | - | -
 1032\* | Stream of Characters | nan | nan | ac automaton | - | - | - | -
 1110 | Delete Nodes And Return Forest | 1 | 1h | dfs | none | none | - | -
 1048 | Longest String Chain | 3 | 1h26m | Hash Table, DP | 1. wrong vector initialization <br> 2. update maxH err | none | - | -
 1074\* | Number of Submatrices That Sum to Target | 3 | 1h | dp | tle | none | - | -
 1088 | Confusing Number II | 2 | 2h | backtracing | see note | none | - | -
 1146\* | Snapshot Array | nan | nan | ? | 1. don't use memset .... 2. begin case | none | - | -
 1197\* | Minimum Knight Moves | nan | 2h | bfs | 1. time limited exceeded 2. unordered_map does not support pair 3. miss 0,0 case | none | - | -
 1219 | Path with Maximum Gold | 2 | 30m | backtracking | 1. m\*n arr not L * L arr | none | - | -
 1231 | Divide Chocolate | 2 | 1h | 1. binary search 2. greedy | iterative biseach implementation err | - | - | -
375 | Guess Number Higher or Lower II | nan | 1h20m | dp | 1. wrong thinking direction. | done | - | -
1438 | Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit | 4 | 45min | 1. array 2. sliding window | 1. empty map access  | done | try deque | - 
 743 | Network Delay Time | 3 | 22m | Dijkstra's algorithm | 1. forget init original cost to zero. | done | - | -
 76\* | Minimum Window Substring | 3 | 45m | 1. two pointer 2. hash table | Not familiar with hash tricks. | done | do more hash problems | -
 560 | Subarray Sum Equals K | 2 | 20m | 1. hash table | indexing error | done | - | -
 253 | Meeting Rooms II | 2 | 20m | interval overlap count | 1. input array may be empty | done | - | -
 846 | Hand of Straights | 2 | 15m | 1. ordered map | 1. map.begin()->first 2. map.find() | done | - | -
 1296 | Divide Array in Sets of K Consecutive Numbers (same as 846) | 2 | 15m | 1. ordered map | 1. map.begin()->first 2. map.find() | done | - | -
 1140\* | Stone Game II | nan | nan | dp | - | - | do more dp | -
 346 | Moving Average from Data Stream | 1 | 7m | queue | - | done | - | -
 946 | Validate Stack Sequences | 2 | 15m | stack | 1. miss stack is empty case. | done | - | -
 679\* | 24 Game | nan | 1h25m | dfs | - | done | 1. do more permutation problem | -
 410\* | Split Array Largest Sum | nan | 45m | dp or bisearch | infinite bisearch loop | done | list all some invalid bisearch case | -
 315\* | Count of Smaller Numbers After Self | nan | nan | merge sort with status | do not have sol | done | done | done
 1153\* | String Transforms Into Another String | 4 | 1h15m | 1. graph 2. union set | 1. logic error (write down pseudo-code / double check pseudo code) | none | - | -
 1345 | Jump Game IV | nan | 1h | bfs | 1. Create unneccesary arry with length N | - | - | -
 593 | Valid Square | 2 | 20m | geometry | miss 0, 0, 0, 0 case | - | - | -
399 | Evaluate Division | 3 | 50m | dfs | 1. unordered_map using pair need its own hash function. | - | try using union_set method | -
394\* | Decode String | nan | 1h20m | parser | 1. Not clear about LL parser | - | - | -
85 | Maximal Rectangle | 2 | 40m | dp | 1. input data is a char not int value. | done | todo | ext
914 | X of a Kind in a Deck of Cards | 2 | 9m | 1. math (gcd) | map.begin()->second | done | - | -
1376 | Time Needed to Inform All Employees | nan | 20m | bfs | 1. access queue element after pop | - | - | -
1320\* | Minimum Distance to Type a Word Using Two Fingers| nan | 1h | dp | 1. matrix access before initialization | - | - | -
1060 | Missing Element in Sorted Array | 1 | 10m | binary search | - | done | - | -
270 | Closest Binary Search Tree Value| 2 | 20m | binary search tree traversal | type unmatched errer | done | - | -
301\* | Remove Invalid Parentheses | nan | nan | backtracing | unfamiliar with backtracing implementation | done | - | -
199 | Binary Tree Right Side View | 2 | 12m | 1. Tree 2. BFS | missing a case that root is NULL. | done | - | -
273 | Integer to English Words | 6 | 1h | Implementation | 1. string merge | done | - | -
23 | Merge k Sorted Lists | 4 | 30m | 1. merge sort | 1. logic error | done | - | -
67 | Add Binary | 2 | 16m | 1. math | 1. Forget to clear register after while loop | done | - | -
398 | Random Pick Index | 1 | 9m | reservoir sampling | - | none | - | -
269\* | Alien Dictionary | nan | 2h30m | 1. Graph 2. Topology sort | Not familiar with problem | done | - | -
88 | Merge Sorted Array | 1 | 12m | 1. two pointer | - | done | - | -
415 | Add Strings | 1 | 10m | 1. two pointer | - | done | - | -
124\* | Binary Tree Maximum Path Sum | nan | 1h40m | 1. tree 2. dfs | - | done | - | -
238 | Product of Array Except Self | 1 | 16m | 1. array | none | read_sol | todo | ext
953 | Verifying an Alien Dictionary | 3 | 14m | 1. hash table | sort cannot use non-static function as cmp | done | - | -
56 | Merge Intervals | 1 | 11m | 1. array 2. sort | none | done | todo | ext
1249 | Minimum Remove to Make Valid Parentheses | 1 | 11m | 1. stack 2. string | - | done | todo | ext
973 | K Closest Points to Origin | 2 | 11m | 1. divide and conqur 2. heap 3. sort | 1. priority_queue put largest first or lowest when greater<T> is applied. | done | todo | ext
31 | Next Permutation | 3 | 30m | 1. permutation | 1. binary search condition problem | done | todo | ext
215 | Kth Largest Element in an Array | 8 | 40m | 1. quick select or intro select algo | 1. partition function must return size >=1 | done | todo | ext
680 | Valid Palindrome II | 1 | 10m | 1. string | none | done | todo | ext
986 | Interval List Intersections| 3 | 20m | 1. two pointer | 1. logic error | done | todo | ext
236 | Lowest Common Ancestor of a Binary Tree | 1 | 18m | 1. tree 2. lca | none | done | todo | ext
173 | Binary Search Tree Iterator | 1 | 30m | 1. tree traversal using stack | none | done | todo | ext
543 | Diameter of Binary Tree | 3 | 10m | 1. tree | typing error | done | todo | ext
438 | Find All Anagrams in a String | 1 | 17m | hash table | none | done | todo | ext
187 | Repeated DNA Sequences| 3 | 10m | hash table | hash value reverse problem with 0 | done | todo | ext
987 | Vertical Order Traversal of a Binary Tree| 4 | 20m | hash_table | 1. misunderstand the Question | done | todo | ext
528 | Random Pick with Weight | 2 | 18m | 1. binary search | 1. binary search disign flawes | done | todo | ext
158 | Read N Characters Given Read4 II - Call multiple times | 1 | 15m | 1. string | none | none | todo | ext
125 | Valid Palindrome| 2 | 11m | 1. string | 1. miss nums cases | done | todo | ext
211 | Add and Search Word - Data structure design| 5 | 23m | trie | 1. never use i, j, k as var name...  | done | todo | ext
636\* | Exclusive Time of Functions | nan | 1h40m | stack | 1. string tokenizing | done | todo | ext
340 | Longest Substring with At Most K Distinct Characters| 5 | 25m | 1. string 2. hash table 3. two pointer | 1. while loop break condition has two type. | done | todo | ext
621\* | Task Scheduler | nan | 1h | 1. greedy | 1. no solution | done | todo | ext
278 | First Bad Version | 1 | 5m | 1. binary search | none | done | todo | ext
938 | Range Sum of BST | 1 | 6m | 1. tree traversal | none | done | todo | ext
523 | Continuous Subarray Sum| nan | 40m | dp | 1. miss corner case k == 0 and k is negative | done | todo | ext
785 | Is Graph Bipartite? | 3 | 36m | 1. disjoin set | none | done | todo | ext
311 | Sparse Matrix Multiplication | 3 | 17m | hash table | err_note | read_sol | todo | ext
282 | Expression Add Operators | nan | 1h | backtracing | do more backtracing problems | read_sol | todo | ext
249 | Group Shifted Strings | 5 | 40m | hash table | 1. Not familiar to built a hash linked table | read_sol | todo | ext
670 | Maximum Swap  | 10 | 40m | 1. array 2. math | 1. implementing priority queue failed | done | todo | ext
689\* | Maximum Sum of 3 Non-Overlapping Subarrays | nan | 1h23m | 1. array 2. dp | 1. indexing problems | done | todo | ext
1428 | Leftmost Column with at Least a One | 2 | 9m | 1. binary search | 1. while( l + 1 < r ) | done | todo | ext
896 | Monotonic Array | 1 | 4m | 1. array | none | done | todo | ext
1026 | Maximum Difference Between Node and Ancestor| 2 | 18m | 1. tree 2. dfs | 1. typing error | none | todo | ext
825 | Friends Of Appropriate Ages | 1 | 17m | 1. array | none | done | todo | ext
200 | Number of Islands | 1 | 14m | 1. dfs | none | done | todo | ext
2 | Add Two Numbers | 1 | 12m | 1. linked list | none | done | todo | ext
937 | Reorder Data in Log Files | nan | 29m | 1. string | 1. string::npos != s.size() 2. key conflict | done | todo | ext
146\* | LRU Cache | 10 | 35m | 1. link list 2. unordered_map | 1. not familiar with stl link list | done | todo | ext
42 | Trapping Rain Water | 2 | 33m | 1. array 2. two pointer 3. stack  | none | done | todo | ext
5 | Longest Palindromic Substring | 3 | 36m | 1. string | err_note | read_sol | todo | ext
21 | Merge Two Sorted Lists | 1 | 4m | 1. merge linked lists | none | done | todo | ext
1192 | Critical Connections in a Network | 10 | 1h17m | 1. tree 2. graph 3. Tarjan's algorithm | Graph traversal visits parent node | done | todo | ext
994 | Rotting Oranges | 1 | 12m | 1. bfs | none | done | todo | ext
121 | Best Time to Buy and Sell Stock | 1 | 5m | 1. array | none | done | todo | ext
692 | Top K Frequent Words | 5 | 25m | 1. nth largest element | nth_element does not sort kth largerst ones | done | todo | ext
763 | Partition Labels | 5 | 23m | 1. merge interval | 1. logic design error | done | todo | ext
49 | Group Anagrams | 3 | 7m | 1. string | none | done | todo | ext
380 | Insert Delete GetRandom O(1) | 3 | 20m | 1. design 2. hash table | 1. no idea | done | todo | ext
127 | Word Ladder | 10 | 1h | 1. bfs | 1. misunderstanding the target question in complexity  | done | todo | ext
588 | Design In-Memory File System | 5 | 1h37m | 1. string processing 2. design | Need to practice more string to tokens in C++ | done | todo | ext
140 | Word Break II | nan | 1h | 1. dp  | 1. string pre vs post construction. | done | todo | ext
239\* | Sliding Window Maximum | nan | 40m | 1. deque 2. dp | no idea of O(N) time | done | todo | ext
227\* | Basic Calculator II | 10 | 1h | 1. string tokenization | +* is left-to-right | done | todo | ext
819 | Most Common Word | 5 | 10m | 1. string processing 2. hash map | 1. tolower 2. after while loop I miss a update | done | todo | ext
460\* | LFU Cache | 10 | 55m | 1. design | too many | done | todo | ext
348 | Design Tic-Tac-Toe | 2 | 9m | 1. design | typing error | done | todo | ext
472 | Concatenated Words | 1 | 30m | 1. string 2. dfs | none | done | todo | ext
240\* | Search a 2D Matrix II | nan | 45m | 1. bi search 2. designed | 1. lower_bound val >= T upper_bound val > T | done | todo | ext
126 | Word Ladder II | 1 | 45m | 1. bfs | none | done | todo | ext
863\* | All Nodes Distance K in Binary Tree | 5 | 1h | 1. dfs 2. tree | 1. design flaws | done | todo | ext
815 | Bus Routes | 3 | 20m | 1. bfs | 1. typo | done | todo | ext
733 | Flood Fill | 1 | 9m| 1. bfs | none | done | todo | ext
909 | Snakes and Ladders | nan | 1h30m | 2. bfs | read problem carefully | done | todo | ext
| try | time | topics | err_note | read_sol | todo | ext
