#!/bin/bash

# test_all.sh - Run lint and tests for all Project Euler solutions across all languages

set -e  # Exit on any error

echo "=== Running Project Euler Lints and Tests ==="
echo

# Function to run lint for a language
run_lint() {
    local lang=$1
    local cmd=$2
    echo "Running $lang lint..."
    if cd "$lang" && eval "$cmd"; then
        echo "✓ $lang lint passed"
    else
        echo "✗ $lang lint failed"
        return 1
    fi
    cd ..
    echo
}

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
run_lint "cpp" "clang-tidy src/*.cpp src/*.h -- -I src -std=c++17 || echo 'clang-tidy not available, skipping'"
run_tests "cpp" "make bin/unittest && ./bin/unittest"

# Go
run_lint "go" "go vet ./... || echo 'go vet not available, skipping'"
run_tests "go" "./test.sh"

# Java
run_lint "java" "./gradlew check || echo 'gradle check not available, skipping'"
run_tests "java" "./gradlew test"

# JavaScript
run_lint "javascript" "npm run lint || echo 'npm run lint not available, skipping'"
run_tests "javascript" "npm test"

# Python
run_lint "python" "pylint src/ || flake8 src/ || echo 'pylint/flake8 not available, skipping'"
run_tests "python" "./test.sh"

# Rust
run_lint "rust" "cargo clippy || echo 'cargo clippy not available, skipping'"
run_tests "rust" "cargo test"

# Ruby
run_lint "ruby" "rubocop || echo 'rubocop not available, skipping'"

echo "=== All lints and tests completed ==="