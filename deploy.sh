#! /bin/sh

node=`uname -n`
home_libs=~/libs/${node}

home_zod=${home_libs}/zod

./configure --prefix=${home_zod}

if test -d ${home_zod}; then
    rm -rf ${home_zod}
fi

make install

make distclean
