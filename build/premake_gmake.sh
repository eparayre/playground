if [[ $(uname) == 'Darwin' ]]; then
	premake='premake/mac/premake5'
else
	premake='premake/linux/premake5'
fi

$premake gmake
