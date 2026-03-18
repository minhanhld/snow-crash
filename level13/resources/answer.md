# Level 13

After decompiling the binary with ghidra, we see that the binary isn't too complicated, it calls `getuid` and checks if the UID is equal to `4242`, if not it exits.
There aren't any users with that UID, and we can't create one.
An option is to use GDB and skip the part of the code where `getuid` is called. We can set a breakpoint with `break` right before, and then jump to the section of the code that calls `ft_des`.