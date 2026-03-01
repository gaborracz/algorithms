# Info

## Scope

I created this project to store my source files created during the
Algorithms I. course on ELTE.

## Environment

```sh
➜  g++ --version
g++-15 (Homebrew GCC 15.2.0) 15.2.0
Copyright (C) 2025 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## Compile

```sh
g++ -W -Wall --pedantic StackMain.cpp
```

Compile QueueMain when Student class is used:

```sh
g++ -W -Wall --pedantic QueueMain.cpp Student.cpp
```

## Check memory leaks

```sh
leaks --atExit -- ./a.out
```

```sh
➜  leaks --atExit -- ./a.out
a.out(45896) MallocStackLogging: could not tag MSL-related memory as no_footprint, so those pages will be included in process footprint - No such file or directory (2)
a.out(45896) MallocStackLogging: recording malloc (and VM allocation) stacks using lite mode
intStack size is: 0
size of size_t is: 8
intStack size is: 1
Top element in the stack: 1
Lord of the Rings.
Process 45896 is not debuggable. Due to security restrictions, leaks can only show or save contents of readonly memory of restricted processes.

Process:         a.out [45896]
Path:            /Users/USER/*/a.out
Load Address:    0x100b70000
Identifier:      a.out
Version:         0
Code Type:       ARM64
Platform:        macOS
Parent Process:  leaks [45895]
Target Type:     live task

Date/Time:       2026-03-01 15:47:58.398 +0100
Launch Time:     2026-03-01 15:47:45.334 +0100
OS Version:      macOS 26.2 (25C56)
Report Version:  7
Analysis Tool:   /usr/bin/leaks

Physical footprint:         4.0G
Physical footprint (peak):  7.0G
Idle exit:                  untracked
----

leaks Report Version: 4.0, multi-line stacks
Process 45896: 189 nodes malloced for 96 KB
Process 45896: 0 leaks for 0 total leaked bytes.
```

# Algorithms

## Stack

The stack.h is my C++ implementation of the linear LIFO data structure called stack.
Its written in a template class to support any primitive data type or object.
Memory management is implemented with std::allocator instead of new and delete. This guarantees a few important things:
- Memory allocation is separated from object condition, so objects that can only be constructed with values specified in the formal parameter list can be added.
- Also, objects are not constructed automatically when allocating memory which would cause significant overheads when dealing with "expensive" objects and a huge stack size.
- Option to use special allocators like pool, stack or shared memory allocator.

## Queue

The queue.h is my C++ implementation of the linear FIFO data structure called the queue.
This is an Array-based circular buffer.
It's also written in a template class to support primitive data types and objects. Memory management is implemented with std::allocator.
