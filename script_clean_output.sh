#!/bin/sh

pushd $(dirname $0) > /dev/null

if [ -d "output" ]; then
    rm -R output
fi

popd > /dev/null
