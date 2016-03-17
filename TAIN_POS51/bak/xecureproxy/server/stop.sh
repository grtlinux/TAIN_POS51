#!/usr/bin/ksh

export XPROXY_HOME=/home/sso/xproxy_post/work/package/32/xecureproxy/server
export LD_LIBRARY_PATH=./lib
export SHLIB_PATH=${LD_LIBRARY_PATH}
export LIBPATH=${LD_LIBRARY_PATH}

cd ${XPROXY_HOME}

./proxy_server stop
