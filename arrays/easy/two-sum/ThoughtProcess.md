# Thought Process

### Things to keep in mind: There is only one solution.

### Target: 9

#### Naive Solution:

Given Array: `[2, 11, 0, 7, 15]`

- Compare `2` and `11` → Sum is `13`
- Compare `2` and `0` → Sum is `2`
- Compare `2` and `7` → Sum is `9` (Solution found: indices `0`, `3`)

```python
for i in range(len(nums)):
    for j in range(len(nums)):
        if i != j:
            if nums[i] + nums[j] == target:
                return [i, j]
```

**Time Complexity:** O(n^2)  
**Space Complexity:** O(1)

#### Take 2:

Next step is to see if we can do something with the properties of the array. The array is unsorted. If we sort the array the best we could do will be nlogn.

Given Array: `[2, 11, 0, 7, 15]`

We sort the array and search inwards: `[0, 2, 7, 11, 15]`

- If the sum of the elements at the two pointers is greater than `9`, decrease the right pointer.
- If the sum of the elements at the two pointers is less than `9`, increase the left pointer.
- If the pointers cross, the target cannot be met.
- If the target is found before the pointers cross, return the indices.

**Time Complexity:** Sorting O(n log n) + Searching O(n) = O(n log n)

#### Take 3:

Let's take a look at our example to see if we can do something better.

Given Array: `[2, 11, 0, 7, 15]`

For each element, calculate the complement:
- For element `2`, the complement is `7`
- For element `11`, the complement is `-2`
- For element `0`, the complement is `9`
- For element `7`, the complement is `2`
- For element `15`, the complement is `-6`

We can build a hashmap to store complements:

1. Loop 1:
   - Array: `[2, 11, 0, 7, 15]`
   - `7` doesn't appear in the hashmap, so add `7` as key and index of `2` as value.
   - Hashmap: `{7: 0}`

2. Loop 2:
   - Array: `[2, 11, 0, 7, 15]`
   - `-2` doesn't appear in the hashmap, so add `-2` as key and index of `11` as value.
   - Hashmap: `{7: 0, -2: 1}`

3. Loop 3:
   - Array: `[2, 11, 0, 7, 15]`
   - `9` doesn't appear in the hashmap, so add `9` as key and index of `0` as value.
   - Hashmap: `{7: 0, -2: 1, 9: 2}`

4. Loop 4:
   - Array: `[2, 11, 0, 7, 15]`
   - `2` appears in the hashmap, so we can return the indices `0` and the current index.

**Time Complexity:** O(n) as we traverse the array once
**Space Complexity:** O(n) as we update a hashmap of size n.