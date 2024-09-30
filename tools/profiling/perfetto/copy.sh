<<<<<<< HEAD
#!/usr/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

DEST=tici:/data/openpilot/selfdrive/debug/profiling/perfetto

scp -r perfetto/out/linux/tracebox $DEST
scp -r perfetto/test/configs $DEST
