# Level 02

We see that there is a `level02.pcap` file in the home folder of user `level02`.
A PCAP file is a Packet Capture file used to store network traffic captured during packet sniffing. We can read it using a tool such as wireshark.

```bash
scp myfile.txt vagrant@192.168.56.10:/home/vagrant/
```

We can run this to transfer the file from the SnowCrash to our utility VM.
We can then read that file using wireshark.
We can find in the packets that the user typed:

```
ft_waNDReL0L
```