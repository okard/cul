CUL - C++ Utility Library 
==========================

Dependencies
--------------------------
* Linux/Windows
* Modern C++ Compiler (GCC)


Design Principles
--------------------------
* KISS - Keep it small and simple
* Lightweight
* Loose coupling - so classes can be easily copied out of library and work anyway
* Cross Platform (currently aiming for linux/posix and windows, mac osx support can added easily)
* Documentation - Try to provide well documented code
* C++11


Available functionality:
-----------------------------------

* Reference Counted Shared Pointer
* Strings
* Simple Typedefs
* Logging
* Threads

Planned features:
------------------------------------
* UTF Support
* IO (file handling, directory iteration, ...)
* More Datastructures (Array, Stack, Sets/Maps, ...)
* Network
* Advanced Memory Management (Allocators, MemPools, ...)
* Split into modules
  - culc: CUL Core Library Header Only
  - culio: CUL I/O Library -> Console, File Handling, Text Handling
  - culsys: CUL System Library -> Threads, Dynlibs, ...
  - culnet: CUL Network Library -> Sockets, ...
  - cullog: CUL Logging Library -> Log Features
* Use PIMPL for Binary Compatibility
* Rewrite logging system using C++11 features
 
