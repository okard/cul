//-----------------------------------------------------------------------------
// MurmurHash3 was written by Austin Appleby, and is placed in the public
// domain. The author hereby disclaims copyright to this source code.
#pragma once
#ifndef _MURMURHASH3_H_
#define _MURMURHASH3_H_

//-----------------------------------------------------------------------------
// Platform-specific functions and macros
#if defined(_MSC_VER)
	typedef unsigned char uint8_t;
	typedef unsigned long uint32_t;
	typedef unsigned __int64 uint64_t;
#else
	#include <stdint.h>
#endif

/**
* Hashs a key with len and a 32 bit seed to a 32 bit output value
*/
void MurmurHash3_x86_32  ( const void * key, int len, uint32_t seed, void * out );

/**
* Hashs a key with len and a 32 bit seed to a 128 bit value
* Optimized for x86-32
*/
void MurmurHash3_x86_128 ( const void * key, int len, uint32_t seed, void * out );

/**
* Hashs a key with len and a 32 bit seed to a 128 bit value
* Optimized for x86-64
*/
void MurmurHash3_x64_128 ( const void * key, int len, uint32_t seed, void * out );



#endif // _MURMURHASH3_H_
