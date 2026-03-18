# Level 00

Intra videos hints to find all files that can ONLY be run by `flag00` user.
`find` command does exactly that:

```bash
find / -user flag00 2> /dev/null
```

This is the content of the two files that are found: `cdiiddwpgswtgt`

It's encrypted by caesar cipher ROT 15, after decryption we get the flag: `nottoohardhere`