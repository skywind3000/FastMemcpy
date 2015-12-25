Build
=====

with gcc:
> gcc -O3 -msse2 FastMemcpy.c -o FastMemcpy

with msvc:
> cl -nologo -O2 FastMemcpy.c

Features
========

* 50% speedup in avg. vs traditional memcpy in msvc 2012 or gcc 4.9
* small size copy optimized with jump table
* medium size copy optimized with sse2 vector copy 
* huge size copy optimized with cache prefetch & movntdq

Reference
=========

[Using Block Prefetch for Optimized Memory Performance](http://files.rsdn.ru/23380/AMD_block_prefetch_paper.pdf)

The artical only focused on aligned huge memory copy. You need handle other conditional by your self.


Results
=======

```
result: gcc4.9 (msvc 2012 got a similar result):
 
benchmark(size=32 bytes, times=16777216):
result(dst aligned, src aligned): memcpy_fast=78ms memcpy=260 ms
result(dst aligned, src unalign): memcpy_fast=78ms memcpy=250 ms
result(dst unalign, src aligned): memcpy_fast=78ms memcpy=266 ms
result(dst unalign, src unalign): memcpy_fast=78ms memcpy=234 ms

benchmark(size=64 bytes, times=16777216):
result(dst aligned, src aligned): memcpy_fast=109ms memcpy=281 ms
result(dst aligned, src unalign): memcpy_fast=109ms memcpy=328 ms
result(dst unalign, src aligned): memcpy_fast=109ms memcpy=343 ms
result(dst unalign, src unalign): memcpy_fast=93ms memcpy=344 ms

benchmark(size=512 bytes, times=8388608):
result(dst aligned, src aligned): memcpy_fast=125ms memcpy=218 ms
result(dst aligned, src unalign): memcpy_fast=156ms memcpy=484 ms
result(dst unalign, src aligned): memcpy_fast=172ms memcpy=546 ms
result(dst unalign, src unalign): memcpy_fast=172ms memcpy=515 ms

benchmark(size=1024 bytes, times=4194304):
result(dst aligned, src aligned): memcpy_fast=109ms memcpy=172 ms
result(dst aligned, src unalign): memcpy_fast=187ms memcpy=453 ms
result(dst unalign, src aligned): memcpy_fast=172ms memcpy=437 ms
result(dst unalign, src unalign): memcpy_fast=156ms memcpy=452 ms

benchmark(size=4096 bytes, times=524288):
result(dst aligned, src aligned): memcpy_fast=62ms memcpy=78 ms
result(dst aligned, src unalign): memcpy_fast=109ms memcpy=202 ms
result(dst unalign, src aligned): memcpy_fast=94ms memcpy=203 ms
result(dst unalign, src unalign): memcpy_fast=110ms memcpy=218 ms

benchmark(size=8192 bytes, times=262144):
result(dst aligned, src aligned): memcpy_fast=62ms memcpy=78 ms
result(dst aligned, src unalign): memcpy_fast=78ms memcpy=202 ms
result(dst unalign, src aligned): memcpy_fast=78ms memcpy=203 ms
result(dst unalign, src unalign): memcpy_fast=94ms memcpy=203 ms

benchmark(size=1048576 bytes, times=2048):
result(dst aligned, src aligned): memcpy_fast=203ms memcpy=191 ms
result(dst aligned, src unalign): memcpy_fast=219ms memcpy=281 ms
result(dst unalign, src aligned): memcpy_fast=218ms memcpy=328 ms
result(dst unalign, src unalign): memcpy_fast=218ms memcpy=312 ms

benchmark(size=4194304 bytes, times=512):
result(dst aligned, src aligned): memcpy_fast=312ms memcpy=406 ms
result(dst aligned, src unalign): memcpy_fast=296ms memcpy=421 ms
result(dst unalign, src aligned): memcpy_fast=312ms memcpy=468 ms
result(dst unalign, src unalign): memcpy_fast=297ms memcpy=452 ms

benchmark(size=8388608 bytes, times=256):
result(dst aligned, src aligned): memcpy_fast=281ms memcpy=452 ms
result(dst aligned, src unalign): memcpy_fast=280ms memcpy=468 ms
result(dst unalign, src aligned): memcpy_fast=298ms memcpy=514 ms
result(dst unalign, src unalign): memcpy_fast=344ms memcpy=472 ms

benchmark random access:
memcpy_fast=515ms memcpy=1014ms

```


About
=====
skywind
http://www.skywind.me
