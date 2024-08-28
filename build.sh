# create build directory if it doesnt exist
if [! -d build ]; then
    mkdir build
fi

cd build # cd into build directory
cmake .. -DMILCH_BUILD_EXAMPLES=ON # make cmake configure this directory
                                   # also build examples
cmake --build . -j # build the project w/ multi threading
