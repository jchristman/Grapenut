How to Grapenut
---------------

```
$ ./new_project.py PROJECT_NAME
$ cd projects/PROJECT_NAME

// Write some C code in main.c. For a list of functions that work, see the syscall.h

$ cd ../..
$ ./mk_shellcode.py PROJECT_NAME
$ cd projects/PROJECT_NAME
$ gcc main -o test -m32 -masm=intel
$ cd ../..
$ ./shellcode_to_py.py PROJECT_NAME
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