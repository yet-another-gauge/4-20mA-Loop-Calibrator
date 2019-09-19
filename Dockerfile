FROM ubuntu:latest

LABEL maintainer="Ivan Dyachenko <vandyachen@gmail.com>"

ARG TOOLCHAIN_SHORT_VERSION
ARG TOOLCHAIN_LONG_VERSION

ENV TOOLCHAIN_SHORT_VERSION ${TOOLCHAIN_SHORT_VERSION:-"8-2019q3"}
ENV TOOLCHAIN_LONG_VERSION ${TOOLCHAIN_LONG_VERSION:-"gcc-arm-none-eabi-8-2019-q3-update"}

RUN apt update
RUN apt install -y bzip2 wget

RUN wget -qO - https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/${TOOLCHAIN_SHORT_VERSION}/RC1.1/${TOOLCHAIN_LONG_VERSION}-linux.tar.bz2 | tar -xj
ENV PATH "${TOOLCHAIN_LONG_VERSION}/bin:$PATH"

RUN apt clean autoclean
RUN apt autoremove -y

RUN rm -rf /var/lib/apt/lists/*
