How to Grapenut
---------------

Note: This is currently not nice. The plan is to combine all of the steps from
`mk_shellcode.py` onwards into a single script.

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

- [ ] x86
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