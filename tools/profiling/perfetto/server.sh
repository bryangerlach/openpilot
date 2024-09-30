<<<<<<< HEAD
#!/usr/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

curl -LO https://get.perfetto.dev/trace_processor
chmod +x ./trace_processor

./trace_processor --httpd
