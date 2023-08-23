# Rearrange an Array to Separate Positive and Negative Numbers

### Problem Statement:

You are given an array of integers, which may contain both positive and negative numbers. Your task is to rearrange the array in such a way that:

1. All negative numbers appear on the left side.
2. All positive numbers appear on the right side.
3. The order of appearance should remain unchanged.

### Input:
An array of integers.

### Output:
A rearranged array of integers.

### Constraints:

- The array length, \( n \), is such that \( 1 \leq n \leq 10^5 \).
- The integers in the array are such that \( -10^9 \leq \text{integer} \leq 10^9 \).

### Example:

**Input:**  
\[ 1, -3, 2, -4, 5, -6 \]

**Output:**  
\[ -3, -4, -6, 1, 2, 5 \]

**Note:** 
The order of negative numbers (-3, -4, -6) remains unchanged, and so does the order of positive numbers (1, 2, 5).
