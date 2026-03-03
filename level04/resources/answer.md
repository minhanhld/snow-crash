We see a PERL file which again has its special bit set to SUID. The file is owned by flag04, so once again we'd like it to run getflag.
We can see in the file the use of the CGI module, meaning that it's probably served on a webserver, this is confirmed by the localhost:4747 command.
After reading the code, we see that the function named x is called with the parameter param("x").
param("x") retrieves the CGI parameter named x from the URL. So for example we can run : 
curl http://localhost:4747/?x=test
This will echo test
Since the goal is to have that script basically run the getflag command, we can use command substitution, sending ${getflag} to the the script.
The script basically runs : 

print `echo ${getflag} 2>&1`;

So getflag will be executed and then the script will echo out the result.