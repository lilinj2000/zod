node=`uname -n`
home_3rd=~/3rd/${node}

boost_home=$home_3rd/boost
home_fmt=$home_3rd/fmt

export LD_LIBRARY_PATH=$boost_home/lib:$home_fmt/lib

