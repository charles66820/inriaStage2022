# Eigen arch functions

## PacketMath.h

### Types

| type eigen | type avx | form             |                 |
|:-----------|:---------|:-----------------|-----------------|
| Packet4f   | __m128   | float            |                 |
| Packet2d   | __m128d  | double           |                 |
| Packet4i   | __m128i  | int              |                 |
| Packet16b  | __m128i  | bool (char)      |                 |
| Packet8f   | __m256   | float            |                 |
| Packet4d   | __m256d  | double           |                 |
| Packet8i   | __m256i  | int              |                 |
| Packet8h   | __m128i  | half (ushort)    |                 |
| Packet8bf  | __m128i  | float16 (ushort) |                 |
| Packet4l   | __m256i  | long             | <!-- AVX512 --> |

### Types unpacket for eigen

| type unpacket | type        | half      | integer_packet | mask_t  |                  |
|:--------------|:------------|:----------|:---------------|:--------|------------------|
| Packet4f      | float       | Packet4f  | Packet4i       |         |                  |
| Packet2d      | double      | Packet2d  |                |         |                  |
| Packet4i      | int         | Packet4i  |                |         |                  |
| Packet16b     | bool        | Packet16b |                |         |                  |
| Packet8f      | float       | Packet4f  | Packet8i       | uint8_t |                  |
| Packet4d      | double      | Packet2d  |                |         |                  |
| Packet8i      | int         | Packet4i  |                |         |                  |
| Packet8h      | Eigen::half | Packet8h  |                |         |                  |
| Packet8bf     | bfloat16    | Packet8bf |                |         |                  |
| Packet4l      | int64_t     | Packet4l  |                |         | <!-- if AVX2 --> |

### Types unpacket for c

> if AVX512

| type unpacket | type      | half      |
|:--------------|:----------|:----------|
| float         | Packet16f | Packet8f  |
| double        | Packet8d  | Packet4d  |
| int           | Packet16i | Packet8i  |
| half          | Packet16h | Packet16h |

> else if AVX

| type unpacket | type      | half      |                  |
|:--------------|:----------|:----------|------------------|
| float         | Packet8f  | Packet4f  |                  |
| double        | Packet4d  | Packet2d  |                  |
| int           | Packet8i  | Packet4i  |                  |
| Eigen::half   | Packet8h  | Packet8h  |                  |
| bfloat16      | Packet8bf | Packet8bf |                  |
| int64_t       | Packet4l  | Packet4l  | <!-- if AVX2 --> |

> else // SSE

| type unpacket | type     | half     |
|:--------------|:---------|:---------|
| float         | Packet4f | Packet4f |
| double        | Packet2d | Packet2d |
| int           | Packet4i | Packet4i |

> all
| type unpacket | type      | half      |
|:--------------|:----------|:----------|
| bool          | Packet16b | Packet16b |

### Functions

* :white_check_mark: in MIPP
* :ballot_box_with_check: nothing to do
* :repeat: todo
* :x: not implemented
* \* multiple kernel

| function \ type                    |      Packet4l      |      Packet4f      |      Packet2d      |      Packet4i      |     Packet16b      |      Packet8f      |      Packet4d      |      Packet8i      |      Packet8h      |     Packet8bf      |
|:-----------------------------------|:------------------:|:------------------:|:------------------:|:------------------:|:------------------:|:------------------:|:------------------:|:------------------:|:------------------:|:------------------:|
| pset1                              | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| pset1frombits                      |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pzero                              | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |        :x:         | :white_check_mark: | :white_check_mark: | :white_check_mark: |        :x:         |        :x:         |
| peven_mask                         |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pload1                             |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| padd                               |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| padd + umask                       |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |        :x:         |
| plset                              |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| psub                               |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| paddsub                            |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |
| pnegate                            |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| pconj                              |      :repeat:      |        :x:         |        :x:         |        :x:         |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pmul                               |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pdiv                               |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pmadd                              |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pmsub                              |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pnmadd                             |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pnmsub                             |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pselect                            |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |
| ptrue                              |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| pand                               |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |
| por                                |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| pxor                               |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| pandnot                            |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| pcmp_le                            |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pcmp_lt                            |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pcmp_lt_or_nan                     |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pcmp_eq                            |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pmin                               |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pmax                               |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| parithmetic_shift_right            |      :repeat:      |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |
| plogical_shift_right               |      :repeat:      |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |
| plogical_shift_left                |      :repeat:      |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |
| pabs                               |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| pround                             |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| print                              |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pceil                              |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pfloor                             |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pload                              |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| ploadu                             |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| ploadu + umask                     |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |        :x:         |
| ploaddup                           |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| ploadquad                          |        :x:         |        :x:         |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |
| pstore                             |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| pstoreu                            |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| pstoreu + umask                    |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |        :x:         |
| pgather                            |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |
| pscatter                           |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pstore1                            |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pfirst                             |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| preverse                           |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |
| predux                             |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |        :x:         |
| pfrexp_generic_get_biased_exponent |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pldexp                             |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| pbroadcast4                        |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |
| punpackp                           |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |
| predux_half_dowto4                 |        :x:         |        :x:         |        :x:         |        :x:         |        :x:         |      :repeat:      |        :x:         |      :repeat:      |        :x:         |        :x:         |
| predux_mul                         |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |        :x:         |
| predux_min                         |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| predux_max                         |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |
| predux_any                         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |      :repeat:      |        :x:         |        :x:         |        :x:         |        :x:         |
| ptranspose                         |      :repeat:      |      :repeat:      |      :repeat:      |      :repeat:      |     :repeat:*      |     :repeat:*      |      :repeat:      |     :repeat:*      |      :repeat:      |     :repeat:*      |
| pblend                             |        :x:         |      :repeat:      |      :repeat:      |      :repeat:      |        :x:         |      :repeat:      |      :repeat:      |        :x:         |        :x:         |        :x:         |

| function \ type |  float   |  double  |   int    |
|:----------------|:--------:|:--------:|:--------:|
| prefetch        | :repeat: | :repeat: | :repeat: |

| to \ from |  Packet8h  |  Packet8f  | Packet8bf |
|:---------:|:----------:|:----------:|:---------:|
| Packet8h  |     --     | float2half |    :x:    |
| Packet8f  | half2float |     --     | Bf16ToF32 |
| Packet8bf |    :x:     | F32ToBf16  |    --     |

> macros

* vec4f_swizzle1(v,p,q,r,s)
* vec4i_swizzle1(v,p,q,r,s)
* vec2d_swizzle1(v,p,q)
* vec4f_swizzle2(a,b,p,q,r,s)
* vec4i_swizzle2(a,b,p,q,r,s)
* vec2d_swizzle2(a,b,mask)

* MM256_SHUFFLE_EPI64(A, B, M)
* MM256_SHUFFLE_EPI32(A, B, M)
* MM256_UNPACKLO_EPI32(A, B)
* MM256_UNPACKHI_EPI32(A, B)

> unpack

* Packet4f vec4f_movelh(Packet4f a, Packet4f b)
* Packet4f vec4f_movehl(Packet4f a, Packet4f b)
* Packet4f vec4f_unpacklo(Packet4f a, Packet4f b)
* Packet4f vec4f_unpackhi(Packet4f a, Packet4f b)
* Packet2d vec2d_unpacklo(Packet2d a, Packet2d b)
* Packet2d vec2d_unpackhi(Packet2d a, Packet2d b)

> conversion

* __m128i Pack16To8(Packet8f rf)
* __m128i half2floatsse(__m128i h)
* __m128i float2half(__m128 f)

## TypeCasting.h

### Types casting

> if AVX512 || AVX

* `type_casting_traits<Eigen::half, float>`
* `type_casting_traits<float, Eigen::half>`
* `type_casting_traits<bfloat16, float>`
* `type_casting_traits<float, bfloat16>`

> else // SSE

* `type_casting_traits<float, int>`
* `type_casting_traits<int, float>`
* `type_casting_traits<double, float>`
* `type_casting_traits<float, double>`

> AVX, AVX2, AVX512, !SSE

* `type_casting_traits<float, int>`
* `type_casting_traits<int, float>`

### `pcast` functions

| to \ from | Packet4i | Packet4f | Packet2d  |
|:---------:|:--------:|:--------:|:---------:|
| Packet4i  |    --    | :repeat: |    :x:    |
| Packet4f  | :repeat: |    --    | :repeat:* |
| Packet2d  |   :x:    | :repeat: |    --     |

| to \ from | Packet8i | Packet8f | Packet8h | Packet8bf |
|:---------:|:--------:|:--------:|:--------:|:---------:|
| Packet8i  |    --    | :repeat: |   :x:    |    :x:    |
| Packet8f  | :repeat: |    --    | :repeat: | :repeat:  |
| Packet8h  |   :x:    | :repeat: |    --    |    :x:    |
| Packet8bf |   :x:    | :repeat: |   :x:    |    --     |

| to \ from  | Packet16i | Packet16f | Packet16h | Packet16bf |
|:----------:|:---------:|:---------:|:---------:|:----------:|
| Packet16i  |    --     | :repeat:  |    :x:    |    :x:     |
| Packet16f  | :repeat:  |    --     | :repeat:  |  :repeat:  |
| Packet16h  |    :x:    | :repeat:  |    --     |    :x:     |
| Packet16bf |    :x:    | :repeat:  |    :x:    |     --     |

### `preinterpret` functions

| to \ from | Packet4i | Packet4f | Packet2d |
|:---------:|:--------:|:--------:|:--------:|
| Packet4i  |    --    | :repeat: | :repeat: |
| Packet4f  | :repeat: |    --    |   :x:    |
| Packet2d  | :repeat: |   :x:    |    --    |

| to \ from | Packet8i | Packet8f |
|:----------|:--------:|:--------:|
| Packet8i  |    --    | :repeat: |
| Packet8f  | :repeat: |    --    |

| to \ from | Packet16i | Packet16f | Packet8d | Packet8f |
|:---------:|:---------:|:---------:|:--------:|:--------:|
| Packet16i |    --     | :repeat:  |   :x:    |   :x:    |
| Packet16f | :repeat:  | :repeat:  | :repeat: |   :x:    |
| Packet8d  |    :x:    | :repeat:  | :repeat: |   :x:    |
| Packet8f  |    :x:    | :repeat:  |   :x:    |    --    |

## MathFunctions.h

| function \ type | Packet4f | Packet2d | Packet16b | Packet8f | Packet4d | Packet8h | Packet8bf |        Packet16f        |        Packet8d         |        Packet16h        |       Packet16bf        |
|:----------------|:--------:|:--------:|:---------:|:--------:|:--------:|:--------:|:---------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| plog            | :repeat: | :repeat: |    :x:    | :repeat: | :repeat: |   :x:    |    :x:    | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| plog2           | :repeat: | :repeat: |    :x:    | :repeat: | :repeat: |   :x:    |    :x:    | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| plog1p          | :repeat: |   :x:    |    :x:    | :repeat: |   :x:    |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pexpm1          | :repeat: |   :x:    |    :x:    | :repeat: |   :x:    |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pexp            | :repeat: | :repeat: |    :x:    | :repeat: | :repeat: |   :x:    |    :x:    |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| psin            | :repeat: |   :x:    |    :x:    | :repeat: |   :x:    |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pcos            | :repeat: |   :x:    |    :x:    | :repeat: |   :x:    |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| psqrt           | :repeat: | :repeat: | :repeat:  | :repeat: | :repeat: |   :x:    |    :x:    |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| prsqrt          | :repeat: |   :x:    |    :x:    | :repeat: |   :x:    |   :x:    |    :x:    |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| preciprocal     | :repeat: |   :x:    |    :x:    | :repeat: |   :x:    |   :x:    |    :x:    |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| ptanh           | :repeat: |   :x:    |    :x:    | :repeat: |   :x:    |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pfrexp          |   :x:    |   :x:    |    :x:    |   :x:    |   :x:    | :repeat: | :repeat:  |           :x:           |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pldexp          |   :x:    |   :x:    |    :x:    |   :x:    |   :x:    | :repeat: | :repeat:  |           :x:           |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |

> numext

* float sqrt(float x)
* double sqrt(double x)

## Complex.h

### Types float

| type eigen | type avx          |
|:-----------|:------------------|
| Packet2cf  | __m128 (Packet4f) |
| Packet4cf  | __m256            |
| Packet8cf  | __m512            |

### Types double

| type eigen | type avx           |
|:-----------|:-------------------|
| Packet1cd  | __m128d (Packet2d) |
| Packet2cd  | __m256d            |
| Packet4cd  | __m512d            |

### Types unpacket for eigen (float / double)

| type unpacket | type              | half      | as_real   |
|:--------------|:------------------|:----------|:----------|
| Packet2cf     | `complex<float>`  | Packet2cf | Packet4f  |
| Packet4cf     | `complex<float>`  | Packet2cf | Packet8f  |
| Packet8cf     | `complex<float>`  | Packet4cf | Packet16f |
| Packet1cd     | `complex<double>` | Packet1cd | Packet2d  |
| Packet2cd     | `complex<double>` | Packet1cd | Packet4d  |
| Packet4cd     | `complex<double>` | Packet2cd | Packet8d  |

### Types unpacket for c (float / double)

> if AVX512

| type unpacket     | type      | half      |
|:------------------|:----------|:----------|
| `complex<float>`  | Packet8cf | Packet4cf |
| `complex<double>` | Packet4cd | Packet2cd |

> else if AVX

| type unpacket     | type      | half      |
|:------------------|:----------|:----------|
| `complex<float>`  | Packet4cf | Packet2cf |
| `complex<double>` | Packet2cd | Packet1cd |

> else // SSE

| type unpacket     | type      | half      |
|:------------------|:----------|:----------|
| `complex<float>`  | Packet2cf | Packet2cf |
| `complex<double>` | Packet1cd | Packet1cd |

### Functions complex

| function \ type |        Packet2cf        |        Packet4cf        |        Packet1cd        |        Packet2cd        |        Packet8cf        |        Packet4cd        |
|:----------------|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| padd            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| psub            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pnegate         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pconj           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pmul            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pcmp_eq         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ptrue           | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pand            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| por             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pxor            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pandnot         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pload           | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| ploadu          | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pset1           |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| ploaddup        | :ballot_box_with_check: |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |        :repeat:         |
| ploadquad       |           :x:           |           :x:           |           :x:           |           :x:           |        :repeat:         |           :x:           |
| pstore          | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pstoreu         | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pgather         |        :repeat:         |        :repeat:         |           :x:           |        :repeat:         |        :repeat:         |        :repeat:         |
| pscatter        |        :repeat:         |        :repeat:         |           :x:           |        :repeat:         |        :repeat:         |        :repeat:         |
| prefetch        |        :repeat:         |           :x:           |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pfirst          |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| preverse        |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| predux          |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| predux_mul      |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| pcplxflip       |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| pdiv            | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| ptranspose      |        :repeat:         |        :repeat:         |           :x:           |        :repeat:         |        :repeat:*        |        :repeat:         |
| pblend          |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| psqrt           | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |

* `Packet4cf predux_half_dowto4<Packet8cf>(const Packet8cf& a)`
