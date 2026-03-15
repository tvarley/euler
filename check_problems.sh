#!/bin/bash

# check_problems.sh - Check problem completeness across all languages

echo "=== Project Euler Problem Completeness Check ==="
echo

languages=("cpp" "go" "java" "javascript" "python" "rust")
total_problems=50

for lang in "${languages[@]}"; do
    echo "Checking $lang..."

    case $lang in
        cpp)
            count=$(ls -1 "$lang/src/euler"*.cpp 2>/dev/null | wc -l)
            ;;
        go)
            count=$(ls -1 "$lang/euler"*.go 2>/dev/null | wc -l)
            ;;
        java)
            count=$(ls -1 "$lang/src/main/java/org/tvarley/euler/solutions/Solution"*.java 2>/dev/null | wc -l)
            ;;
        javascript)
            count=$(ls -1 "$lang/src/euler/solution"*.js 2>/dev/null | wc -l)
            ;;
        python)
            count=$(ls -1 "$lang/src/euler"*.py 2>/dev/null | wc -l)
            ;;
        ruby)
            count=$(ls -1 "$lang/lib/euler"*.rb 2>/dev/null | wc -l)
            ;;
        rust)
            # Count modules in lib.rs or separate files
            count=$(grep -c "^pub mod euler[0-9]" "$lang/src/lib.rs" 2>/dev/null || ls -1 "$lang/src/euler"*.rs 2>/dev/null | wc -l)
            ;;
    esac

    percentage=$((count * 100 / total_problems))
    echo "  $lang: $count/$total_problems problems ($percentage%)"

    if [ "$count" -lt "$total_problems" ]; then
        echo "  Missing: $(seq -f "%03g" $((count + 1)) $total_problems | tr '\n' ' ')"
    fi
    echo
done

echo "=== Check complete ==="