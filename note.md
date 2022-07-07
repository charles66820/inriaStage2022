# Note

## Workflow

* start to see mipp integration (fma)

## Notes

### To add the new MIPP arch

* arch folder in `Eigen/src/Core/arch/<arch>/`
* arch load in `Eigen/Core`
* vecto config in `Eigen/src/Core/util/ConfigureVectorization.h`

### To benchmark

* run `./bench_multi_compilers.sh compilerlist.txt bench_norm.cpp`
* see BenchTimer

### Build and run Eigen test with MIPP

* `cmake .. -DEIGEN_TEST_MIPP=ON`
* `make check -j -k; while [ $? -ne 0 ]; do make check -j -k; done`

### Other

* disable the turbo boost `echo "1" | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo`
* to get all eigen types `cat */* | egrep -o 'Packet[0-9]+[a-z]+? ' | sort | uniq`
* to test if is align `float* test = ...; ((intptr_t)test % 32);`
* Search SSE, AVX, AVX2 `<Packet(2d|4(f|d|i|l)|8(f|i|h|bf)|16b)`
* Search pset1 function definition `Packet[1-9]+[a-x]+ pset1<`

```c++
EIGEN_STRONG_INLINE Packet8f Bf16ToF32(const Packet8bf& a) {
  // auto s = mipp::cvt<short,float>(a);
  // auto s = mipp::cvt<int16_t,int32_t>((__m128)a.m_val);
  // return (__m256) mipp::lshift<float>(s, 16);
```

### Plafrim eigen tests

* `srun -C haswell --time=03:00:00 --pty bash -i`
* `module load build/cmake/3.21.3 compiler/gcc/11.2.0`
* `cd eigen-fork && mkdir build ; cd build`
* `cmake .. -DEIGEN_TEST_MIPP=ON`
* `make buildtests -j12 -k; while [ $? -ne 0 ]; do make buildtests -j12 -k; done`

### types size

> Integer

| type        | type std | Byte | bits |
|:------------|:---------|:-----|:-----|
| char / bool | int8_t   | 1    | 8    |
| short       | int16_t  | 2    | 16   |
| int         | int32_t  | 4    | 32   |
| long        | int64_t  | 8    | 64   |

> float

| type   | type std | Byte | bits |
|:-------|:---------|:-----|:-----|
| float  | uint32_t | 4    | 32   |
| double | uint64_t | 8    | 64   |

### types size (Eigen / MIPP)

> from Packet to MIPP

| type eigen | type MIPP | to MIPP SSE        | to MIPP AVX                                | to MIPP AVX512                             |
|:-----------|:----------|:-------------------|:-------------------------------------------|:-------------------------------------------|
| Packet16b  | int8_t    | (reg)(__m128i) vec | (reg)(__m256i) _mm256_castsi128_si256(vec) | (reg)(__m512i) _mm512_castsi128_si512(vec) |
| Packet4i   | int32_t   | (reg)(__m128i) vec | (reg)(__m256i) _mm256_castsi128_si256(vec) | (reg)(__m512i) _mm512_castsi128_si512(vec) |
| Packet8i   | int32_t   | /                  | (reg)(__m256i) vec                         | (reg)(__m512i) _mm512_castsi256_si512(vec) |
| Packet16i  | int32_t   | /                  | /                                          | (reg)(__m512i) vec                         |
| Packet4l   | int64_t   | /                  | (reg)(__m256i) vec                         | (reg)(__m512i) _mm512_castsi256_si512(vec) |
| Packet8h   | int16_t   | (reg)(__m128i) vec | (reg)(__m256i) _mm256_castsi128_si256(vec) | (reg)(__m512i) _mm512_castsi128_si512(vec) |
| Packet16h  | int16_t   | /                  | /                                          | (reg)(__m512i) vec                         |
| Packet4f   | float     | (reg) vec          | (reg) _mm256_castps128_ps256(vec)          | (reg) _mm512_castps128_ps512(vec)          |
| Packet8f   | float     | /                  | (reg) vec                                  | (reg) _mm512_castps256_ps512(vec)          |
| Packet16f  | float     | /                  | /                                          | (reg) vec                                  |
| Packet2d   | double    | (reg)(__m128d) vec | (reg)(__m128d) _mm256_castpd128_pd256(vec) | (reg)(__m512d) _mm512_castpd128_pd512(vec) |
| Packet4d   | double    | /                  | (reg)(__m256d) vec                         | (reg)(__m512d) _mm512_castpd256_pd512(vec) |
| Packet8d   | double    | /                  | /                                          | (reg)(__m512d) vec                         |
| Packet8bf  | int16_t   | (reg)(__m256i) vec | (reg)(__m256i) _mm256_castsi128_si256(vec) | (reg)(__m512i) _mm512_castsi128_si512(vec) |
| Packet16bf | int16_t   | /                  | /                                          |                                            |

> from MIPP to Packet

| type eigen | type MIPP | form MIPP SSE | form MIPP AVX                                  | form MIPP AVX512                               |
|:-----------|:----------|:--------------|:-----------------------------------------------|:-----------------------------------------------|
| Packet16b  | int8_t    | (__m128i) vec | (__m128i) _mm256_castsi256_si128((__m256i)vec) | (__m128i) _mm512_castsi512_si128((__m512i)vec) |
| Packet4i   | int32_t   | (__m128i) vec | (__m128i) _mm256_castsi256_si128((__m256i)vec) | (__m128i) _mm512_castsi512_si128((__m512i)vec) |
| Packet8i   | int32_t   | /             | (reg)(__m256i) vec                             | (__m256i) _mm512_castsi512_si256((__m512i)vec) |
| Packet16i  | int32_t   | /             | /                                              | (__m512i) vec                                  |
| Packet4l   | int64_t   | /             | (reg)(__m256i) vec                             | (__m256i) _mm512_castsi512_si256((__m512i)vec) |
| Packet8h   | int16_t   | (__m128i) vec | (__m128i) _mm256_castsi256_si128((__m256i)vec) | (__m128i) _mm512_castsi512_si128((__m512i)vec) |
| Packet16h  | int16_t   | /             | /                                              | (__m512i) vec                                  |
| Packet4f   | float     | (reg) vec     | (__m128) _mm256_castps256_ps128((__m256)vec)   | (__m128) _mm512_castps512_ps128((__m512)vec)   |
| Packet8f   | float     | /             | (__m256) vec                                   | (__m256) _mm512_castps512_ps256((__m512)vec)   |
| Packet16f  | float     | /             | /                                              | (__m512) vec                                   |
| Packet2d   | double    | (__m128d) vec | (__m128d) _mm256_castpd256_pd128((__m256d)vec) | (__m128d) _mm512_castpd512_pd128((__m512d)vec) |
| Packet4d   | double    | /             | (__m256d) vec                                  | (__m256d) _mm512_castpd512_pd256((__m512d)vec) |
| Packet8d   | double    | /             | /                                              | (__m512d) vec                                  |
| Packet8bf  | int16_t   | (__m128i) vec | (__m128i) _mm256_castsi256_si128((__m256i)vec) | (__m128i) _mm512_castsi512_si128((__m512i)vec) |
| Packet16bf | int16_t   | /             | /                                              | (__m512i) vec                                  |

<!-- Complex -->
Packet1cd
Packet2cd
Packet2cf
Packet4cf

<!-- other -->

<!-- float, double -->
Packet2f

<!-- short?, int, long -->
Packet8s
Packet4s
Packet2i
Packet2l

<!-- half -->
Packet4h
Packet16h

Packet4hf
Packet8hf

<!-- BFloat https://en.wikipedia.org/wiki/Bfloat16_floating-point_format -->
Packet4bf

<!-- ? -->
Packet2bl
Packet4bi

<!-- Complex -->
Packet4c
Packet8c
Packet16c
Packet1cd
Packet2cd
Packet4cd
Packet1cf
Packet2cf
Packet4cf
Packet8cf

<!-- unsigned -->
Packet2ui
Packet2ul
Packet4uc
Packet4ui
Packet4us
Packet8uc
Packet8us
Packet16uc

## Links

* <https://github.com/aff3ct/MIPP>
* <https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html>
