<<<<<<< HEAD
#!/usr/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null && pwd)"
cd $DIR

OUT=trace_
sudo ./tracebox -o $OUT --txt -c configs/scheduling.cfg
sudo chown $USER:$USER $OUT
