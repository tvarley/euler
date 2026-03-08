#!/bin/bash

# test_all.sh - Run tests for all Project Euler solutions across all languages

set -e  # Exit on any error

echo "=== Running Project Euler Tests ==="
echo

# Function to run tests for a language
run_tests() {
    local lang=$1
    local cmd=$2
    echo "Running $lang tests..."
    if cd "$lang" && eval "$cmd"; then
        echo "✓ $lang tests passed"
    else
        echo "✗ $lang tests failed"
        return 1
    fi
    cd ..
    echo
}

# C++
run_tests "cpp" "make bin/unittest && ./bin/unittest"

# Go
run_tests "go" "./test.sh"

# Java
run_tests "java" "./gradlew test"

# JavaScript
run_tests "javascript" "yarn test"

# Python
run_tests "python" "./test.sh"

# Ruby
run_tests "ruby" "./test.sh"

# Rust
run_tests "rust" "cargo test"

echo "=== All tests completed ==="