// https://projecteuler.net/problem=79
// Passcode Derivation
//
// A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.
//
// The text file, keylog.txt, contains fifty successful login attempts.
//
// Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.
//
// Answer: 73162890

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>

std::string passcode_derivation()
{
    std::ifstream file("keylog.txt");
    std::vector<std::string> logs;
    std::string line;
    while (std::getline(file, line)) {
        if (line.size() == 3) logs.push_back(line);
    }
    std::vector<std::set<int>> graph(10);
    std::vector<int> indegree(10, 0);
    std::set<int> digits;
    for (const auto& log : logs) {
        int a = log[0] - '0', b = log[1] - '0', c = log[2] - '0';
        digits.insert(a);
        digits.insert(b);
        digits.insert(c);
        if (graph[a].find(b) == graph[a].end()) {
            graph[a].insert(b);
            ++indegree[b];
        }
        if (graph[b].find(c) == graph[b].end()) {
            graph[b].insert(c);
            ++indegree[c];
        }
    }
    std::queue<int> q;
    for (int d : digits) {
        if (indegree[d] == 0) q.push(d);
    }
    std::string passcode;
    while (!q.empty()) {
        int d = q.front(); q.pop();
        passcode += '0' + d;
        for (int next : graph[d]) {
            --indegree[next];
            if (indegree[next] == 0) q.push(next);
        }
    }
    return passcode;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << passcode_derivation() << std::endl;
}
#endif