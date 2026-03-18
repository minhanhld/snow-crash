# Level 08

We see a binary and a token file.
We decompile the file to see what it does:

It runs the `strstr` function on the first argument and `"token"`, meaning that if it finds `"token"` in the filename, it will return a pointer to the beginning of that string, else it will return a `NULL` pointer.

Then it checks the result, if the pointer is different from `NULL`, basically meaning that if there IS `token` in the filename, then it says that the file is not accessible and exits immediately.

Obviously we don't have the permissions to rename the file or access it.
And looking further into the file, there's nothing we could inject if we were to create our own file, the program just prints the content of a file.

What we can do though is create a symlink to that token file, since the program is only checking for the name and nothing else.

We can do so by running:

```bash
ln -s /home/user/level08/token /tmp/test
```

And then run:

```bash
./level08 /tmp/test
```

There is our token.