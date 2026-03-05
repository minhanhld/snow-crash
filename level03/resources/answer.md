We have a file with special bit set, meaning that the file executes as the user who owns the file here.
If we run : stat '%U' level03
we can see that the user owning the file is flag03.
Using ghidra or gdb, we can see that in the source code, the binary is using /usr/bin/env to echo his message.
We can override the shell echo by prepending a path to PATH :
export PATH="/ourPath:$PATH"
and creating our own fake echo.
The only place where we have permissions to create files is /tmp, so we create our file named echo inside it.
This file should launch getflag, so we simply put getflag in it.
We give it execution permission with chmod, and then we can just execute level03 to get our token.