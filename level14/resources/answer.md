There's nothing in the home folder, no interesting files that flag14 or level14 could execute.
Let's take a look at the getflag binary with ghidra
We can see that it uses a ft_des function to basically decrypt the token that are hardcoded in the main function.
We can take a look at the ft_des function and try to reproduce it in C.

