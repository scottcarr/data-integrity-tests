#!/bin/sh
CC=~/dataconf-workspace2/buildShared/bin/clang C_FLAG='-DSPEC_CPU -DNDEBUG -g -O2 -std=gnu89 -mllvm -dataconf -fsanitize=dataconf -mllvm -debug-only=DataConf -DSPEC_CPU_LP64' cmake ../mcf
