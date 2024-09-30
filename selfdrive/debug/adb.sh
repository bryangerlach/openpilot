<<<<<<< HEAD
#!/usr/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
set -e

PORT=5555

setprop service.adb.tcp.port $PORT
sudo systemctl start adbd

IP=$(echo $SSH_CONNECTION | awk '{ print $3}')
echo "then, connect on your computer:"
echo "adb connect $IP:$PORT"
