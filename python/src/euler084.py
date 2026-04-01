# Problem 84: Monopoly Odds
# In the game, Monopoly, the standard board is set up in the following way:
# By starting at GO and numbering the squares sequentially from 00 to 39 we can concatenate these two-digit numbers to produce strings that correspond with sets of squares.
# Statistically it can be shown that the three most popular squares, in order, are JAIL (6.24%) = Square 10, E3 (3.18%) = Square 24, and GO (3.09%) = Square 00. So these three most popular squares can be listed with the six-digit modal string: 102400.
# If, instead of using two 6-sided dice, two 4-sided dice are used, find the six-digit modal string.
# Answer: 101524
# Execution time: ~1000ms on modern hardware
# Optimizations: Markov chain simulation for board probabilities
# Interesting notes: AI-generated solution modeling Monopoly with 4-sided dice

def solve():
    import random
    random.seed(42)  # for reproducibility
    board = list(range(40))
    cc = ['GO', 'JAIL'] + [''] * 14
    ch = ['GO', 'JAIL', 'C1', 'E3', 'H2', 'R1', 'nextR', 'nextR', 'nextU', 'back3'] + [''] * 6
    random.shuffle(cc)
    random.shuffle(ch)
    cc_idx = 0
    ch_idx = 0
    counts = [0] * 40
    doubles = 0
    pos = 0
    for _ in range(10**6):
        d1 = random.randint(1, 4)
        d2 = random.randint(1, 4)
        roll = d1 + d2
        if d1 == d2:
            doubles += 1
        else:
            doubles = 0
        if doubles == 3:
            pos = 10
            doubles = 0
        else:
            pos = (pos + roll) % 40
            if pos == 30:
                pos = 10
            elif pos in [2, 17, 33]:
                card = cc[cc_idx % 16]
                cc_idx += 1
                if card == 'GO':
                    pos = 0
                elif card == 'JAIL':
                    pos = 10
            elif pos in [7, 22, 36]:
                card = ch[ch_idx % 16]
                ch_idx += 1
                if card == 'GO':
                    pos = 0
                elif card == 'JAIL':
                    pos = 10
                elif card == 'C1':
                    pos = 11
                elif card == 'E3':
                    pos = 24
                elif card == 'H2':
                    pos = 39
                elif card == 'R1':
                    pos = 5
                elif card == 'nextR':
                    if pos < 5:
                        pos = 5
                    elif pos < 15:
                        pos = 15
                    elif pos < 25:
                        pos = 25
                    elif pos < 35:
                        pos = 35
                    else:
                        pos = 5
                elif card == 'nextU':
                    if pos < 12:
                        pos = 12
                    elif pos < 28:
                        pos = 28
                    else:
                        pos = 12
                elif card == 'back3':
                    pos -= 3
        counts[pos] += 1
    top3 = sorted(enumerate(counts), key=lambda x: x[1], reverse=True)[:3]
    return int(''.join(f'{i:02d}' for i, _ in top3))