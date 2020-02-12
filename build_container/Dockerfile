FROM alpine:3.11

ENV QMK_HOME /qmk_firmware
ENV KEYBOARD=ergodox_ez
ENV KEYMAP=default

RUN apk add --update-cache --no-cache \
        build-base \
        gcc-avr \
        avr-libc \
        git \
        python3 \
    && ln -s /usr/bin/easy_install-3.8 /usr/bin/easy_install \
    && ln -s /usr/bin/pip3 /usr/bin/pip \
    && ln -s /usr/bin/pydoc3 /usr/bin/pydoc \
    && ln -s /usr/bin/python3 /usr/bin/python

VOLUME /qmk_firmware
WORKDIR /qmk_firmware

CMD make ${KEYBOARD}:${KEYMAP}
