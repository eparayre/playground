#!/bin/bash

pushd $(dirname $0) > /dev/null

buildtools-premake/bin/premake.sh gmake

popd > /dev/null
