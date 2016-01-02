pushd $(dirname $0) > /dev/null

build/premake_gmake.sh

cd build/gmake
make

popd > /dev/null
