pushd $(dirname $0) > /dev/null

if [[ $(uname) == 'Darwin' ]]; then
	premake='premake/mac/premake5'
else
	premake='premake/linux/premake5'
fi

$premake gmake

popd > /dev/null
