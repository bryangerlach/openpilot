<<<<<<< HEAD
#!/usr/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null && pwd)"

export FINGERPRINT="TOYOTA_COROLLA_TSS2"
export SKIP_FW_QUERY="1"
$DIR/../launch_openpilot.sh
