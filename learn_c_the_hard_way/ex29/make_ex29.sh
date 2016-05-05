cc -fPIC -c libex29.c -o libex29.o
cc -shared -o libex29.so libex29.o
cc -Wall -g -DNDEBUG ex29.c -ldl -o ex29
