bool isPalindrome(int x) {
    // Negative numbers and numbers ending in 0 (except 0 itself) are not palindromes
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;

    unsigned int reverse = 0;
    // Reverse the second half of the number
    while(x > reverse) {
        reverse = (reverse * 10) + (x % 10);
        x /=  10; 
    }

    // Check if the number is a palindrome
    return x == reverse || x == reverse / 10;
}