#!/bin/bash
PREVIOUS_DIR=$(pwd)
CURRENTS_DIR=$(cd $(dirname $0); pwd)
CMDNAME=$(basename $0)

KEYBOARD=${1:-ergodox_ez}
KEYMAP=${2:-default}

IMAGE_NAME=arielase/qmkbuild:builder-alpine-3.11

cd ${CURRENTS_DIR}
docker run -it --rm -e KEYBOARD=${KEYBOARD} -e KEYMAP=${KEYMAP} -v ${CURRENTS_DIR}:/qmk_firmware ${IMAGE_NAME}
cd ${PREVIOUS_DIR}
