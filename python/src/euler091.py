# Problem 91: Right triangles with integer coordinates
# The points P (x1, y1) and Q (x2, y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.
# There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between 0 and 2 inclusive; i.e., 0 ≤ x1, y1, x2, y2 ≤ 2.
# Find how many such triangles exist when each co-ordinate lies between 0 and 50 inclusive.
# Answer: 14234
# Execution time: ~1000ms on modern hardware
# Optimizations: Loop over points with symmetry
# Interesting notes: AI-generated solution counting right triangles

def gcd(a, b):
    while a:
        a, b = b % a, a
    return b

def solve():
    size = 50
    result = 3 * size * size
    for px in range(1, size + 1):
        for py in range(1, px + 1):
            factor = gcd(px, py)
            dx = px // factor
            dy = py // factor
            found = 0
            # Q below P
            qx = px - dy
            qy = py + dx
            while qx >= 0 and qy <= size:
                found += 1
                qx -= dy
                qy += dx
            # Q above P
            qx = px + dy
            qy = py - dx
            while qy >= 0 and qx <= size:
                found += 1
                qx += dy
                qy -= dx
            if px != py:
                found *= 2
            result += found
    return result

if __name__ == "__main__":
    print(solve())