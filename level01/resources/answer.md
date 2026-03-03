/etc/passwd shows the hash for the  password of user flag01 : 42hDRfypTqqnw
We can use John the Ripper to try and crack it, using the dictionary rockyou.txt : 
john <fileToCrack> --wordlist="rockyou.txt"
We get the password : abcdefg