#!/bin/bash

if [ $# -ne 2 ]; then
    echo "syntax: $0 <btcdeb root dir> <aixcoin core root dir>"
    exit 1
fi

b=$PWD
cd "$1"
bd_src=$PWD
cd "$b"
cd "$2"
bc_src=$PWD
cd "$b"

if [ ! -e "$bd_src/extras/reset-to-core.sh" ]; then
    echo "invalid btcdeb dir: $bd_src (looked for $bd_src/extras/reset-to-core.sh, but could not find it)"
    exit 1
fi

if [ ! -e "$bc_src/src/script/interpreter.h" ]; then
    echo "invalid aixcoin core dir: $bc_src (looked for $bc_src/src/script/interpreter.h, but could not find it)"
    exit 1
fi

cd "$bd_src"

# aixcoin/src/ -> btcdeb/

for i in *.h *.cpp; do
    if [ -e "$bc_src/src/$i" ]; then
        cp "$bc_src/src/$i" .
    fi
done

# .h only dirs

for j in compat policy; do
    for i in $j/*.h; do
        if [ -e "$bc_src/src/$i" ]; then
            cp "$bc_src/src/$i" $j/
        fi
    done
done

# .h and .cpp dirs

for j in crypto primitives script support util; do
    for i in $j/*.h $j/*.cpp; do
        if [ -e "$bc_src/src/$i" ]; then
            cp "$bc_src/src/$i" $j/
        fi
    done
done
