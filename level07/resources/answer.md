# Level 07

We can see a `level07` file, again owned by `flag07` and with the special bit set to SUID.
We decompile the file and see that it echos the `LOGNAME` that is in the environment.
We can easily override that logname with `export`, thus making the file run the command we want:

```bash
export LOGNAME="; getflag"
./level07
```