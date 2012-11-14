# CUL - C++ Utility Library 

## Dependencies

* Linux/Windows
* Modern C++ Compiler (GCC)


## Design Principles

* KISS - Keep it small and simple
* Lightweight - Keep bloat out
* Cross Platform (currently aiming for linux/posix and windows, mac osx support can added easily)
* Documentation - Try to provide well documented code and examples
* C++11 - Don't live in the past
* Modern Interface - Usage similiar to Java, D Tango or .NET Framework 
* Loose coupling - so classes can be easily copied out of library and work anyway

## Modules

* culcore - Core Library (Header only)
* culio - Input/Output Library (File, Console, ...)
* culsys - System Interfaces (Threads, Timer, ...)
* cullog - Logging Framework (Requires Rewrite)
* culnet - Network Library

## Available functionality:

* Reference Counted Shared Pointer
* Strings
* Simple Typedefs
* Logging
* Threads

## Planned features:

* UTF Support
* IO (file handling, directory iteration, ...)
* More Datastructures (Array, Stack, Sets/Maps, ...)
* Network
* Advanced Memory Management (Allocators, MemPools, ...)
* Use PIMPL for Binary Compatibility
* Rewrite logging system using C++11 features
 
