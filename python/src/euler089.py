# Problem 89: Roman numerals
# The file contains 1000 numbers written in valid, but not necessarily minimal, Roman numerals.
# Find the number of characters saved by writing each of these in their minimal form.
# Answer: 743
# Execution time: ~1ms on modern hardware
# Optimizations: Use dictionary for roman to int and int to roman
# Interesting notes: AI-generated solution converting roman numerals

def roman_to_int(s):
    roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
    total = 0
    prev = 0
    for c in reversed(s):
        val = roman[c]
        if val < prev:
            total -= val
        else:
            total += val
        prev = val
    return total

def int_to_roman(n):
    val = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
    sym = ['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
    roman = ''
    i = 0
    while n > 0:
        for _ in range(n // val[i]):
            roman += sym[i]
            n -= val[i]
        i += 1
    return roman

def solve():
    saved = 0
    with open('../cpp/src/p089_roman.txt') as f:
        for line in f:
            line = line.strip()
            num = roman_to_int(line)
            minimal = int_to_roman(num)
            saved += len(line) - len(minimal)
    return saved

if __name__ == "__main__":
    print(solve())