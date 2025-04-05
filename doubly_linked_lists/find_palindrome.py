def is_palindrome(n):
    return str(n) == str(n)[::-1]

max_palindrome = 0

for i in range(999, 99, -1):
    for j in range(i, 99, -1):
        product = i * j
        if is_palindrome(product) and product > max_palindrome:
            max_palindrome = product

with open("102-result", "w") as f:
    f.write(str(max_palindrome))

