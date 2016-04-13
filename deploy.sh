#! /bin/sh

home_libs=~/libs

home_zod=${home_libs}/zod

./configure --prefix=${home_zod}

if test -d ${home_zod}; then
    rm -rf ${home_zod}
fi

make install

make distclean
