pushd $(dirname $0) > /dev/null

if [ -d "gmake" ]; then
    rm -R gmake
fi

if [ -d "xcode4" ]; then
  rm -R xcode4
fi

popd > /dev/null
