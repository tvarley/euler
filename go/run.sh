#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")"

run_problem() {
    local file="$1"
    local label
    label=$(basename "$file" .go)
    printf "%-20s " "$label:"
    go run "$file"
}

for f in euler001.go euler002.go euler003.go euler004.go euler005.go euler006.go euler007.go \
          euler008.go euler009.go euler010.go euler011.go euler012.go \
          euler013.go euler014.go euler015.go euler016.go euler017.go \
          euler018.go euler019.go euler020.go euler021.go euler022.go \
          euler023.go euler024.go euler025.go euler026.go euler027.go \
          euler028.go euler029.go euler030.go; do
    run_problem "$f"
done
