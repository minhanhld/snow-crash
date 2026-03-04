There's a perl script again. After reading through it, we know that it's a CGI script that runs on localhost:4646.
The main things to know about what the scripts does are :
-It capitalizes every alphabetical character
-It removes everything that's after the first whitespace
-It runs a command in the shell, we know that thanks to the backticks

The main issue is that the script capitalizes everything we send, so we can't just send getflag.
Instead, we are going to create our own script in /tmp, that we will name GETFLAG.SH, which will simply contain :

#!/bin/sh

getflag > /tmp/flag

But we can't write /tmp/GETFLAG.SH since tmp will get capitalized, for that we can use the wild card ?, thus writing /???/GETFLAG.SH, making the shell look in every folders in the root folder that contains exactly 3 characters.

We can then curl the web server :

curl 'http://localhost:4646/?x=$(/???/GETFLAG.SH)'