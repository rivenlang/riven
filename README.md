<div align="center">

<!-- Logo -->
<img src="docs/assets/riven-logo.svg" alt="Riven Logo" width="120" height="120" />

<br />

<!-- Banner -->
<img src="docs/assets/riven-banner.png" alt="Riven Banner" width="100%" />

<br />
<br />

# Riven

**A native systems programming language built from scratch in modern C++.**  
Designed for AI programming, automation, and the next generation of software.

<br />

[![Build Status](https://img.shields.io/github/actions/workflow/status/yourusername/riven/ci.yml?branch=main&style=flat-square&label=build&color=0f172a)](https://github.com/yourusername/riven/actions)
[![License](https://img.shields.io/badge/license-MIT-blue?style=flat-square&color=0f172a)](LICENSE)
[![Version](https://img.shields.io/badge/version-0.1.0--dev-orange?style=flat-square&color=7c3aed)](CHANGELOG.md)
[![Language](https://img.shields.io/badge/written%20in-C%2B%2B23-informational?style=flat-square&color=0284c7)](https://en.cppreference.com/w/cpp/23)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey?style=flat-square)](docs/platforms.md)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen?style=flat-square&color=059669)](CONTRIBUTING.md)
[![Discord](https://img.shields.io/badge/discord-join-5865F2?style=flat-square&logo=discord&logoColor=white)](https://discord.gg/placeholder)
[![Stars](https://img.shields.io/github/stars/yourusername/riven?style=flat-square&color=f59e0b)](https://github.com/yourusername/riven/stargazers)

<br />

[**Documentation**](https://riven-lang.org/docs) · [**Language Tour**](https://riven-lang.org/tour) · [**Playground**](https://riven-lang.org/play) · [**Roadmap**](ROADMAP.md) · [**Blog**](https://riven-lang.org/blog)

<br />

</div>

---

## About

Riven is a compiled, statically typed programming language designed for systems programming, AI development, and large-scale automation — built entirely from scratch in modern C++, with no dependency on LLVM or other compiler frameworks.

The compiler is self-contained: custom lexer, parser, semantic analyzer, optimizer, and code generation backend. Riven is being built for developers who need precise control over machine behavior without sacrificing the expressiveness and safety that modern software demands.

> **Status:** Early development. The compiler bootstraps a subset of the language. Not production-ready.

---

## Vision

Most languages today either give you full control (C, C++) at the cost of safety and ergonomics, or give you safety and expressiveness (Rust, Swift) at the cost of complexity and learning curve. AI and automation tooling is often bolted onto languages that weren't designed for it.

Riven starts from a different premise:

- **Safety without ceremony.** Ownership and memory safety enforced at compile time, without lifetime annotations cluttering every function signature.
- **AI as a first-class citizen.** Language-level constructs for model invocation, structured output, and tensor operations — not third-party libraries.
- **Native speed.** No runtime, no garbage collector, no virtual machine. Riven compiles directly to machine code.
- **One compiler, built to last.** No LLVM dependency. Full control over every optimization pass and code generation target.

---

## Features

| Feature | Status |
|---|---|
| Hand-written recursive descent parser | ✅ Implemented |
| Static type system with inference | ✅ Implemented |
| Lexical scoping and closures | ✅ Implemented |
| First-class functions | ✅ Implemented |
| Structs and enums | ✅ Implemented |
| Pattern matching | 🔧 In progress |
| Memory ownership model | 🔧 In progress |
| Native x86-64 code generation | 🔧 In progress |
| Cross-platform target support | 📅 Planned |
| Concurrency primitives | 📅 Planned |
| AI programming constructs | 📅 Planned |
| Package manager (`rpm`) | 📅 Planned |
| Language server (LSP) | 📅 Planned |
| Integrated debugger | 📅 Planned |
| Standard library | 📅 Planned |

---

## Why Riven?

<table>
<tr>
<td width="50%" valign="top">

**No LLVM.**  
Riven's compiler backend is written entirely from scratch. This means full control over instruction selection, register allocation, and target-specific optimizations — without LLVM's compilation overhead, toolchain complexity, or licensing constraints.

**Built for AI.**  
Language-level support for model inference, structured generation, and data pipelines is part of the language design, not an afterthought. Write AI-driven programs the same way you write any other system.

</td>
<td width="50%" valign="top">

**Predictable performance.**  
No garbage collector. No runtime pauses. Deterministic memory management with compile-time ownership semantics keeps your program's behavior in your hands.

**Cross-platform from day one.**  
Riven targets Linux, macOS, and Windows natively. A single codebase, a single compiler, multiple backends.

</td>
</tr>
</table>

---

## Hello, World

```riven
fn main() {
    println("Hello, World!")
}
```

**Fibonacci sequence:**

```riven
fn fib(n: u64) -> u64 {
    match n {
        0 => 0,
        1 => 1,
        _ => fib(n - 1) + fib(n - 2),
    }
}

fn main() {
    for i in 0..10 {
        println("{}", fib(i))
    }
}
```

**Structs and methods:**

```riven
struct Point {
    x: f64,
    y: f64,
}

impl Point {
    fn distance(self, other: Point) -> f64 {
        let dx = self.x - other.x
        let dy = self.y - other.y
        sqrt(dx * dx + dy * dy)
    }
}

fn main() {
    let a = Point { x: 0.0, y: 0.0 }
    let b = Point { x: 3.0, y: 4.0 }
    println("Distance: {}", a.distance(b))
}
```

---

## Repository Structure

```
riven/
├── compiler/               # Core compiler implementation (C++)
│   ├── include/            # Public headers
│   │   ├── lexer/          # Tokenizer and source location tracking
│   │   ├── parser/         # AST node types and parser interface
│   │   ├── sema/           # Semantic analysis and type checker
│   │   ├── ir/             # Intermediate representation
│   │   ├── opt/            # Optimization passes
│   │   └── codegen/        # Native code generation backends
│   └── src/                # Implementation files
│       ├── lexer/
│       ├── parser/
│       ├── sema/
│       ├── ir/
│       ├── opt/
│       └── codegen/
│           ├── x86_64/     # x86-64 backend
│           └── aarch64/    # ARM64 backend (planned)
├── stdlib/                 # Riven standard library (written in Riven)
│   ├── core/               # Core types, operators, primitives
│   ├── io/                 # I/O and formatting
│   ├── collections/        # Vec, Map, Set, and friends
│   └── ai/                 # AI programming constructs (planned)
├── tools/
│   ├── rpm/                # Riven package manager (planned)
│   ├── rls/                # Riven language server (planned)
│   └── rdb/                # Riven debugger (planned)
├── tests/                  # Test suite
│   ├── unit/               # Unit tests per compiler stage
│   ├── integration/        # End-to-end compiler tests
│   └── conformance/        # Language conformance tests
├── docs/                   # Documentation source
│   └── assets/             # Logos, banners, diagrams
├── examples/               # Example Riven programs
├── benchmarks/             # Performance benchmarks
├── CMakeLists.txt          # Top-level build configuration
└── CONTRIBUTING.md
```

---

## Compiler Architecture

```
Source File (.rv)
      │
      ▼
┌─────────────┐
│    Lexer    │  Tokenizes source text into a stream of typed tokens.
│             │  Tracks source locations for precise diagnostics.
└──────┬──────┘
       │  Token stream
       ▼
┌─────────────┐
│   Parser    │  Recursive descent parser. Produces a typed AST.
│             │  No grammar files — fully hand-written for full control.
└──────┬──────┘
       │  Abstract Syntax Tree (AST)
       ▼
┌─────────────┐
│    Sema     │  Semantic analysis: name resolution, type inference,
│             │  ownership checks, and borrow validation.
└──────┬──────┘
       │  Typed, resolved AST
       ▼
┌─────────────┐
│  IR / MIR   │  Lowering to Riven's mid-level intermediate representation.
│             │  Control-flow graph, SSA form, explicit ownership graph.
└──────┬──────┘
       │  Mid-level IR
       ▼
┌─────────────┐
│  Optimizer  │  Optimization passes: inlining, dead code elimination,
│             │  constant folding, escape analysis, vectorization.
└──────┬──────┘
       │  Optimized IR
       ▼
┌─────────────┐
│   Codegen   │  Target-specific instruction selection,
│             │  register allocation, and assembly emission.
└──────┬──────┘
       │
   ┌───┴───┐
   ▼       ▼
x86-64  AArch64   (more targets planned)
```

---

## Build Instructions

### Prerequisites

| Tool | Minimum Version |
|---|---|
| C++ Compiler (GCC or Clang) | GCC 13 / Clang 17 |
| CMake | 3.25 |
| Ninja | 1.11 (recommended) |
| Python | 3.10 (for build scripts) |

### Quick Start

```sh
# Clone the repository
git clone https://github.com/yourusername/riven.git
cd riven

# Configure (Release mode recommended for first build)
cmake -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build build --parallel

# Run the compiler
./build/bin/rivc --help
```

### Build Options

| Option | Default | Description |
|---|---|---|
| `RIVEN_ENABLE_TESTS` | `ON` | Build the test suite |
| `RIVEN_ENABLE_ASSERTIONS` | `ON` (Debug) | Enable internal compiler assertions |
| `RIVEN_SANITIZERS` | `OFF` | Enable AddressSanitizer and UBSan |
| `RIVEN_TARGET_X86_64` | `ON` | Build the x86-64 codegen backend |
| `RIVEN_TARGET_AARCH64` | `OFF` | Build the AArch64 codegen backend |
| `RIVEN_BUILD_STDLIB` | `ON` | Build the standard library |

### Running Tests

```sh
# Run the full test suite
ctest --test-dir build --parallel --output-on-failure

# Run a specific test category
ctest --test-dir build -R "unit/lexer" --output-on-failure
```

### Compile a Riven Program

```sh
# Compile to native binary
./build/bin/rivc examples/hello.rv -o hello

# Run it
./hello
```

---

## Development Roadmap

### Phase 1 — Compiler Foundation *(current)*

- [x] Lexer with source location tracking
- [x] Hand-written recursive descent parser
- [x] Abstract syntax tree (AST) definition
- [x] Basic type system and type inference
- [x] Semantic analysis pass
- [ ] Mid-level IR (MIR) design and lowering
- [ ] x86-64 code generation (function calls, arithmetic, control flow)
- [ ] ELF/PE/Mach-O object file emission

### Phase 2 — Language Core

- [ ] Memory ownership model and borrow checker
- [ ] Pattern matching and exhaustiveness checking
- [ ] Generics and parametric polymorphism
- [ ] Traits / interfaces
- [ ] Error handling (`Result` and `Option`)
- [ ] Module system and namespaces
- [ ] Inline assembly

### Phase 3 — Standard Library & Tooling

- [ ] Core standard library (`core`, `io`, `collections`)
- [ ] Package manager (`rpm`)
- [ ] Language Server Protocol implementation (`rls`)
- [ ] Integrated debugger (`rdb`)
- [ ] Build system integration
- [ ] REPL / interactive mode

### Phase 4 — AI & Automation

- [ ] AI programming primitives (model invocation, structured output)
- [ ] Async/await and concurrent task primitives
- [ ] Tensor and vector type support
- [ ] Automation scripting layer
- [ ] Foreign function interface (C/C++ interop)

### Phase 5 — Production Readiness

- [ ] AArch64 (ARM64) backend
- [ ] WebAssembly backend
- [ ] Self-hosting compiler bootstrap
- [ ] Formal language specification
- [ ] Comprehensive documentation and book

---

## Project Status

> **Alpha — Not production-ready.**

Riven is in active early development. Core language features are being implemented and the compiler architecture is still evolving. The language syntax and semantics may change without notice between versions.

| Component | Status |
|---|---|
| Lexer | Stable |
| Parser | Stable |
| Type Checker | In progress |
| IR / MIR | Design phase |
| x86-64 Backend | In progress |
| Standard Library | Not started |
| Package Manager | Not started |
| Language Server | Not started |

---

## Documentation

| Resource | Description |
|---|---|
| [Language Reference](https://riven-lang.org/docs/reference) | Complete language specification |
| [Getting Started](https://riven-lang.org/docs/getting-started) | Install and write your first program |
| [Language Tour](https://riven-lang.org/tour) | Interactive guided tour |
| [Compiler Internals](docs/compiler-internals.md) | Architecture and contributing guide for the compiler |
| [Standard Library API](https://riven-lang.org/docs/stdlib) | Standard library reference |
| [Changelog](CHANGELOG.md) | Version history and release notes |

---

## Contributing

Contributions are welcome. Riven is a community-driven project and every piece of help — from bug reports to new compiler passes — matters.

### Getting Started

1. Read [CONTRIBUTING.md](CONTRIBUTING.md) for the full contribution guide.
2. Browse [open issues](https://github.com/yourusername/riven/issues) — issues labeled `good first issue` are a great starting point.
3. Join the [Discord](https://discord.gg/placeholder) to discuss ideas and ask questions before opening a PR.

### Contribution Areas

- **Compiler:** Parser improvements, new optimization passes, codegen correctness.
- **Standard Library:** Core types, I/O, and collections (written in Riven).
- **Tests:** Conformance tests, edge case coverage, regression tests.
- **Documentation:** Language reference, tutorials, examples.
- **Tooling:** Editor support, build system integration, CI improvements.

### Code Style

- Follow the [C++ style guide](docs/style-guide.md) used across the compiler.
- All public APIs must be documented.
- New features require tests. Bug fixes should include a regression test.
- Run `clang-format` before submitting (configuration in `.clang-format`).

---

## License

Riven is released under the [MIT License](LICENSE).

```
MIT License

Copyright (c) 2024 Riven Contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software...
```

See [LICENSE](LICENSE) for the full text.

---

<div align="center">

<br />

**Riven** is built by contributors around the world.  
If this project interests you, give it a ⭐ — it helps more people find it.

<br />

[Website](https://riven-lang.org) · [Documentation](https://riven-lang.org/docs) · [Discord](https://discord.gg/placeholder) · [Twitter / X](https://twitter.com/riven_lang) · [Issues](https://github.com/yourusername/riven/issues)

<br />

<sub>Copyright © 2024 Riven Contributors. Released under the MIT License.</sub>

