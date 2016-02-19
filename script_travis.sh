#!/bin/bash

pushd $(dirname $0) > /dev/null

build/premake_gmake.sh
r=$?

if [[ $r -eq 0 ]]; then
    cd build/gmake

    make
    r=$?
fi

popd > /dev/null

exit $r
