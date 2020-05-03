rm -rf _build

mkdir _build && cd _build

cmake .. -G "Unix Makefiles"

cmake --build .

cd ..

cd _build/

./cpp_cmake


