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

    got=$(python3 -c "import sys; sys.path.insert(0, 'src'); import $file; print($file.solve())" 2>&1)

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

check "euler001" euler001 "233168"
check "euler002" euler002 "4613732"
check "euler003" euler003 "6857"
check "euler004" euler004 "906609"
check "euler005" euler005 "232792560"
check "euler006" euler006 "25164150"
check "euler007" euler007 "104743"
check "euler008" euler008 "23514624000"
check "euler009" euler009 "31875000"
check "euler010" euler010 "142913828922"
check "euler011" euler011 "70600674"
check "euler012" euler012 "76576500"
check "euler013" euler013 "5537376230"
check "euler014" euler014 "837799"
check "euler015" euler015 "137846528820"
check "euler016" euler016 "1366"
check "euler017" euler017 "21124"
check "euler018" euler018 "1074"
check "euler019" euler019 "171"
check "euler020" euler020 "648"
check "euler021" euler021 "31626"
check "euler022" euler022 "871198282"
check "euler023" euler023 "4179871"
check "euler024" euler024 "2783915460"
check "euler025" euler025 "4782"
check "euler026" euler026 "983"
check "euler027" euler027 "-59231"
check "euler028" euler028 "669171001"
check "euler029" euler029 "9183"
check "euler030" euler030 "443839"
check "euler031" euler031 "73682"
check "euler032" euler032 "45228"
check "euler033" euler033 "100"
check "euler034" euler034 "40730"
check "euler035" euler035 "55"
check "euler036" euler036 "872187"
check "euler037" euler037 "748317"
check "euler038" euler038 "932718654"
check "euler039" euler039 "840"
check "euler040" euler040 "210"
check "euler041" euler041 "7652413"
check "euler042" euler042 "162"
check "euler043" euler043 "16695334890"
check "euler044" euler044 "5482660"
check "euler045" euler045 "1533776805"
check "euler046" euler046 "5777"
check "euler047" euler047 "134043"
check "euler048" euler048 "9110846700"
check "euler049" euler049 "296962999629"
check "euler050" euler050 "997651"
check "euler051" euler051 "121313"
check "euler052" euler052 "142857"
check "euler053" euler053 "4075"
check "euler054" euler054 "376"
check "euler055" euler055 "249"
check "euler056" euler056 "972"
check "euler057" euler057 "153"
check "euler058" euler058 "26241"
check "euler059" euler059 "107359"
check "euler060" euler060 "26033"

echo "--------------------------------------"
echo "Results: ${PASS} passed, ${FAIL} failed"

if [ "${FAIL}" -gt 0 ]; then
    echo "Failed: ${ERRORS[*]}"
    exit 1
fi