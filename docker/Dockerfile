FROM ubuntu:noble

RUN userdel -r ubuntu

RUN apt update && apt install -y \
    build-essential \
    make \
    cmake \
    gdb \
    git

ARG UID=1000
RUN useradd -m -u ${UID} -s /bin/bash builder
USER builder