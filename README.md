<div align="center">

<br>

```
  ██████╗ ██╗██╗   ██╗███████╗███╗   ██╗
  ██╔══██╗██║██║   ██║██╔════╝████╗  ██║
  ██████╔╝██║██║   ██║█████╗  ██╔██╗ ██║
  ██╔══██╗██║╚██╗ ██╔╝██╔══╝  ██║╚██╗██║
  ██║  ██║██║ ╚████╔╝ ███████╗██║ ╚████║
  ╚═╝  ╚═╝╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═══╝
```

<br>

**One language. Every domain.**

*AI · Automation · Systems · Native Performance*

<br>

![Status](https://img.shields.io/badge/status-pre--alpha-8B5E3C?style=flat-square&labelColor=1a1a1a)
![Language](https://img.shields.io/badge/compiler-C%2B%2B20-C8A97E?style=flat-square&labelColor=1a1a1a)
![Build](https://img.shields.io/badge/build-CMake-F5F0E8?style=flat-square&labelColor=1a1a1a)
![License](https://img.shields.io/badge/license-TBD-8B5E3C?style=flat-square&labelColor=1a1a1a)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-C8A97E?style=flat-square&labelColor=1a1a1a)
![Scratch](https://img.shields.io/badge/built%20from-scratch-F5F0E8?style=flat-square&labelColor=1a1a1a)

<br>

---

</div>

<br>

## What is Riven?

Riven is a next-generation, natively compiled programming language designed from the ground up — without LLVM, without Clang, without borrowed infrastructure. Every component of the compiler is engineered in-house using modern C++20.

The language is built around a single premise: the modern developer should not need to switch between Python for AI, C++ for performance, and a shell language for automation. Riven is one coherent language, capable of all three — and more.

Riven is **not** a replacement for C++. Riven is **not** a replacement for Python. It is something different: a language shaped by the demands of modern computing, designed to grow with you from scripting to systems programming to machine learning pipelines, all within a single, expressive syntax.

<br>

---

<br>

## Vision

<div align="center">

```
┌─────────────────────────────────────────────────────────────────────┐
│                                                                     │
│     AI Development   ──┐                                           │
│     Automation       ──┤                                           │
│     Systems          ──┼──▶   One Language   ──▶   Riven          │
│     Native Apps      ──┤                                           │
│     Cross Platform   ──┘                                           │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

</div>

Riven combines:

- The **expressiveness** of high-level languages
- The **performance and control** of low-level systems languages
- A **modern, clean syntax** that scales from small scripts to large codebases
- A **complete ecosystem** built entirely from scratch

<br>

---

<br>

## Why Riven?

The landscape of programming languages has a recurring problem: specialization at the cost of breadth. You write AI pipelines in one language, system utilities in another, and automation scripts in a third. Each switch carries cognitive overhead, toolchain complexity, and ecosystem fragmentation.

Riven is built on the conviction that this tradeoff is unnecessary.

| Problem Today | Riven's Approach |
|---|---|
| AI development requires Python; performance requires C++ | One language handles both |
| Every domain needs a different toolchain | Riven ships a unified ecosystem |
| Compiler infrastructure is borrowed, not owned | Every component is built from scratch |
| Modern languages compromise control for safety | Riven provides both without sacrificing either |
| Ecosystems grow fragmented over time | Riven's ecosystem is designed as a cohesive whole |

<br>

---

<br>

## Hello, World

```riven
riven main[]
{
    impr /> "Hello, World!";
}
```

Clean. Unambiguous. Intentional.

Every keyword in Riven is deliberate. Every operator has a defined purpose. The syntax is designed to be readable at first glance and precise under the hood.

<br>

---

<br>

## Language Primitives

### Current Keywords

| Keyword | Role |
|---|---|
| `riven` | Entry point declaration |
| `main` | Primary execution scope identifier |
| `impr` | Output / print instruction |

### Current Operators

| Operator | Description |
|---|---|
| `/>` | Output pipe — directs a value to the output stream |

### Supported Token Set

```
RIVEN          MAIN           LEFT_BRACKET    RIGHT_BRACKET
LEFT_BRACE     RIGHT_BRACE    IMPR            OUTPUT
STRING         SEMICOLON      END_OF_FILE
```

> The token set and keyword registry will expand incrementally as the compiler pipeline matures. Each addition is deliberate and documented.

<br>

---

<br>

## Compiler Architecture

Riven's compiler is engineered entirely from scratch. No third-party compiler infrastructure. No borrowed backends. Every stage is designed, implemented, and owned by this project.

<div align="center">

```
                     ┌──────────────────────────────────────┐
                     │           Riven Source File           │
                     │              ( .riven )               │
                     └──────────────────┬───────────────────┘
                                        │
                                        ▼
                     ┌──────────────────────────────────────┐
                     │               Lexer                   │
                     │     Tokenizes raw source text         │
                     │     into a structured token stream    │
                     └──────────────────┬───────────────────┘
                                        │
                                        ▼
                     ┌──────────────────────────────────────┐
                     │               Parser                  │
                     │     Builds a concrete syntax tree     │
                     │     from the token stream             │
                     └──────────────────┬───────────────────┘
                                        │
                                        ▼
                     ┌──────────────────────────────────────┐
                     │      Abstract Syntax Tree (AST)       │
                     │     Structured representation of      │
                     │     the program's semantics           │
                     └──────────────────┬───────────────────┘
                                        │
                                        ▼
                     ┌──────────────────────────────────────┐
                     │          Semantic Analysis            │
                     │     Type checking, scope resolution,  │
                     │     and validation passes             │
                     └──────────────────┬───────────────────┘
                                        │
                                        ▼
                     ┌──────────────────────────────────────┐
                     │             Optimizer                 │
                     │     IR-level and high-level           │
                     │     optimization passes               │
                     └──────────────────┬───────────────────┘
                                        │
                                        ▼
                     ┌──────────────────────────────────────┐
                     │         Code Generation Backend       │
                     │     Emits native machine code         │
                     │     for the target architecture       │
                     └──────────────────┬───────────────────┘
                                        │
                            ┌───────────┴───────────┐
                            ▼                       ▼
          ┌─────────────────────┐   ┌───────────────────────┐
          │      Assembler      │   │        Linker          │
          │  Translates emitted │   │  Resolves symbols and  │
          │  instructions into  │   │  produces the final    │
          │  object files       │   │  executable binary     │
          └─────────────────────┘   └───────────────────────┘
                            │                       │
                            └───────────┬───────────┘
                                        ▼
                     ┌──────────────────────────────────────┐
                     │          Native Executable            │
                     │     Runs directly on the target OS    │
                     └──────────────────────────────────────┘
```

</div>

<br>

---

<br>

## Current Progress

<div align="center">

| Component | Status | Progress |
|---|---|---|
| Repository Setup | Complete | `████████████████████` 100% |
| Lexer | In Progress | `████████░░░░░░░░░░░░` 40% |
| Parser | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| AST | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| Semantic Analysis | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| Optimizer | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| Code Generation Backend | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| Assembler | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| Linker | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| Runtime | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| Standard Library | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| Package Manager | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |
| Language Server | Not Started | `░░░░░░░░░░░░░░░░░░░░` 0% |

</div>

> Riven is in active pre-alpha development. All public milestones are tracked in the [Issues](../../issues) tab.

<br>

---

<br>

## Roadmap

```
Phase 0 — Foundation                                        [ Current ]
  ├── Repository structure
  ├── CMake build system
  ├── Lexer implementation
  └── Initial token set

Phase 1 — Frontend                                          [ Upcoming ]
  ├── Complete Lexer
  ├── Parser
  ├── AST construction
  └── Semantic Analysis

Phase 2 — Backend                                           [ Planned ]
  ├── Optimizer passes
  ├── Code generation backend
  ├── Assembler
  └── Linker

Phase 3 — Runtime & Standard Library                        [ Planned ]
  ├── Core runtime
  ├── Memory model
  ├── Standard Library (I/O, collections, strings)
  └── Error handling primitives

Phase 4 — Tooling                                           [ Planned ]
  ├── Package Manager
  ├── Language Server (LSP)
  ├── Formatter
  ├── Debugger
  └── Profiler

Phase 5 — Ecosystem                                         [ Future ]
  ├── Build System
  ├── Testing Framework
  ├── Automation Framework
  ├── AI Framework
  ├── GPU Computing
  ├── Networking
  ├── Database APIs
  ├── Cloud APIs
  ├── SDK
  ├── IDE Support
  ├── Documentation Site
  └── Website
```

<br>

---

<br>

## Repository Structure

```
riven/
│
├── compiler/               # Compiler source — Lexer, Parser, AST, Semantic Analysis,
│   │                       # Optimizer, Backend, Assembler, Linker
│   ├── lexer/
│   ├── parser/
│   ├── ast/
│   ├── sema/
│   ├── optimizer/
│   ├── backend/
│   ├── assembler/
│   └── linker/
│
├── runtime/                # Riven runtime — memory model, execution context
│
├── std/                    # Standard Library — I/O, collections, strings, math
│
├── docs/                   # Language specification, design documents, guides
│
├── examples/               # Riven example programs demonstrating syntax and features
│
├── tests/                  # Compiler and language test suites
│
├── scripts/                # Developer and CI utility scripts
│
├── tools/                  # Developer tools — formatter, profiler stubs, helpers
│
├── assets/                 # Branding assets — logo, mascot, color references
│
├── benchmarks/             # Performance benchmarks for the compiler and runtime
│
├── third_party/            # Vendored external dependencies (minimal by design)
│
├── CMakeLists.txt          # Top-level CMake build configuration
└── README.md
```

<br>

---

<br>

## Building from Source

Riven's compiler is built with CMake and requires a C++20-compliant toolchain.

### Prerequisites

| Tool | Minimum Version |
|---|---|
| CMake | 3.20 |
| C++ Compiler | GCC 11 / Clang 13 / MSVC 2022 |
| Git | Any recent version |

---

### Windows

```powershell
git clone https://github.com/your-org/riven.git
cd riven

cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

The compiled binary will be located at `build\Release\rivenc.exe`.

---

### Linux

```bash
git clone https://github.com/your-org/riven.git
cd riven

cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -- -j$(nproc)
```

The compiled binary will be located at `build/rivenc`.

---

### macOS

```bash
git clone https://github.com/your-org/riven.git
cd riven

cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -- -j$(sysctl -n hw.logicalcpu)
```

The compiled binary will be located at `build/rivenc`.

---

### Running the Compiler

```bash
# Compile a Riven source file
./rivenc hello.riven

# Compile with verbose output
./rivenc --verbose hello.riven
```

> Note: Not all compiler flags are implemented in the current pre-alpha stage. The CLI surface is under active development.

<br>

---

<br>

## Examples

### Hello, World

```riven
riven main[]
{
    impr /> "Hello, World!";
}
```

> More examples will be published to the `examples/` directory as the language matures and additional syntax is implemented.

<br>

---

<br>

## Documentation

Documentation lives in the `docs/` directory and will grow alongside the language.

| Document | Description |
|---|---|
| `docs/spec/` | Language specification |
| `docs/compiler/` | Compiler internals and architecture notes |
| `docs/stdlib/` | Standard Library reference |
| `docs/contributing/` | Contribution guidelines and coding standards |

A dedicated documentation website is planned as part of the Phase 5 ecosystem build-out.

<br>

---

<br>

## Contributing

Riven is in pre-alpha. At this stage, the most valuable contributions are:

- Reviewing and discussing the language design in [Discussions](../../discussions)
- Reporting issues with the build system or compiler in [Issues](../../issues)
- Reading the architecture documents in `docs/compiler/` and providing feedback

Before contributing code, please read the contributor guidelines in `docs/contributing/`. All contributors are expected to follow the project's coding standards and design philosophy — particularly the commitment to building every component from scratch.

Pull requests targeting core compiler components will be reviewed carefully. Please open a discussion or issue before beginning large pieces of work.

<br>

---

<br>

## Design Philosophy

Riven's development is guided by a small number of firm principles:

**Everything from scratch.** No LLVM. No Clang. No external compiler infrastructure. Every stage of the compiler — from lexer to linker — is designed and implemented within this project.

**One language, many domains.** Riven does not specialize. It grows to cover AI, automation, systems programming, and native application development as a unified whole.

**Intentional syntax.** Every keyword, operator, and construct is chosen deliberately. The language will not accumulate features without purpose.

**Long-term thinking.** Riven is not being built to ship fast. It is being built to last.

<br>

---

<br>

## Future Plans

Beyond the compiler and standard library, the long-term vision for Riven includes a complete, self-contained ecosystem:

- **AI Framework** — First-class tensor operations, model integration, and training utilities
- **GPU Computing** — Native GPU programming without requiring external shading languages
- **Automation Framework** — Shell-level scripting power with systems-level performance
- **Networking** — Async-native networking primitives in the standard library
- **Database APIs** — Unified query interface across relational and document databases
- **Cloud APIs** — First-class bindings for cloud infrastructure management
- **Testing Framework** — Built-in test runner, assertion library, and coverage tooling
- **IDE Support** — Language Server Protocol implementation and editor plugins
- **Profiler** — Sampling and instrumentation profiler integrated into the toolchain
- **Debugger** — Source-level debugger with native debug information emission

None of these are premature. All of them are accounted for in the architecture of what is being built today.

<br>

---

<br>

## Acknowledgements

Riven is built entirely from scratch. Its design draws on decades of compiler theory, systems programming practice, and language design research — not on borrowed code. Every engineering decision is made in service of the language's long-term vision.

<br>

---

<br>

## License

License terms are forthcoming. Until a license is formally published, all rights are reserved. Do not redistribute or use the source code in other projects without explicit permission.

<br>

---

<br>

<div align="center">

```
  ██████╗ ██╗██╗   ██╗███████╗███╗   ██╗
  ██╔══██╗██║██║   ██║██╔════╝████╗  ██║
  ██████╔╝██║██║   ██║█████╗  ██╔██╗ ██║
  ██╔══██╗██║╚██╗ ██╔╝██╔══╝  ██║╚██╗██║
  ██║  ██║██║ ╚████╔╝ ███████╗██║ ╚████║
  ╚═╝  ╚═╝╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═══╝
```

*Built from nothing. Aimed at everything.*

<br>

![Pre-Alpha](https://img.shields.io/badge/pre--alpha-in%20development-8B5E3C?style=flat-square&labelColor=1a1a1a)

</div>
