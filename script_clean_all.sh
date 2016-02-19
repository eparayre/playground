#!/bin/bash

pushd $(dirname $0) > /dev/null

build/premake_clean.sh

./script_clean_output.sh

popd > /dev/null
