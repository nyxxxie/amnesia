# amnesia

A library for messing with memory in remote processes.  Supports a variety of
methods.

Linux methods:
Method name             | Notes
-------------------------------------------------------------------------------
ptrace                  | Safe, intended way for debuggers to read memory.
`process_vm_*` syscalls | Requires ptrace permission, shouldn't be detectable by remote process.
kernel module           | Unsafe but undetectable (unless remote process explititly looks for the km).
