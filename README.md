# Project Euler Solutions [![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](cpp/) [![Go](https://img.shields.io/badge/Go-00ADD8?style=flat-square&logo=go&logoColor=white)](go/) [![Java](https://img.shields.io/badge/Java-ED8B00?style=flat-square&logo=openjdk&logoColor=white)](java/) [![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat-square&logo=javascript&logoColor=black)](javascript/) [![Python](https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white)](python/) [![Ruby](https://img.shields.io/badge/Ruby-CC342D?style=flat-square&logo=ruby&logoColor=white)](ruby/) [![Rust](https://img.shields.io/badge/Rust-000000?style=flat-square&logo=rust&logoColor=white)](rust/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Languages](#languages)
- [Usage](#usage)
- [Examples](#examples)
- [Running Tests](#running-tests)
- [Contributing](#contributing)
- [Links](#links)
- [License](#license)

This repository contains solutions to [Project Euler](https://projecteuler.net/) problems in multiple programming languages.

## Description

Project Euler is a series of challenging mathematical/computer programming problems that will require more than just mathematical insights to solve. Although mathematics will help you arrive at elegant and efficient methods, the use of a computer and programming skills will be required to solve most problems.

This repository provides comprehensive solutions to the first 30 Project Euler problems in seven different programming languages: C++, Go, Java, JavaScript, Python, Ruby, and Rust. Each language implementation demonstrates optimal algorithms, performance considerations, and language-specific best practices. The solutions serve as educational examples for learning both mathematical problem-solving and programming techniques across paradigms.

**Note:** Everything in this repository before this commit was hand-written. This repository is now 100% generated and maintained using AI assistance.

## Features

- **Multi-language implementations**: Compare approaches across seven programming languages
- **Optimized algorithms**: Solutions designed for efficiency and clarity
- **Comprehensive testing**: Unit tests verify correctness against known Project Euler answers
- **Educational value**: Learn both mathematics and programming through practical examples
- **Language-specific idioms**: Demonstrates best practices in each programming language
- **Complete coverage**: Solutions for problems 1-30, with answers verified

## Languages

This repository includes solutions in the following languages:

- [**C++**](cpp/) - High-performance implementations using modern C++17 features
- [**Go**](go/) - Concurrent and efficient solutions leveraging Go's strengths
- [**Java**](java/) - Object-oriented approaches with comprehensive testing via Gradle
- [**JavaScript**](javascript/) - Node.js solutions with modern ES6+ syntax
- [**Python**](python/) - Clean, readable code following PEP 8 standards
- [**Ruby**](ruby/) - Elegant, expressive solutions using Ruby idioms
- [**Rust**](rust/) - Memory-safe implementations with zero-cost abstractions

## Usage

Each language directory contains solutions to Project Euler problems. To run a specific solution:

- **Go** (go/): `go run eulerXXX.go`
- **Rust** (rust/): `cargo run`
- **C++** (cpp/): `make && ./bin/eulerXXX` (e.g., `./bin/euler026`)
- **Java** (java/): `./gradlew run`
- **JavaScript** (javascript/): `npm test` or `node src/eulerXXX.js`
- **Python** (python/): `python src/eulerXXX.py`
- **Ruby** (ruby/): `ruby lib/eulerXXX.rb` or `bundle exec rspec`

## Examples

### Running a Specific Solution

```bash
# Run Problem 1 in Python
cd python && python src/euler001.py

# Run Problem 1 in Go
cd go && go run euler001.go

# Run Problem 1 in Rust
cd rust && cargo run --bin euler001
```

### Using Automation Scripts

```bash
# Run all solutions across all languages
./run_solutions.sh

# Run tests for all languages
./test_all.sh

# Check problem completeness
./check_problems.sh
```

## Running Tests

### C++
Tests use Catch2 framework.

```bash
cd cpp
make bin/unittest
./bin/unittest
```

### Rust
```bash
cd rust
cargo test
```

### Ruby
```bash
cd ruby
bundle exec rspec
```

### JavaScript
```bash
cd javascript
npm test
```

### Java
```bash
cd java
./gradlew test
```

### Go
```bash
cd go
go test ./euler
```

### Python
```bash
cd python
pytest
```

## Contributing

Contributions are welcome! To add a new solution or improve existing ones:

1. Choose a problem and language
2. Implement the solution following the existing code style
3. Add appropriate tests
4. Update the README.md in the language directory
5. Submit a pull request

Please ensure all tests pass and the solution is efficient.

## Links

[Project Euler](https://projecteuler.net/)

[Go Euler Solutions](https://github.com/tvarley/go_euler)

[Current Repository](https://github.com/tvarley/euler)

## License

The MIT License (MIT)
Copyright (c) 2014-2026 Tim Varley

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.