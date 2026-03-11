#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")"

PASS=0
FAIL=0
ERRORS=()

check() {
    local label="$1"
    local file="$2"
    local expected="$3"
    local got

    got=$(go run "$file" 2>&1 | tr -d '\n')

    if [ "$got" = "$expected" ]; then
        printf "PASS  %-20s %s\n" "$label" "$got"
        PASS=$((PASS + 1))
    else
        printf "FAIL  %-20s got=%s want=%s\n" "$label" "$got" "$expected"
        FAIL=$((FAIL + 1))
        ERRORS+=("$label")
    fi
}

echo "Running solution answer checks"
echo "--------------------------------------"

check "euler001" euler001.go "233168"
check "euler002" euler002.go "4613732"
check "euler003" euler003.go "6857"
check "euler004" euler004.go "906609"
check "euler005" euler005.go "232792560"
check "euler006" euler006.go "25164150"
check "euler007" euler007.go "104743"
check "euler008" euler008.go "23514624000"
check "euler009" euler009.go "31875000"
check "euler010" euler010.go "142913828922"
check "euler011" euler011.go "70600674"
check "euler012" euler012.go "76576500"
check "euler013" euler013.go "5537376230"
check "euler014" euler014.go "837799"
check "euler015" euler015.go "137846528820"
check "euler016" euler016.go "1366"
check "euler017" euler017.go "21124"
check "euler018" euler018.go "1074"
check "euler019" euler019.go "171"
check "euler020" euler020.go "648"
check "euler021" euler021.go "31626"
check "euler022" euler022.go "871198282"
check "euler023" euler023.go "4179871"
check "euler024" euler024.go "2783915460"
check "euler025" euler025.go "4782"
check "euler026" euler026.go "983"
check "euler027" euler027.go "-59231"
check "euler028" euler028.go "669171001"
check "euler029" euler029.go "9183"
check "euler030" euler030.go "443839"
check "euler031" euler031.go "73682"
check "euler032" euler032.go "45228"
check "euler033" euler033.go "100"
check "euler034" euler034.go "40730"
check "euler035" euler035.go "55"
check "euler036" euler036.go "872187"
check "euler037" euler037.go "748317"
check "euler038" euler038.go "932718654"
check "euler039" euler039.go "840"
check "euler040" euler040.go "210"

echo "--------------------------------------"
echo "Results: ${PASS} passed, ${FAIL} failed"

if [ "${FAIL}" -gt 0 ]; then
    echo "Failed: ${ERRORS[*]}"
    exit 1
fi
