import os


def solve():
    """
    Names scores
    Using names.txt, a 46K text file containing over five-thousand first names,
    begin by sorting it into alphabetical order. Then working out the alphabetical
    value for each name, multiply this value by its alphabetical position in the list
    to obtain a name score.
    For example, when the list is sorted into alphabetical order, COLIN, which is worth
    3 + 15 + 12 + 9 + 14 = 53, is the 522nd name in the list. So, COLIN would obtain
    a score of 522 × 53 = 27736.
    What is the total of all the name scores in the file?
    https://projecteuler.net/problem=22
    """
    data_path = os.path.join(os.path.dirname(__file__), '..', 'data', 'p022_names.txt')
    with open(data_path) as f:
        names = sorted(name.strip('"') for name in f.read().split(','))

    total = 0
    for i, name in enumerate(names, 1):
        score = sum(ord(c) - ord('A') + 1 for c in name)
        total += i * score
    return total
