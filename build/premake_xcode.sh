#!/bin/sh

pushd $(dirname $0) > /dev/null

buildtools-premake/bin/premake.sh xcode4

popd > /dev/null
