#!/bin/bash
PREVIOUS_DIR=$(pwd)
CURRENTS_DIR=$(cd $(dirname $0); pwd)
CMDNAME=$(basename $0)

IMAGE_NAME=arielase/qmkbuild:builder-alpine-3.11

cd ${CURRENTS_DIR}
make attack25:ariela
make claw44:ariela
make ergo42:ariela
make ergo42:ariela-clipstudio
make fortitude60:ariela
make helix/rev2:arielix
make helix/rev2:cscade
make helix/rev2:ffpad
make namecard2x4:clipstudio
make namecard2x4:clipstudio4ariela
make ut472:ariela

mkdir -p ${CURRENTS_DIR}/myfirmwares
/bin/cp -f ${CURRENTS_DIR}/.build/*.hex ${CURRENTS_DIR}/myfirmwares

cd ${PREVIOUS_DIR}
