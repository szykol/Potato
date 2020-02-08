submodules=(`grep "path =" .gitmodules | awk '{ print $3 }'`)

for submdl in ${submodules[@]}; do
    if [ ! "$(ls -A $submdl)" ]; then
        echo "one or more modules does not exist"
        echo "initializing submodules"
        git submodule update --init --recursive
        break
    fi
done

if hash cmake 2>/dev/null; then
    mkdir -p build
    cd build
    if [ "$1" = "debug" ]; then
        echo "Running cmake with debug flag"
        cmake -DCMAKE_BUILD_TYPE=Debug ..
    else
        echo "Running cmake without debug flag"
        cmake ..
    fi
    make -j4
else
    echo "CMake is not installed. Please try again with CMake installed"
fi
