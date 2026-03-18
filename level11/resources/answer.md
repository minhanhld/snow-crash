# Level 11

We can see a lua script. We see that a server is running on `localhost:5151`.
There's a function to hash the password that is asked as an input, and we can notice that in that function user input is inserted directly into a shell command without any checks:

```
;getflag > /tmp/pwd
```