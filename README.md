Build
=====

using gcc:
> gcc -O3 -msse2 FastMemcpy.c -o FastMemcpy

using msvc:
> cl -nologo -O2 FastMemcpy.c

Features
========

* 40% speedup in avg. vs traditional memcpy in msvc 2012 or gcc 4.9
* cache optimized copy
* small size copy optimized 
* medium size copy optimized

Reference
=========

[Using Block Prefetch for Optimized Memory Performance](http://files.rsdn.ru/23380/AMD_block_prefetch_paper.pdf)

The artical only focused on aligned huge memory copy. You need handle other conditional by your self.


Results
=======

```
result: gcc4.9 (msvc 2012 got a similar result):
 
benchmark(size=32 bytes, times=16777216):
result(dst aligned, src aligned): memcpy_fast=180ms memcpy=249 ms
result(dst aligned, src unalign): memcpy_fast=170ms memcpy=271 ms
result(dst unalign, src aligned): memcpy_fast=179ms memcpy=269 ms
result(dst unalign, src unalign): memcpy_fast=180ms memcpy=260 ms
 
benchmark(size=64 bytes, times=16777216):
result(dst aligned, src aligned): memcpy_fast=162ms memcpy=300 ms
result(dst aligned, src unalign): memcpy_fast=199ms memcpy=328 ms
result(dst unalign, src aligned): memcpy_fast=410ms memcpy=339 ms
result(dst unalign, src unalign): memcpy_fast=390ms memcpy=361 ms
 
benchmark(size=512 bytes, times=8388608):
result(dst aligned, src aligned): memcpy_fast=160ms memcpy=241 ms
result(dst aligned, src unalign): memcpy_fast=200ms memcpy=519 ms
result(dst unalign, src aligned): memcpy_fast=313ms memcpy=509 ms
result(dst unalign, src unalign): memcpy_fast=311ms memcpy=520 ms
 
benchmark(size=1024 bytes, times=4194304):
result(dst aligned, src aligned): memcpy_fast=145ms memcpy=179 ms
result(dst aligned, src unalign): memcpy_fast=180ms memcpy=430 ms
result(dst unalign, src aligned): memcpy_fast=245ms memcpy=430 ms
result(dst unalign, src unalign): memcpy_fast=230ms memcpy=455 ms
 
benchmark(size=4096 bytes, times=524288):
result(dst aligned, src aligned): memcpy_fast=80ms memcpy=80 ms
result(dst aligned, src unalign): memcpy_fast=110ms memcpy=205 ms
result(dst unalign, src aligned): memcpy_fast=110ms memcpy=224 ms
result(dst unalign, src unalign): memcpy_fast=110ms memcpy=200 ms
 
benchmark(size=8192 bytes, times=262144):
result(dst aligned, src aligned): memcpy_fast=70ms memcpy=78 ms
result(dst aligned, src unalign): memcpy_fast=100ms memcpy=222 ms
result(dst unalign, src aligned): memcpy_fast=100ms memcpy=210 ms
result(dst unalign, src unalign): memcpy_fast=100ms memcpy=230 ms
 
benchmark(size=1048576 bytes, times=2048):
result(dst aligned, src aligned): memcpy_fast=200ms memcpy=201 ms
result(dst aligned, src unalign): memcpy_fast=260ms memcpy=270 ms
result(dst unalign, src aligned): memcpy_fast=263ms memcpy=361 ms
result(dst unalign, src unalign): memcpy_fast=267ms memcpy=321 ms
 
benchmark(size=4194304 bytes, times=512):
result(dst aligned, src aligned): memcpy_fast=281ms memcpy=391 ms
result(dst aligned, src unalign): memcpy_fast=265ms memcpy=407 ms
result(dst unalign, src aligned): memcpy_fast=313ms memcpy=453 ms
result(dst unalign, src unalign): memcpy_fast=282ms memcpy=439 ms
 
benchmark(size=8388608 bytes, times=256):
result(dst aligned, src aligned): memcpy_fast=266ms memcpy=422 ms
result(dst aligned, src unalign): memcpy_fast=250ms memcpy=407 ms
result(dst unalign, src aligned): memcpy_fast=297ms memcpy=516 ms
result(dst unalign, src unalign): memcpy_fast=281ms memcpy=436 ms
```


