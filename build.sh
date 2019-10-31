if [ ! "$(ls -A googletest)" ]; then
    echo "googletest submodule does not exist"
    echo "initializing submodules"
    git submodule update --init --recursive
fi

if hash cmake 2>/dev/null; then
    mkdir -p build
    cd build
    cmake ..
    make
else
    echo "cmake is not installed. Please try again with cmake installed"
fi
