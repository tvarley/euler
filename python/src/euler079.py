# Problem 79: Passcode Derivation
# A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.
# The text file, keylog.txt, contains fifty successful login attempts.
# Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.
# Answer: 73162890
# Execution time: ~1ms on modern hardware
# Optimizations: Build graph from constraints, topological sort
# Interesting notes: AI-generated solution using graph to find the order

def solve():
    from collections import defaultdict
    with open('data/0079_keylog.txt') as f:
        attempts = [line.strip() for line in f]
    graph = defaultdict(list)
    nodes = set()
    for att in attempts:
        a, b, c = att
        nodes.add(a)
        nodes.add(b)
        nodes.add(c)
        graph[a].append(b)
        graph[b].append(c)
    # Now, topological sort using DFS
    visited = set()
    temp = set()
    result = []
    def dfs(node):
        if node in temp:
            return  # cycle
        if node in visited:
            return
        temp.add(node)
        for neigh in graph[node]:
            dfs(neigh)
        temp.remove(node)
        visited.add(node)
        result.append(node)
    for node in sorted(nodes):
        if node not in visited:
            dfs(node)
    result.reverse()
    return int(''.join(result))

if __name__ == "__main__":
    print(solve())