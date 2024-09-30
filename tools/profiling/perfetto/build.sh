<<<<<<< HEAD
#!/usr/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

if [ ! -d perfetto ]; then
  git clone https://android.googlesource.com/platform/external/perfetto/
fi

cd perfetto

tools/install-build-deps --linux-arm
tools/gn gen --args='is_debug=false target_os="linux" target_cpu="arm64"' out/linux
tools/ninja -C out/linux tracebox traced traced_probes perfetto
