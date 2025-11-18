# SIIAU Project

A lightweight academic management system implemented in C, designed to practice modular architecture, repositories, and in-memory databases.
This project demonstrates clean separation between **core models**, **repositories**, and **memory-based database implementations**.

## Features

- Modular C architecture with `.h` and `.c` separation
- In-memory database (`MemoryDatabase`)
- Repository pattern for handling students
- Easy to compile and run using a Makefile
- Clean and extensible folder structure

## Build & Run

The project uses a Makefile to simplify the build process.

### **Compile the project**
```sh
make run

```
Compiles the project (if required) and executes the generated binary.
Useful for testing immediate changes.

### Clean build files

```sh
make clean
```
Removes all generated files — including the executable — restoring a clean state.
Use this before rebuilding to avoid stale or conflicting binaries.

## Prerequisites

- GCC (GNU Compiler Collection)
- Make utility
- Linux or macOS recommended (Windows users can use WSL or MinGW)
esto es una prueba 