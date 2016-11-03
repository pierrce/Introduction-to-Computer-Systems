all: cache1Db4 cache1Db32 cache1Db64 cache2Drowsb64 cache2Dcolsb64 cache1D cache2Drows cache2Dcols

cache1Db4: cache1D
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 4 -ds 16384 -da 1 -db 4 -- cache1D

cache1Db32: cache1D
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 32 -ds 16384 -da 1 -db 32 -- cache1D

cache1Db64: cache1D
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 64 -ds 16384 -da 1 -db 64 -- cache1D

cache2Drowsb64: cache2Drows
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 64 -ds 16384 -da 1 -db 64 -- cache2Drows

cache2Dcolsb64: cache2Dcols
	/p/course/cs354-common/public/cache/pin -t /p/course/cs354-common/public/cache/source/tools/Memory/obj-ia32/allcache.so -is 16384 -ia 1 -ib 64 -ds 16384 -da 1 -db 64 -- cache2Dcols

cache1D: cache1D.c
	gcc -o cache1D cache1D.c -Wall -m32

cache2Drows: cache2Drows.c
	gcc -o cache2Drows cache2Drows.c -Wall -m32

cache2Dcols: cache2Dcols.c
	gcc -o cache2Dcols cache2Dcols.c -Wall -m32


