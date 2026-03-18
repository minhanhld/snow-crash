# Level 09

There's a binary in the home folder along with a token file.
After decompiling it and analyzing what ghidra shows us, we understand that the function hashes the input by basically adding the index to the i-th character of the input, so for example:

```
abc -> a + 0 / b + 1 / c + 2 => ace
```

Now we can see that printing the token gives us some weird character.
The solution is most likely to take that token and apply the reverse operation on it, meaning that for each char, we substract its index, and then this should give us our token to log into `flag09`.