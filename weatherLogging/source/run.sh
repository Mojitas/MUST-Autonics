#!/bin/bash
# Todo:
# 1. Check python version
# 2. Check requirements installation
# 3. (optional) Check if code is pushed
# 4. (optional) Compile Arduino code
# 5. (optional) Push code to Arduino
initial_run=0
req_file="../requirements.txt"

function check_requirements {
  pip3 check $req_file

  if [[ "$(echo $?)" == "0" ]]; then
    echo "Requirements satisfied!"
    return
  fi

  pip3 install -r $req_file
}


while getopts 'i' c
do
  case $c in
    i)
      initial_run=1
      ;;
    *);;
  esac
done

if [[ $initial_run -eq 1 ]]; then
  check_requirements
fi

cd python/ || exit

python_version=$(python -c "import sys; print('.'.join(map(str, sys.version_info[:3])))")
case "$python_version" in
  3\..*)
    python main.py
  ;;
  *)
    python3 main.py
  ;;
esac