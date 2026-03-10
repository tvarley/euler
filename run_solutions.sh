#!/bin/bash

# run_solutions.sh - Run all Project Euler solutions across all languages

set -e  # Exit on any error

echo "=== Running Project Euler Solutions ==="
echo

# Function to run solutions for a language
run_language() {
    local lang=$1
    local cmd=$2
    echo "Running $lang solutions..."
    if cd "$lang" && eval "$cmd"; then
        echo "✓ $lang completed successfully"
    else
        echo "✗ $lang failed"
        return 1
    fi
    cd ..
    echo
}

# C++
run_language "cpp" "make all && for f in bin/euler*; do ./\$f; done"

# Go
run_language "go" "./run.sh"

# Java
run_language "java" "./gradlew run"

# JavaScript
run_language "javascript" "node src/index.js"

# Python
run_language "python" "python3 run_all.py"

# Ruby
run_language "ruby" "./run.sh"

# Rust
run_language "rust" "cargo run"

echo "=== All solutions completed ==="