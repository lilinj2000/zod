#! /bin/sh

home_libs=~/libs

if test -d /llj/libs ; then
   home_libs=/llj/libs
fi

home_zod=${home_libs}/zod

./configure --prefix=${home_zod}

if test -d ${home_zod}; then
    rm -rf ${home_zod}
fi

make install

make distclean
