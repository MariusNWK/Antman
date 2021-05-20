#!/bin/bash
cd ../antman/
make
time ./antman ../tests/$1 1 > compressed
mv compressed ../tests/
make fclean
cd ../giantman/
make
time ./giantman ../tests/compressed 1 > decompressed
mv decompressed ../tests/
make fclean
cd ../tests/
gcc -o test *.c -I include/
./test $1 compressed decompressed
rm test
rm compressed
rm decompressed