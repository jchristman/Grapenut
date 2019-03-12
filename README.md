How to Grapenut
---------------

Note 1: This is currently very manual for compilation (3 different scripts need to be run).
The plan is to combine all of the steps from `mk_shellcode.py` onwards into a single script.

Note 2: The following is the single caveat I have found so far:

```C
// Don't do this
char * tmp = "Hello, world";    // This will place the string in .rodata and point to it

// Instead do this
char tmp[] = "Hello, world";    // This will assign the string in the local function scope
```

Turns out the only way to get strings to not be in `.rodata` is the second method above.
This includes having issues with `#define TMP "/bin/bash"`. This will not work how you
expect it to.

Finally -- here's how to use the tools.

```
$ ./new_project.py PROJECT_NAME
$ cd projects/PROJECT_NAME

// Write some C code in main.c. For a list of functions that work, see the syscall.h

$ cd ../..
$ ./mk_shellcode.py PROJECT_NAME                # combines asm functions into syscall.c
$ cd projects/PROJECT_NAME
$ gcc main -o test -m32 -masm=intel             # compiles to an ELF
$ cd ../..
$ ./shellcode_to_py.py --binary=path/to/elf     # rips main out of the binary and returns the bytes
```

Supported Architectures
-----------------------

- [x] x86
- [ ] x86_64

Implemented Syscall Functions
-----------------------------

- [x] read
- [x] write
- [x] open
- [x] close
- [x] exit
- [x] mmap
- [ ] munmap
- [x] execve
- [x] socket
- [x] connect
- [ ] bind
- [ ] alarm
- [ ] kill
- [ ] dup

Implemented Convenience Functions
---------------------------------

- [ ] strcpy
- [ ] memcpy

Planned Additional Features
---------------------------

- [ ] combine build process into a single script
- [ ] add some sed-like features for complicated things like:
    - [ ] IP replacement with integers (to bypass .rodata and complicated inet_aton support)