#!/bin/bash
PREVIOUS_DIR=$(pwd)
CURRENTS_DIR=$(cd $(dirname $0); pwd)
CMDNAME=$(basename $0)

IMAGE_NAME=arielase/qmkbuild:builder-alpine-3.11

cd ${CURRENTS_DIR}
docker build -t ${IMAGE_NAME} .

trivy --clear-cache
trivy --exit-code 1 ${IMAGE_NAME}
if [ $? -eq 1 ]; then
    exit 1
fi

docker login
docker push ${IMAGE_NAME}
cd ${PREVIOUS_DIR}
