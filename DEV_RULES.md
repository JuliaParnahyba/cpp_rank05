# 📏 Development Conventions — C++ Rank 05

This document defines the development standards used in this repository.
Its purpose is to ensure **consistency, readability, and maintainability**, aligned with the expectations of the 42 curriculum.

---

# Philosophy

This project follows the core principles of 42:

* Code must be **understood, not just written**
* Clarity is more important than cleverness
* Every decision must be explainable during evaluation
* Learning > speed

---

# Project Structure

## Global Structure

```bash
cpp_rank05/
├── README.md
├── docs/
├── cpp05/
├── cpp06/
├── cpp07/
├── cpp08/
└── cpp09/
```

## Exercise Structure

```bash
cpp05/ex00/
├── Makefile
├── main.cpp
├── include/
└── src/
```

---

# Compilation Rules

All projects must compile with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

Failure to compile under these flags is considered a **critical error**.

---

# Naming Conventions

## Classes

* Must follow: `UpperCamelCase`

Example:

```cpp
Bureaucrat
Form
Span
```

## Files

* Must match class name:

```bash
Bureaucrat.hpp
Bureaucrat.cpp
```

## Functions and variables

* Use descriptive names in English
* Prefer `camelCase`

---

# Code Design Rules

## Orthodox Canonical Form (OCF)

All classes (CPP02 → CPP09) must implement:

* Default constructor
* Copy constructor
* Copy assignment operator
* Destructor

Unless explicitly stated otherwise.

---

## Headers

* Must be **self-contained**
* Must include all dependencies
* Must use include guards

---

## Implementation Rules

* No function implementation in `.hpp`
* Exception: Templates (CPP07)

---

## Memory Management

* No memory leaks allowed
* Every `new` must have a corresponding `delete`

---

# 🚫 Restrictions

## Forbidden (unless explicitly allowed)

* `printf`, `malloc`, `free`
* `using namespace`
* `friend`
* External libraries (Boost, C++11+)

---

## STL Usage

| Module      | STL Usage   |
| ----------- | ----------- |
| CPP05–CPP07 | Forbidden |
| CPP08–CPP09 | Required  |

---

# Git Workflow

## Branching Strategy

### One branch per exercise:

```bash
feature/cpp05-ex00
feature/cpp05-ex01
feature/cpp06-ex00
```

### Auxiliary branches:

```bash
fix/cpp05-ex00
refactor/cpp05-ex00
docs/repo
chore/repo
```

---

## Commit Convention (Conventional Commits)

Format:

```bash
type(scope): message
```

### Types

* `feat` → new feature
* `fix` → bug fix
* `refactor` → code improvement (no behavior change)
* `docs` → documentation
* `test` → tests
* `chore` → setup / maintenance

---

### Scope

```bash
cpp05/ex00
cpp05/ex01
cpp06/ex00
repo
docs
```

---

### Examples

```bash
chore(repo): initialize repository structure
docs(repo): add development conventions
feat(cpp05/ex00): create Bureaucrat class
fix(cpp05/ex00): validate grade boundaries
refactor(cpp05/ex01): simplify form logic
test(cpp05/ex02): add execution tests
```

---

# Testing Strategy

* Each exercise must include a `main.cpp`
* `main.cpp` acts as:
  * manual test
  * validation tool
  * defense preparation

---

# Documentation Rules

## docs/ structure

* `subjects/` → official PDFs
* `notes/` → learning notes
* `diagrams/` → UML and architecture

---

# Evaluation Readiness

During peer evaluation, you must be able to:

* Explain every class and method
* Modify code quickly
* Justify design decisions
* Handle edge cases

---

# Important Notes

* Code readability is critical
* Over-engineering is penalized
* Unclear code = failed evaluation

---

# Development Workflow

For each exercise:

1. Create branch
2. Setup structure
3. Implement step-by-step
4. Test via `main.cpp`
5. Refactor
6. Commit in small increments
7. Merge to main

---

# Final Goal

Build a repository that is:

* Clean
* Understandable
* Defensible
* Aligned with 42 standards
* Ready for peer evaluation

---
