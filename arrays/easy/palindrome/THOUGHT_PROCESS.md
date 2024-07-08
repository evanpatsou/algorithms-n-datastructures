
# Thought process

### Naive Approach

**Initial Concept**:
To determine if an integer \( x \) is a palindrome, the simplest way is to convert the number into a string and check if the string reads the same forwards and backwards.

```
j = 0

if x < 0: return False

arr = str(x)

for i from 0 to 0:
    pal[j] = arr[i]
    j++ 

for i from 0 to N:
    if pal[i] != arr[i]: return false

return true
```

This approach involves extra space for the string representation of the number.

Time complexity: O(N)
Space complexity: O(N)

### Intermediate Approach

**Improvement Idea**:
- Instead of converting the integer to a string, we can reverse the integer itself and compare it with the original number.
 - This avoids the extra space used for the string.

Let's play with divs and mods:

```
121 // 10 = 1
121 % 10 = 12

12 // 10 = 2
12 %  10 = 1

put them in array

[ 1 , 2 , 1]


math.floor(math.log10(121)) = 2

for i -> math.floor(math.log10(121)) to 1:
    num += (x % 10) * (10 * i)
    x = x // 10


output should be:

x: 1221
-> math.floor(math.log10(1221)) = 3

i = 3:
(1221%10) * 1000 = 1 * 1000 = 1000
(122%10) * 100 = 2 * 100 = 200
(12%10) * 10 = 2 * 10 = 20
1


Without log:

loop1:
1234 %  10 = 4
1234 // 10 = 123
reverse = 10 * 0 + 1 = 1

loop2:
123 %  10 = 3
123 // 10 = 12
reverse = 10 * 4 + 3 = 43

loop3:
12 %  10 = 2
12 // 10 = 1
reverse = 10 * 43 + 2 = 432

loop4:
1 %  10 = 1
1 // 10 = 0
reverse = 10 * 432 + 1 = 4321
```


### Optimized Approach

Instead of reversing the entire number, we only reverse the second half of the number. This allows us to compare the first half and the reversed second half directly, making it more efficient and avoiding overflow issues.

```
loop1:
1234 > 0 = True
--
1234 %  10 = 4
1234 // 10 = 123
--
reverse = 10 * 0 + 1 = 1


loop2:
123 > 4 = True
--
123 %  10 = 3
123 // 10 = 12
--
reverse = 10 * 4 + 3 = 43

loop3:
12 > 43 = False

loop4:
1 %  10 = 1
1 // 10 = 0
12 == 43 --> False.
```