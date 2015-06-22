cd build

chmod +x premake/linux/premake5
premake/linux/premake5 gmake

cd gmake
ls
make
