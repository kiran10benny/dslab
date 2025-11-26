from palindrome import ispalindrome

def longest_palindrome(s):
    n = len(s)
    longest = ""

    for i in range(n):
        for j in range(i + 1, n + 1):
            substring = s[i:j]
            if ispalindrome(substring) and len(substring) > len(longest):
                longest = substring

    return longest


data = input("Enter the text: ")
print("Longest palindromic substring:", longest_palindrome(data))
