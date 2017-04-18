# amnesia

A library for messing with memory in remote processes.  Supports (or will
support) a variety of methods.

Linux methods:

| Method name             | Notes                                             |
| ----------------------- | ------------------------------------------------- |
| ptrace                  | Safe method, intended for debuggers to read       |
|                         | memory.                                           |
| `process_vm_*` syscalls | Requires that the CONFIG_CROSS_MEMORY_ATTACH      |
|                         | kernel configuration item be enabled during       |
|                         | kernel compile.  Shouldn't be detectable by       |
|                         | remote processes unless they intercept the        |
|                         | syscall.                                          |
| page mapping            | Experimental method that maps the kernel page     |
|                         | from one process onto that of another.  No idea   |
|                         | if this will work, but it's probably safer than   |
|                         | implementing a kernel driver that does r/w.       |
|                         | Also, this obviously requires root.               |
| /proc/id/mem            | This reportedly works well for reads, but I've    |
|                         | been unable to make signifigant progress in my    |
|                         | experimentation.  Regardless, I'll attempt to     |
|                         | create a mode for this, since it apparantly works |
|                         | in usermode and is available on pretty much all   |
|                         | modern machines.

