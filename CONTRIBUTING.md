# Contributing to Riven

Thank you for your interest in contributing to Riven. This document explains how to participate in the project effectively, what standards we hold ourselves to, and what you can expect from the process of getting your work merged.

Riven is a pre-alpha programming language and compiler built entirely from scratch in Modern C++20. Every component — from the lexer to the linker — is developed within this project. Contributing here means working on fundamental systems software, and we treat the codebase with the seriousness that demands.

---

## Table of Contents

- [Welcome](#welcome)
- [Project Philosophy](#project-philosophy)
- [Before You Contribute](#before-you-contribute)
- [Development Environment Setup](#development-environment-setup)
- [Repository Structure Overview](#repository-structure-overview)
- [Coding Standards](#coding-standards)
- [Naming Conventions](#naming-conventions)
- [Branch Naming Rules](#branch-naming-rules)
- [Commit Message Guidelines](#commit-message-guidelines)
- [Pull Request Process](#pull-request-process)
- [Code Review Expectations](#code-review-expectations)
- [Testing Requirements](#testing-requirements)
- [Documentation Requirements](#documentation-requirements)
- [Compiler Architecture Guidelines](#compiler-architecture-guidelines)
- [Performance Guidelines](#performance-guidelines)
- [Error Handling Guidelines](#error-handling-guidelines)
- [Directory Organization Rules](#directory-organization-rules)
- [Issue Reporting](#issue-reporting)
- [Feature Requests](#feature-requests)
- [Security Reporting](#security-reporting)
- [Community Expectations](#community-expectations)
- [Recognition for Contributors](#recognition-for-contributors)

---

## Welcome

Riven is an ambitious project. Building a complete compiler toolchain from scratch — with no dependency on LLVM, Clang, or any existing compiler infrastructure — is not a small undertaking. Every component you see in this repository was written specifically for Riven.

We welcome contributors who are willing to learn the codebase, engage thoughtfully in design discussions, write clean code, and maintain high standards for quality. Experience with compiler internals is helpful but not required for all tasks. Curiosity, patience, and attention to detail matter more.

If you are new to compiler development, start by reading the existing code carefully before proposing changes. The best contributions often come from people who spend time understanding the system before touching it.

---

## Project Philosophy

Riven is guided by a set of principles that shape every decision, from high-level architecture to individual function design.

**Simplicity.** A solution that is easy to understand is almost always preferable to one that is clever. Complexity should be introduced only when the problem genuinely demands it.

**Maintainability.** Code will be read far more often than it is written. Favor designs that remain comprehensible as the project grows. Avoid constructs that create hidden dependencies or obscure intent.

**Modularity.** Each compiler stage has a defined responsibility. Boundaries between stages are intentional and should be respected. Mixing concerns across module boundaries creates fragility and makes future changes harder.

**Performance.** Riven aims to be a fast compiler. Performance matters, but it should not come at the cost of correctness or clarity. Measure before optimizing. Document the reason for any non-obvious optimization.

**Readability.** Code is communication. Variable names, function signatures, and structure should tell the reader what is happening and why. Comments explain intent, not mechanics.

**Long-term stability.** We are building a foundation. Decisions made today will constrain and enable decisions made years from now. Prefer approaches that age well over those that deliver short-term convenience.

---

## Before You Contribute

Before writing any code, please take the following steps.

**Read this document in full.** The guidelines here exist for good reasons. Submitting work that ignores them creates review overhead and slows the project down.

**Check the issue tracker.** The work you want to do may already be tracked, in progress, or intentionally deferred. Look for existing issues and pull requests before starting.

**Open an issue before large changes.** If your contribution involves significant new functionality, a change to compiler architecture, or a departure from existing design patterns, open an issue and discuss it first. This saves both your time and the maintainers' time.

**Understand the compiler pipeline.** Familiarize yourself with the stage of the compiler your change touches before modifying it. Read the relevant source files, tests, and any inline documentation.

**Do not introduce external compiler framework dependencies.** Riven builds every compiler component in-house. Contributions that introduce dependencies on LLVM, Clang libraries, or similar frameworks will not be accepted regardless of the quality of the surrounding code. The host C++ toolchain (GCC, Clang, MSVC) is used only to compile the Riven source itself.

---

## Development Environment Setup

### Requirements

- A C++20-compliant compiler: GCC 11 or later, or Clang 13 or later
- CMake 3.22 or later
- Ninja (recommended) or Make
- Python 3.8 or later (for test tooling)
- Git 2.30 or later

### Building the Project

```bash
git clone https://github.com/riven-lang/riven.git
cd riven
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

For a release build:

```bash
cmake -B build-release -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

### Running Tests

```bash
cd build
ctest --output-on-failure
```

Or run the test suite directly:

```bash
python3 tools/test-runner.py
```

### Recommended Configuration

Enable compiler warnings and treat them as errors during development:

```bash
cmake -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DRIVEN_WARNINGS_AS_ERRORS=ON \
  -DRIVEN_ENABLE_SANITIZERS=ON
```

Address Sanitizer and Undefined Behavior Sanitizer are enabled by the `RIVEN_ENABLE_SANITIZERS` flag and should be used during local development.

---

## Repository Structure Overview

```
riven/
├── include/              # Public headers for each compiler component
│   ├── lexer/
│   ├── parser/
│   ├── ast/
│   ├── sema/
│   ├── ir/
│   ├── optimizer/
│   ├── codegen/
│   ├── assembler/
│   ├── linker/
│   └── runtime/
├── src/                  # Implementation files
│   ├── lexer/
│   ├── parser/
│   ├── ast/
│   ├── sema/
│   ├── ir/
│   ├── optimizer/
│   ├── codegen/
│   ├── assembler/
│   ├── linker/
│   └── runtime/
├── tests/                # Test suite
│   ├── unit/
│   ├── integration/
│   └── end-to-end/
├── tools/                # Developer tooling and scripts
├── docs/                 # Project and language documentation
├── benchmarks/           # Performance benchmarks
└── CMakeLists.txt
```

Each top-level directory under `include/` and `src/` corresponds to a distinct stage in the compiler pipeline. Keep this correspondence strict.

---

## Coding Standards

Riven is written in Modern C++20. The following rules apply to all source contributions.

### General

- Write code that can be understood without consulting the author. If a function requires a comment to be understood, consider whether it can be restructured.
- Prefer explicit over implicit. Avoid relying on implicit conversions, argument-dependent lookup surprises, or behavior that depends on subtle contextual rules.
- Keep functions small and focused. A function should do one thing. If a function is doing several things, consider decomposing it.
- Avoid deeply nested control flow. Extract early returns, guard clauses, or helper functions rather than nesting conditionals several levels deep.
- Do not write speculative infrastructure. Implement what the current feature requires. Generalization can be added when there is a second use case.

### C++20 Specifics

- Use `std::span`, `std::string_view`, and ranges where they improve clarity and reduce copying.
- Use concepts to constrain templates rather than relying on substitution failure or static assertions alone.
- Prefer `constexpr` and `consteval` for compile-time computation.
- Use structured bindings where they improve readability.
- Do not use raw owning pointers. Use `std::unique_ptr` or `std::shared_ptr` with a clear ownership rationale.
- Avoid `std::shared_ptr` unless shared ownership is genuinely required. Most cases in a compiler pipeline involve clear single ownership.
- Use `[[nodiscard]]` on functions whose return values should not be silently discarded.
- Use `std::optional` instead of nullable pointers or sentinel values for optional results.
- Use `std::variant` and `std::visit` for typed unions rather than untagged unions or manual type tags.

### Forbidden Practices

- No `goto`.
- No `reinterpret_cast` without a documented justification.
- No C-style casts.
- No `#define` for constants or pseudo-functions. Use `constexpr` or `inline` functions.
- No global mutable state unless unavoidable and explicitly justified.
- No ignored return values on functions marked `[[nodiscard]]`.

---

## Naming Conventions

Consistent naming reduces the cognitive load of reading unfamiliar code. Follow these conventions throughout the codebase.

| Construct | Convention | Example |
|---|---|---|
| Types and classes | `PascalCase` | `TokenKind`, `AstNode`, `SemanticAnalyzer` |
| Functions and methods | `camelCase` | `parseExpression()`, `emitInstruction()` |
| Local variables | `camelCase` | `tokenList`, `currentScope` |
| Member variables | `camelCase` with `m_` prefix | `m_tokens`, `m_currentOffset` |
| Static member variables | `camelCase` with `s_` prefix | `s_instanceCount` |
| Constants and enumerators | `UPPER_SNAKE_CASE` | `MAX_TOKEN_LENGTH`, `TokenKind::IDENTIFIER` |
| Macros (minimize use) | `UPPER_SNAKE_CASE` with `RIVEN_` prefix | `RIVEN_ASSERT(...)` |
| Namespaces | `lowercase` | `riven::lexer`, `riven::sema` |
| Template parameters | `PascalCase` | `template <typename NodeType>` |
| Files | `kebab-case` | `token-kind.h`, `ast-node.cpp` |

Do not abbreviate names arbitrarily. `identifier` is preferable to `ident`, and `expression` is preferable to `expr`, unless the abbreviation is so universally established in compiler literature that it causes no ambiguity. Prefer `lhs` and `rhs` over `left` and `right` for operand sides, as this is standard compiler convention.

---

## Branch Naming Rules

All work happens on branches off `main`. Branch names must follow this schema:

```
<type>/<short-description>
```

Valid types:

| Type | Purpose |
|---|---|
| `feature/` | New functionality |
| `fix/` | Bug fixes |
| `refactor/` | Code restructuring without behavior change |
| `docs/` | Documentation changes only |
| `test/` | Adding or updating tests |
| `perf/` | Performance improvements |
| `chore/` | Build system, tooling, CI/CD changes |

The short description should use hyphens, not underscores or spaces, and should be specific enough to convey what the branch contains.

**Examples:**

```
feature/lexer-unicode-support
fix/parser-precedence-in-binary-expressions
refactor/ir-instruction-layout
docs/codegen-architecture-overview
test/sema-type-inference-edge-cases
```

Do not use generic names like `feature/update` or `fix/bug`. If your description is that vague, the scope of the work is probably unclear.

---

## Commit Message Guidelines

Riven follows a conventional commit format. Every commit message must be structured as follows:

```
<type>(<scope>): <short summary>

<body — optional but encouraged for non-trivial changes>

<footer — optional, for issue references or breaking change notices>
```

### Type

Use the same type categories as branch naming: `feat`, `fix`, `refactor`, `docs`, `test`, `perf`, `chore`.

### Scope

The scope is the compiler component affected: `lexer`, `parser`, `ast`, `sema`, `ir`, `optimizer`, `codegen`, `assembler`, `linker`, `runtime`, `build`, `tests`, `docs`.

### Summary

- Use the imperative mood: "add support for", "fix incorrect", "remove unused"
- Do not capitalize the first letter
- Do not end with a period
- Keep it under 72 characters

### Body

Use the body to explain *why* the change was made, not *what* it does. The diff itself shows what changed. If the reason for a change is not self-evident, explain it here. Wrap at 72 characters.

### Examples

```
feat(lexer): add support for multiline string literals

Multiline string literals were not previously handled. This adds
token recognition for the `"""..."""` form. The lexer tracks newline
positions within the token for accurate source location reporting.

Closes #42
```

```
fix(parser): correct operator precedence for unary minus

Unary minus was being parsed at the same precedence level as binary
subtraction, causing `- a * b` to parse as `(-a) * b` rather than
`-(a * b)`. This is incorrect per the language specification.
```

```
refactor(ir): consolidate instruction encoding into InstructionLayout

Previously, encoding logic was spread across three files with
inconsistent assumptions about alignment. Consolidating into a single
struct reduces duplication and makes alignment rules explicit.
```

---

## Pull Request Process

1. **Ensure your branch is up to date** with `main` before opening a pull request. Rebase rather than merge to keep the history clean.

2. **Run the full test suite locally** before submitting. Pull requests that fail CI will not receive review until they pass.

3. **Fill out the pull request description.** Explain what the change does, why it is needed, and how it was tested. Reference the relevant issue number.

4. **Keep pull requests focused.** A PR that touches the lexer, redesigns the IR, and updates the build system is three PRs. Reviewers cannot effectively evaluate large, multi-concern changes.

5. **Do not merge your own pull requests.** At least one maintainer approval is required. For changes to core compiler stages, two approvals are preferred.

6. **Respond to review comments promptly.** If a review comment requires discussion, engage with it in the PR thread. If you disagree with feedback, explain your reasoning. Silence stalls the process.

7. **Squash fixup commits before the final merge.** If you pushed follow-up commits to address review feedback, squash them into logical units before the branch is merged. The project history should tell a coherent story.

---

## Code Review Expectations

Code review in Riven is a collaborative technical process, not a gatekeeping exercise. Reviewers and authors share the goal of producing correct, maintainable code.

**For authors:**
- Be open to feedback. A review comment is not a personal criticism.
- Explain your reasoning when you disagree with a suggestion. A well-reasoned disagreement is more useful than silent compliance.
- Do not take review personally. Expect detailed comments on technical decisions — this is a compiler, and details matter.

**For reviewers:**
- Be specific. "This is unclear" is not actionable. "This variable name doesn't convey that it tracks byte offsets rather than character offsets" is.
- Distinguish between required changes and suggestions. Use explicit markers such as `nit:` for minor style preferences, and reserve blocking comments for issues that affect correctness, maintainability, or alignment with project architecture.
- Review the design, not just the surface. Consider whether the change fits the compiler pipeline, maintains modularity, and handles error cases correctly.
- Approve when the code is ready. Do not hold pull requests open indefinitely over minor disagreements.

---

## Testing Requirements

All contributions to compiler functionality must include tests. The threshold for "sufficient testing" depends on the nature of the change.

### Unit Tests

Unit tests cover individual compiler components in isolation. Every new public function in a compiler stage should have unit test coverage. Test files live under `tests/unit/<component>/` and mirror the structure of the source tree.

### Integration Tests

Integration tests exercise the interaction between two or more compiler stages. When a change affects how data passes between stages (for example, how the parser populates AST nodes that the semantic analyzer reads), integration tests should verify that the pipeline behaves correctly end to end through those stages.

### End-to-End Tests

End-to-end tests compile and run Riven programs and verify output. These live under `tests/end-to-end/` and are organized by language feature. New language features must include end-to-end tests covering the expected behavior and at least one error case.

### General Rules

- Tests must pass before a pull request is eligible for review.
- Tests must be deterministic. Flaky tests will be rejected.
- Do not write tests that depend on the order other tests run.
- Test error paths, not only happy paths. The compiler must produce correct diagnostics for invalid input.
- Do not write tests that test implementation details rather than behavior. If your tests break every time you rename an internal function, they are testing the wrong thing.

---

## Documentation Requirements

### Inline Documentation

Every public function, class, and non-obvious constant in a header file must have a doc comment. Use a style consistent with the rest of the file. Document the *purpose* and any non-obvious preconditions or postconditions. Do not write comments that restate what the function signature already communicates.

```cpp
/// Returns the source location corresponding to the start of this token.
/// The location is expressed as a byte offset into the original source buffer.
/// Returns nullopt if the token was synthetically generated.
std::optional<SourceLocation> Token::startLocation() const;
```

### Architecture Documentation

When introducing a new compiler stage, subsystem, or significant data structure, include a brief document in `docs/` explaining its purpose, design decisions, and how it fits into the broader pipeline. This does not need to be long — a clear one-page overview is more valuable than an exhaustive reference that no one reads.

### Updating Existing Documentation

If your change alters the behavior of a documented interface or modifies the compiler pipeline, update the relevant documentation in the same pull request. Letting documentation drift from the implementation is a maintenance burden for everyone.

---

## Compiler Architecture Guidelines

Riven's compiler pipeline is structured as a sequence of discrete, well-defined stages:

```
Source
  → Lexer
    → Parser
      → Abstract Syntax Tree (AST)
        → Semantic Analyzer
          → Intermediate Representation (IR)
            → Optimizer
              → Code Generator
                → Assembler
                  → Linker
                    → Executable
```

This pipeline is not a suggestion. It is the architecture of the project. Every contribution must respect the following rules.

**Stage independence.** Each stage should depend only on its inputs and produce well-defined outputs. The lexer should not perform parsing. The parser should not perform type checking. The semantic analyzer should not emit IR. Stages that reach across their boundaries to perform work that belongs to another stage will not be accepted.

**Data flows forward, not backward.** Information flows from earlier stages to later ones. A later stage should not mutate data structures owned by an earlier stage. If a later stage needs to communicate information back, establish a separate, explicit channel — not a back-pointer into an earlier stage's data.

**AST nodes are the output of the parser.** The parser constructs the AST. It does not annotate it with type information, resolve names, or perform any semantic work. The AST should represent the syntactic structure of the source and nothing more.

**The IR is the abstraction boundary between front end and back end.** The optimizer and code generator work on the IR. They do not have access to AST nodes or semantic analysis structures. If information from the front end is needed in the back end, it must be encoded into the IR explicitly.

**No LLVM, no Clang, no external compiler infrastructure.** This is a hard rule. The project may use a host C++ compiler to build Riven itself, but the compiled artifacts — the lexer, parser, optimizer, assembler, and all other components — are original implementations. External compiler libraries are not permitted as dependencies.

---

## Performance Guidelines

Riven should be a fast compiler. Performance is a feature. The following principles guide performance-sensitive code.

**Measure before optimizing.** Do not optimize code that has not been identified as a bottleneck. Use benchmarks to establish baseline performance before and after changes. Claims of performance improvement must be supported by data.

**Prefer allocation-efficient data structures.** In a compiler, allocation pressure in hot paths has measurable cost. Prefer flat arrays over linked structures where access patterns permit. Use arena allocators for AST nodes and other short-lived, bulk-allocated data.

**Avoid unnecessary copies.** Pass large structures by reference. Use `std::string_view` and `std::span` to refer to existing data rather than copying it. Be explicit about when ownership is transferred.

**Cache-friendly data layout matters.** Structure fields accessed together should be laid out together. Avoid large objects with rarely-used fields mixed among frequently-used ones.

**Document non-obvious optimizations.** If a piece of code is written in an unusual way for performance reasons, say so explicitly in a comment, and include a reference to the benchmark or profiling data that motivated it.

---

## Error Handling Guidelines

Errors in Riven fall into two categories: compiler errors (problems in the user's source code) and internal errors (bugs in the compiler itself). These must be handled differently.

### Compiler Errors (User Source Problems)

- Detect and report errors at the appropriate compiler stage. A lexer error is a lexer error; do not propagate invalid tokens and let the parser emit a confusing diagnostic.
- Produce specific, actionable error messages. Include the source location, a description of what went wrong, and where possible, a suggestion for how to fix it.
- Recover gracefully where possible. The compiler should not abort on the first error if it is possible to continue and report additional errors.
- Do not use exceptions to signal compiler errors. Use result types or explicit error accumulation structures.

### Internal Errors (Compiler Bugs)

- Use `RIVEN_ASSERT` for invariants that must hold if the compiler is correct. Assertion failures indicate bugs in Riven, not problems in user code.
- Do not use assertions to validate user input. User input can be anything; assertions are for conditions that the code has already guaranteed.
- When an internal invariant is violated, fail loudly with a clear message that identifies the violated condition and the location in the source code. Silent corruption is worse than a crash.
- Do not use exceptions for control flow or error signaling in internal compiler logic. Reserve exceptions, if used at all, for truly exceptional and unrecoverable situations.

---

## Directory Organization Rules

- Source files (`.cpp`) belong under `src/<component>/`.
- Header files (`.h`) belong under `include/<component>/`.
- A source file may only include headers from its own component, from components that precede it in the pipeline, and from the standard library.
- Test files belong under `tests/<type>/<component>/`.
- Scripts and developer tools belong under `tools/`.
- Documentation belongs under `docs/`.

Do not create files in the root of the repository. Do not put headers in `src/` or implementation files in `include/`. If a new top-level directory seems necessary, discuss it in an issue before creating it.

---

## Issue Reporting

Use the GitHub issue tracker to report bugs, unexpected behavior, and build failures.

A useful bug report includes:

- The version or commit hash of Riven you are using
- Your operating system, compiler, and compiler version
- The exact steps to reproduce the issue
- The expected behavior
- The actual behavior, including any error output or crash messages
- A minimal reproducing example if applicable

Before opening an issue, search the existing issues to avoid duplicates. If you find an existing issue that matches yours, add any additional information in a comment rather than opening a new one.

Label issues accurately. Do not apply labels speculatively.

---

## Feature Requests

Feature requests are welcome, but the bar for adding complexity to a compiler project is high. When proposing a new feature, address the following:

- What problem does this solve? Describe the concrete need, not the proposed solution.
- How does this fit within the existing compiler architecture and language design?
- What is the implementation scope? Is this a change to the language itself, the compiler pipeline, a library, or tooling?
- Are there existing approaches in other languages or compiler projects that inform this design?

Features that conflict with the project's design principles, require bending the compiler pipeline, or introduce significant complexity without clear benefit will not be accepted regardless of technical quality. Opening a discussion before investing implementation effort is strongly recommended.

---

## Security Reporting

Do not report security vulnerabilities through public GitHub issues.

If you discover a security issue in Riven — including issues that could affect users compiling untrusted source code — please report it privately. Contact the maintainers directly at the email address listed in the repository's `SECURITY.md` file.

Provide a description of the issue, steps to reproduce, and your assessment of impact. We will acknowledge receipt promptly and work with you on disclosure timing.

---

## Community Expectations

Riven is a technical project. Interactions here should be professional, focused, and constructive.

- Treat everyone with respect. Disagreements about technical decisions are expected and healthy. Personal attacks, condescension, and harassment are not tolerated under any circumstances.
- Stay on topic. This is a compiler project. Keep discussions in issues, pull requests, and other project channels focused on the work.
- Assume good faith. Most people contributing to open-source projects are doing so because they care. When something is unclear or frustrating, ask for clarification before assuming bad intent.
- Do not demand timelines. Maintainers and contributors are often working on this project in their available time. Pressuring people to merge changes faster or respond immediately is not acceptable.
- Accept decisions gracefully. Not every contribution will be accepted. If your work is declined, a clear reason will be given. You may disagree, but accept the decision professionally.

These expectations apply to maintainers as well as contributors.

---

## Recognition for Contributors

Riven maintains a `CONTRIBUTORS` file at the root of the repository. Every contributor whose work is merged into the project is listed there, along with a brief description of their contributions.

Significant or sustained contributions may be recognized additionally in release notes and project documentation. Contributors who demonstrate deep knowledge of the codebase and sustained commitment to the project's principles may be invited to take on a maintainer role.

We are grateful to everyone who takes the time to understand this project, engage with its design, and improve it. Building a programming language from scratch is a long endeavor. Every careful contribution brings it closer to something real and lasting.

---

*This document is maintained by the Riven core team and is updated as the project evolves. If you have questions not answered here, open an issue with the `question` label.*
