<<<<<<< HEAD
#!/usr/bin/bash
=======
#!/usr/bin/env bash
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
set -e

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null && pwd)"
cd $DIR

if [ ! -z "$(git status --porcelain)" ]; then
  echo "Dirty working tree after build:"
  git status --porcelain
  exit 1
fi
