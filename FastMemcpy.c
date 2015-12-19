//=====================================================================
//
// FastMemcpy.c - skywind3000@163.com, 2012
//
// feature:
// 40% speed up in avg. vs standard memcpy (tested in vc2012/gcc4.9)
//
//=====================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <emmintrin.h>

void *memcpy_tiny(void *dst, const void *src, size_t len)
{
    if (len <= 64) {
        register unsigned char *dd = (unsigned char*)dst + len;
        register const unsigned char *ss = (const unsigned char*)src + len;
        switch (len) {
        case 68:    *((int*)(dd - 68)) = *((int*)(ss - 68));
        case 64:    *((int*)(dd - 64)) = *((int*)(ss - 64));
        case 60:    *((int*)(dd - 60)) = *((int*)(ss - 60));
        case 56:    *((int*)(dd - 56)) = *((int*)(ss - 56));
        case 52:    *((int*)(dd - 52)) = *((int*)(ss - 52));
        case 48:    *((int*)(dd - 48)) = *((int*)(ss - 48));
        case 44:    *((int*)(dd - 44)) = *((int*)(ss - 44));
        case 40:    *((int*)(dd - 40)) = *((int*)(ss - 40));
        case 36:    *((int*)(dd - 36)) = *((int*)(ss - 36));
        case 32:    *((int*)(dd - 32)) = *((int*)(ss - 32));
        case 28:    *((int*)(dd - 28)) = *((int*)(ss - 28));
        case 24:    *((int*)(dd - 24)) = *((int*)(ss - 24));
        case 20:    *((int*)(dd - 20)) = *((int*)(ss - 20));
        case 16:    *((int*)(dd - 16)) = *((int*)(ss - 16));
        case 12:    *((int*)(dd - 12)) = *((int*)(ss - 12));
        case  8:    *((int*)(dd - 8)) = *((int*)(ss - 8));
        case  4:    *((int*)(dd - 4)) = *((int*)(ss - 4));
                    break;
        case 67:    *((int*)(dd - 67)) = *((int*)(ss - 67));
        case 63:    *((int*)(dd - 63)) = *((int*)(ss - 63));
        case 59:    *((int*)(dd - 59)) = *((int*)(ss - 59));
        case 55:    *((int*)(dd - 55)) = *((int*)(ss - 55));
        case 51:    *((int*)(dd - 51)) = *((int*)(ss - 51));
        case 47:    *((int*)(dd - 47)) = *((int*)(ss - 47));
        case 43:    *((int*)(dd - 43)) = *((int*)(ss - 43));
        case 39:    *((int*)(dd - 39)) = *((int*)(ss - 39));
        case 35:    *((int*)(dd - 35)) = *((int*)(ss - 35));
        case 31:    *((int*)(dd - 31)) = *((int*)(ss - 31));
        case 27:    *((int*)(dd - 27)) = *((int*)(ss - 27));
        case 23:    *((int*)(dd - 23)) = *((int*)(ss - 23));
        case 19:    *((int*)(dd - 19)) = *((int*)(ss - 19));
        case 15:    *((int*)(dd - 15)) = *((int*)(ss - 15));
        case 11:    *((int*)(dd - 11)) = *((int*)(ss - 11));
        case  7:    *((int*)(dd - 7)) = *((int*)(ss - 7));
                    *((int*)(dd - 4)) = *((int*)(ss - 4));
                    break;
        case  3:    *((short*)(dd - 3)) = *((short*)(ss - 3));
                    dd[-1] = ss[-1];
                    break;
        case 66:    *((int*)(dd - 66)) = *((int*)(ss - 66));
        case 62:    *((int*)(dd - 62)) = *((int*)(ss - 62));
        case 58:    *((int*)(dd - 58)) = *((int*)(ss - 58));
        case 54:    *((int*)(dd - 54)) = *((int*)(ss - 54));
        case 50:    *((int*)(dd - 50)) = *((int*)(ss - 50));
        case 46:    *((int*)(dd - 46)) = *((int*)(ss - 46));
        case 42:    *((int*)(dd - 42)) = *((int*)(ss - 42));
        case 38:    *((int*)(dd - 38)) = *((int*)(ss - 38));
        case 34:    *((int*)(dd - 34)) = *((int*)(ss - 34));
        case 30:    *((int*)(dd - 30)) = *((int*)(ss - 30));
        case 26:    *((int*)(dd - 26)) = *((int*)(ss - 26));
        case 22:    *((int*)(dd - 22)) = *((int*)(ss - 22));
        case 18:    *((int*)(dd - 18)) = *((int*)(ss - 18));
        case 14:    *((int*)(dd - 14)) = *((int*)(ss - 14));
        case 10:    *((int*)(dd - 10)) = *((int*)(ss - 10));
        case  6:    *((int*)(dd - 6)) = *((int*)(ss - 6));
        case  2:    *((short*)(dd - 2)) = *((short*)(ss - 2));
                    break;
        case 65:    *((int*)(dd - 65)) = *((int*)(ss - 65));
        case 61:    *((int*)(dd - 61)) = *((int*)(ss - 61));
        case 57:    *((int*)(dd - 57)) = *((int*)(ss - 57));
        case 53:    *((int*)(dd - 53)) = *((int*)(ss - 53));
        case 49:    *((int*)(dd - 49)) = *((int*)(ss - 49));
        case 45:    *((int*)(dd - 45)) = *((int*)(ss - 45));
        case 41:    *((int*)(dd - 41)) = *((int*)(ss - 41));
        case 37:    *((int*)(dd - 37)) = *((int*)(ss - 37));
        case 33:    *((int*)(dd - 33)) = *((int*)(ss - 33));
        case 29:    *((int*)(dd - 29)) = *((int*)(ss - 29));
        case 25:    *((int*)(dd - 25)) = *((int*)(ss - 25));
        case 21:    *((int*)(dd - 21)) = *((int*)(ss - 21));
        case 17:    *((int*)(dd - 17)) = *((int*)(ss - 17));
        case 13:    *((int*)(dd - 13)) = *((int*)(ss - 13));
        case  9:    *((int*)(dd - 9)) = *((int*)(ss - 9));
        case  5:    *((int*)(dd - 5)) = *((int*)(ss - 5));
        case  1:    dd[-1] = ss[-1];
                    break;
        case 0:
        default: break;
        }
        return dd;
    }   else {
        return memcpy(dst, src, len);
    }
}

void* memcpy_fast(void *destination, const void *source, size_t size)
{
	unsigned char *dst = (unsigned char*)destination;
	const unsigned char *src = (const unsigned char*)source;
	static size_t cachesize = 0x10000;
	size_t diff;

	// small memory copy
	if (size < 64) {
		return memcpy_tiny(dst, src, size);
	}

	// align destination to 16 bytes boundary
	diff = (((size_t)dst + 15) & (~15)) - ((size_t)dst);
	if (diff > 0) {
		memcpy_tiny(dst, src, diff);
		dst += diff;
		src += diff;
		size -= diff;
	}

	// medium size copy
	if (size <= cachesize) {
		__m128i c1, c2, c3, c4;
		
		if ((((size_t)src) & 15) == 0) {	// source aligned
			for (; size >= 64; size -= 64) {
				c1 = _mm_load_si128(((const __m128i*)src) + 0);
				c2 = _mm_load_si128(((const __m128i*)src) + 1);
				c3 = _mm_load_si128(((const __m128i*)src) + 2);
				c4 = _mm_load_si128(((const __m128i*)src) + 3);
				src += 64;
				_mm_store_si128((((__m128i*)dst) + 0), c1);
				_mm_store_si128((((__m128i*)dst) + 1), c2);
				_mm_store_si128((((__m128i*)dst) + 2), c3);
				_mm_store_si128((((__m128i*)dst) + 3), c4);
				dst += 64;
			}
		}
		else {							// source un-aligned
			for (; size >= 64; size -= 64) {
				c1 = _mm_loadu_si128(((const __m128i*)src) + 0);
				c2 = _mm_loadu_si128(((const __m128i*)src) + 1);
				c3 = _mm_loadu_si128(((const __m128i*)src) + 2);
				c4 = _mm_loadu_si128(((const __m128i*)src) + 3);
				src += 64;
				_mm_store_si128((((__m128i*)dst) + 0), c1);
				_mm_store_si128((((__m128i*)dst) + 1), c2);
				_mm_store_si128((((__m128i*)dst) + 2), c3);
				_mm_store_si128((((__m128i*)dst) + 3), c4);
				dst += 64;
			}
		}
	}
	else {		// big memory copy
		__m128i c1, c2, c3, c4;

		_mm_prefetch((const char*)(src), _MM_HINT_NTA);

		if ((((size_t)src) & 15) == 0) {	// source aligned
			for (; size >= 64; size -= 64) {
				_mm_prefetch((const char*)(src + 128), _MM_HINT_NTA);
				c1 = _mm_load_si128(((const __m128i*)src) + 0);
				c2 = _mm_load_si128(((const __m128i*)src) + 1);
				c3 = _mm_load_si128(((const __m128i*)src) + 2);
				c4 = _mm_load_si128(((const __m128i*)src) + 3);
				src += 64;
				_mm_stream_si128((((__m128i*)dst) + 0), c1);
				_mm_stream_si128((((__m128i*)dst) + 1), c2);
				_mm_stream_si128((((__m128i*)dst) + 2), c3);
				_mm_stream_si128((((__m128i*)dst) + 3), c4);
				dst += 64;
			}
		}
		else {							// source unaligned
			for (; size >= 64; size -= 64) {
				_mm_prefetch((const char*)(src + 128), _MM_HINT_NTA);
				c1 = _mm_loadu_si128(((const __m128i*)src) + 0);
				c2 = _mm_loadu_si128(((const __m128i*)src) + 1);
				c3 = _mm_loadu_si128(((const __m128i*)src) + 2);
				c4 = _mm_loadu_si128(((const __m128i*)src) + 3);
				src += 64;
				_mm_stream_si128((((__m128i*)dst) + 0), c1);
				_mm_stream_si128((((__m128i*)dst) + 1), c2);
				_mm_stream_si128((((__m128i*)dst) + 2), c3);
				_mm_stream_si128((((__m128i*)dst) + 3), c4);
				dst += 64;
			}
		}
		_mm_sfence();
	}

	return memcpy_tiny(dst, src, size);
}

void benchmark(int dstalign, int srcalign, size_t size, int times)
{
	char *DATA1 = (char*)malloc(size + 64);
	char *DATA2 = (char*)malloc(size + 64);
	size_t LINEAR1 = ((size_t)DATA1);
	size_t LINEAR2 = ((size_t)DATA2);
	char *ALIGN1 = (char*)(((64 - (LINEAR1 & 63)) & 63) + LINEAR1);
	char *ALIGN2 = (char*)(((64 - (LINEAR2 & 63)) & 63) + LINEAR2);
	char *dst = (dstalign)? ALIGN1 : (ALIGN1 + 1);
	char *src = (srcalign)? ALIGN2 : (ALIGN2 + 3);
	DWORD t1, t2;
	int k;
	
	Sleep(100);
	t1 = timeGetTime();
	for (k = times; k > 0; k--) {
		memcpy(dst, src, size);
	}
	t1 = timeGetTime() - t1;
	Sleep(100);
	t2 = timeGetTime();
	for (k = times; k > 0; k--) {
		memcpy_fast(dst, src, size);
	}
	t2 = timeGetTime() - t2;

	free(DATA1);
	free(DATA2);

	printf("result(dst %s, src %s): memcpy_fast=%dms memcpy=%d ms\n",  
		dstalign? "aligned" : "unalign", 
		srcalign? "aligned" : "unalign", (int)t2, (int)t1);
}


void bench(int copysize, int times)
{
	printf("benchmark(size=%d bytes, times=%d):\n", copysize, times);
	benchmark(1, 1, copysize, times);
	benchmark(1, 0, copysize, times);
	benchmark(0, 1, copysize, times);
	benchmark(0, 0, copysize, times);
	printf("\n");
}


void random_bench(int maxsize, int times)
{
	static char A[11 * 1024 * 1024 + 2];
	static char B[11 * 1024 * 1024 + 2];
	static int random_offsets[0x10000];
	static int random_sizes[0x8000];
	unsigned int i, p1, p2;
	DWORD t1, t2;
	for (i = 0; i < 0x10000; i++) {	// generate random offsets
		random_offsets[i] = rand() % (10 * 1024 * 1024 + 1);
	}
	for (i = 0; i < 0x8000; i++) {	// generate random sizes
		random_sizes[i] = 1 + rand() % maxsize;
	}
	Sleep(100);
	t1 = timeGetTime();
	for (p1 = 0, p2 = 0, i = 0; i < times; i++) {
		int offset1 = random_offsets[(p1++) & 0xffff];
		int offset2 = random_offsets[(p1++) & 0xffff];
		int size = random_sizes[(p2++) & 0x7fff];
		memcpy(A + offset1, B + offset2, size);
	}
	t1 = timeGetTime() - t1;
	Sleep(100);
	t2 = timeGetTime();
	for (p1 = 0, p2 = 0, i = 0; i < times; i++) {
		int offset1 = random_offsets[(p1++) & 0xffff];
		int offset2 = random_offsets[(p1++) & 0xffff];
		int size = random_sizes[(p2++) & 0x7fff];
		memcpy_fast(A + offset1, B + offset2, size);
	}
	t2 = timeGetTime() - t2;
	printf("benchmark random access:\n");
	printf("memcpy_fast=%dms memcpy=%dms\n\n", (int)t2, (int)t1);
}


#ifdef _MSC_VER
#pragma comment(lib, "winmm.lib")
#endif

int main(void)
{
	bench(32, 0x1000000);
	bench(64, 0x1000000);
	bench(512, 0x800000);
	bench(1024, 0x400000);
	bench(4096, 0x80000);
	bench(8192, 0x40000);
	bench(1024 * 1024 * 1, 0x800);
	bench(1024 * 1024 * 4, 0x200);
	bench(1024 * 1024 * 8, 0x100);
	
	random_bench(2048, 8000000);

	return 0;
}




/*
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

benchmark random access:
memcpy_fast=594ms memcpy=1161ms


*/




