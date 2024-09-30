<<<<<<< HEAD
#!/usr/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
nmcli connection modify --temporary esim ipv4.route-metric 1 ipv6.route-metric 1
nmcli con up esim
