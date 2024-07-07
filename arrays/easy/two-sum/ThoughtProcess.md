# Thought Process

Things to keep in mind: Therre only one solution.

Target: 9

Naive solution:

2  11  0 7 15 
|   |         ---> 13

2  11  0 7 15 
|      |      ---> 2

2  11  0 7 15 
|        |    ---> 9, Then solution is 0, 3.


for i: 0 to N
    for j: 0 to N
        if i different to j
            if sum meet the target then return i, j


Time Complexity: O(n^2), 
Space Complexity: O(1)

Take 2:

Next step is to see if we can do something with the properties of the array. The array is unsorted. If we sort the array the best we could to will be nlogn. 

2  11  0 7 15 

We sort the array and we search inwards:
0 2 7 11 15
|->     <-|

if i + j element is 15 > 9: then we know we need to lower the sum, hence decrease the right index.

if i + j element is 5 < 9: then we know that we need to increase the sum hence we need to increase the left index.

if i > j then we know that the target can not be meet.

if we find the target before that then we return the indexes.

Time complexity:

Sorting O(nlogn) + Searching O(n) = O(nlogn)

Take 3:

Lets take a look to our example to see if we can do something better. 

2  11  0 7 15 

For element 2 to the complementary: 7
For element 11 to the complementary: -3
For element 0 to the complementary: 9
For element 7 to the complementary: 2
For element 15 to the complementary: -6

so we can build a hashmap:

loop1:
2  11  0 7 15 
|

7 doesnt appear to hashmap then hash put 7 as key and index of 2 as value.

hash: 
[7] : index 0

loop2:
2  11  0 7 15 
    |

hash: [7] : index 0, [-3]: index 1

loop3:
2  11  0 7 15 
       |

hash:
[7] : index 0
[-3]: index 1
[9]: index 2

loop4:
2  11  0 7 15 
         |

hash:
[7] : index 0 <--- 7 appears to hashmap then we can return 0, curr idx
[-3]: index 1
[9]: index 2