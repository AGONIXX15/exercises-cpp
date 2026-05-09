

cmake . -B build  && \
make -C build && \
echo "copying compile_commands.json to root" && \
cp build/compile_commands.json . && \
build/test2
