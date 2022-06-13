# Eigen arch functions

## PacketMath.h

### Types

| type eigen | type avx | form             |
|:-----------|:---------|:-----------------|
| Packet4f   | __m128   | float            |
| Packet2d   | __m128d  | double           |
| Packet4i   | __m128i  | int              |
| Packet16b  | __m128i  | bool (char)      |
| AVX        |          |                  |
| Packet8f   | __m256   | float            |
| Packet4d   | __m256d  | double           |
| Packet8i   | __m256i  | int              |
| Packet8h   | __m128i  | half (ushort)    |
| Packet8bf  | __m128i  | float16 (ushort) |
| AVX2       |          |                  |
| Packet4l   | __m256i  | long             |
| AVX512     |          |                  |
| Packet16f  | __m512   | float            |
| Packet8d   | __m512d  | double           |
| Packet16i  | __m512i  | int              |
| Packet16h  | __m256i  | half (ushort)    |
| Packet16bf | __m256i  | float16 (ushort) |

### Types unpacket for eigen

| type unpacket | type        | half      | integer_packet | mask_t   |
|:--------------|:------------|:----------|:---------------|:---------|
| Packet4f      | float       | Packet4f  | Packet4i       |          |
| Packet2d      | double      | Packet2d  |                |          |
| Packet4i      | int         | Packet4i  |                |          |
| Packet16b     | bool        | Packet16b |                |          |
| AVX           |             |           |                |          |
| Packet8f      | float       | Packet4f  | Packet8i       | uint8_t  |
| Packet4d      | double      | Packet2d  |                |          |
| Packet8i      | int         | Packet4i  |                |          |
| Packet8h      | Eigen::half | Packet8h  |                |          |
| Packet8bf     | bfloat16    | Packet8bf |                |          |
| AVX2          |             |           |                |          |
| Packet4l      | int64_t     | Packet4l  |                |          |
| AVX512        |             |           |                |          |
| Packet16f     | float       | Packet8f  | Packet16i      | uint16_t |
| Packet8d      | double      | Packet4d  |                | uint8_t  |
| Packet16i     | int         | Packet8i  |                |          |
| Packet16h     | Eigen::half | Packet8h  |                |          |
| Packet16bf    | bfloat16    | Packet8bf |                |          |

### Types unpacket for c

> if AVX512

| type unpacket | type      | half      |
|:--------------|:----------|:----------|
| float         | Packet16f | Packet8f  |
| double        | Packet8d  | Packet4d  |
| int           | Packet16i | Packet8i  |
| half          | Packet16h | Packet16h |

> else if AVX

| type unpacket | type      | half      |
|:--------------|:----------|:----------|
| float         | Packet8f  | Packet4f  |
| double        | Packet4d  | Packet2d  |
| int           | Packet8i  | Packet4i  |
| Eigen::half   | Packet8h  | Packet8h  |
| bfloat16      | Packet8bf | Packet8bf |
| AVX2          |           |           |
| int64_t       | Packet4l  | Packet4l  |

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

> SSE

| function \ type                    |        Packet4f         |        Packet2d         |        Packet4i         |        Packet16b        |
|:-----------------------------------|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| pset1                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| pset1frombits                      |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pzero                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |           :x:           |
| peven_mask                         |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |
| pload1                             |        :repeat:         |           :x:           |           :x:           |           :x:           |
| padd                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| padd + umask                       |           :x:           |           :x:           |           :x:           |           :x:           |
| plset                              |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |
| psub                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| paddsub                            |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pnegate                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: |
| pconj                              | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| pmul                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pdiv                               |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pmadd                              |        :repeat:         |        :repeat:         | :ballot_box_with_check: |           :x:           |
| pmsub                              |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pnmadd                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pnmsub                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pselect                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ptrue                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pand                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| por                                |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pxor                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pandnot                            |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |
| pcmp_le                            |        :repeat:         |        :repeat:         | :ballot_box_with_check: |           :x:           |
| pcmp_lt                            |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |
| pcmp_lt_or_nan                     |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pcmp_eq                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pmin                               |        :repeat:         |        :repeat:         |           :x:           |        :repeat:         |
| pmax                               |        :repeat:         |        :repeat:         |           :x:           |        :repeat:         |
| parithmetic_shift_right            |           :x:           |           :x:           |        :repeat:         |           :x:           |
| plogical_shift_right               |           :x:           |           :x:           |        :repeat:         |           :x:           |
| plogical_shift_left                |           :x:           |           :x:           |        :repeat:         |           :x:           |
| pabs                               |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |
| pround                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| print                              |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pceil                              |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pfloor                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pload                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadu                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadu + umask                     |           :x:           |           :x:           |           :x:           |           :x:           |
| ploaddup                           |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |
| ploadquad                          |           :x:           |           :x:           |           :x:           |        :repeat:         |
| pstore                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu + umask                    |           :x:           |           :x:           |           :x:           |           :x:           |
| pgather                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pscatter                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstore1                            |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pfirst                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| preverse                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| predux                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pfrexp_generic_get_biased_exponent |           :x:           |        :repeat:         |           :x:           |           :x:           |
| pfrexp                             | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |           :x:           |
| pldexp                             | :ballot_box_with_check: |        :repeat:         |           :x:           |           :x:           |
| pbroadcast4                        |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| punpackp                           |        :repeat:         |           :x:           |           :x:           |           :x:           |
| predux_half_dowto4                 |           :x:           |           :x:           |           :x:           |           :x:           |
| predux_mul                         |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |
| predux_min                         |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |
| predux_max                         |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |
| predux_any                         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| ptranspose                         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:*        |
| pblend                             |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |
| extract256                         |           :x:           |           :x:           |           :x:           |           :x:           |
| extract128                         |           :x:           |        :repeat:         |           :x:           |           :x:           |
| cat256                             |           :x:           |           :x:           |           :x:           |           :x:           |

> AVX / AVX2

| function \ type                    |        Packet8f         |        Packet4d         |        Packet8i         |        Packet8h         |        Packet8bf        |        Packet4l         |
|:-----------------------------------|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| pset1                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| pset1frombits                      |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |
| pzero                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |           :x:           |           :x:           |   :white_check_mark:    |
| peven_mask                         |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |           :x:           |        :repeat:         |
| pload1                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |        :repeat:         |
| padd                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| padd + umask                       |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| plset                              |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| psub                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| paddsub                            |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| pnegate                            |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| pconj                              | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pmul                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pdiv                               |        :repeat:         |        :repeat:         |       :question:        | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| pmadd                              |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |
| pmsub                              |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |
| pnmadd                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |
| pnmsub                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |
| pselect                            |        :repeat:         |        :repeat:         |           :x:           |        :repeat:         |        :repeat:         |           :x:           |
| ptrue                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pand                               |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |        :repeat:         |        :repeat:         |
| por                                |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pxor                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pandnot                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pcmp_le                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pcmp_lt                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pcmp_lt_or_nan                     |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| pcmp_eq                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pmin                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pmax                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| parithmetic_shift_right            |           :x:           |           :x:           |        :repeat:         |           :x:           |           :x:           |        :repeat:         |
| plogical_shift_right               |           :x:           |           :x:           |        :repeat:         |           :x:           |           :x:           |        :repeat:         |
| plogical_shift_left                |           :x:           |           :x:           |        :repeat:         |           :x:           |           :x:           |        :repeat:         |
| pabs                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pround                             |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| print                              |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| pceil                              |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| pfloor                             |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| pload                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadu                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadu + umask                     |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| ploaddup                           |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |           :x:           |        :repeat:         |
| ploadquad                          |        :repeat:         |           :x:           |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pstore                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu + umask                    |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| pgather                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pscatter                           |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pstore1                            | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |           :x:           | :ballot_box_with_check: |
| pfirst                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| preverse                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| predux                             |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |           :x:           |        :repeat:         |
| pfrexp_generic_get_biased_exponent |           :x:           |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |
| pfrexp                             |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |           :x:           |           :x:           |
| pldexp                             | :ballot_box_with_check: |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |
| pbroadcast4                        |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| punpackp                           |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| predux_half_dowto4                 |        :repeat:         |           :x:           |        :repeat:         |           :x:           |           :x:           |           :x:           |
| predux_mul                         |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| predux_min                         |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| predux_max                         |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| predux_any                         |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| ptranspose                         |        :repeat:*        |        :repeat:         |        :repeat:*        |        :repeat:         |        :repeat:*        |        :repeat:         |
| pblend                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |
| extract256                         |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| extract128                         |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| cat256                             |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |

> AVX512

| function \ type                    |        Packet16f        |        Packet8d         |        Packet16i        |        Packet16h        |       Packet16bf        |
|:-----------------------------------|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| pset1                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pset1frombits                      |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pzero                              |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| peven_mask                         |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           |           :x:           |
| pload1                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| padd                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| padd + umask                       |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| plset                              |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| psub                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| paddsub                            |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| pnegate                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pconj                              | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pmul                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pdiv                               |        :repeat:         |        :repeat:         |                         | :ballot_box_with_check: | :ballot_box_with_check: |
| pmadd                              |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pmsub                              |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pnmadd                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pnmsub                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pselect                            |        :repeat:         |        :repeat:         |           :x:           |        :repeat:         |        :repeat:         |
| ptrue                              |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pand                               |        :repeat:         |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: |
| por                                |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pxor                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pandnot                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pcmp_le                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pcmp_lt                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pcmp_lt_or_nan                     |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pcmp_eq                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pmin                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pmax                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| parithmetic_shift_right            |           :x:           |           :x:           |        :repeat:         |           :x:           |           :x:           |
| plogical_shift_right               |           :x:           |           :x:           |        :repeat:         |           :x:           |           :x:           |
| plogical_shift_left                |           :x:           |           :x:           |        :repeat:         |           :x:           |           :x:           |
| pabs                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pround                             |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| print                              |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pceil                              |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pfloor                             |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pload                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadu                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadu + umask                     |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| ploaddup                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadquad                          |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstore                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu + umask                    |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pgather                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pscatter                           |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pstore1                            | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |           :x:           |
| pfirst                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| preverse                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| predux                             |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pfrexp_generic_get_biased_exponent |           :x:           |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pfrexp                             | :ballot_box_with_check: |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pldexp                             |        :repeat:         |        :repeat:         |           :x:           |           :x:           |           :x:           |
| pbroadcast4                        |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| punpackp                           |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| predux_half_dowto4                 |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| predux_mul                         |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| predux_min                         |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| predux_max                         |        :repeat:         |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| predux_any                         |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |
| ptranspose                         |        :repeat:*        |        :repeat:*        |        :repeat:*        |        :repeat:*        |        :repeat:*        |
| pblend                             |       :question:        |        :repeat:         |           :x:           |           :x:           |           :x:           |
| extract256                         |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| extract128                         |           :x:           |           :x:           |           :x:           |           :x:           |           :x:           |
| cat256                             |        :repeat:         |           :x:           |           :x:           |           :x:           |           :x:           |

| function \ type |  float   |  double  |   int    |
|:----------------|:--------:|:--------:|:--------:|
| prefetch        | :repeat: | :repeat: | :repeat: |

| to \ from |  Packet8h  |  Packet8f  | Packet8bf |
|:---------:|:----------:|:----------:|:---------:|
| Packet8h  |     --     | float2half |    :x:    |
| Packet8f  | half2float |     --     | Bf16ToF32 |
| Packet8bf |    :x:     | F32ToBf16  |    --     |

| to \ from  | Packet16h  | Packet16f  | Packet16bf |
|:----------:|:----------:|:----------:|:----------:|
| Packet16h  |     --     | float2half |    :x:     |
| Packet16f  | half2float |     --     | Bf16ToF32  |
| Packet16bf |    :x:     | F32ToBf16  |     --     |

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

* EIGEN_EXTRACT_8f_FROM_16f(INPUT, OUTPUT)
* EIGEN_EXTRACT_8i_FROM_16i(INPUT, OUTPUT)

* EIGEN_INSERT_8f_INTO_16f(OUTPUT, INPUTA, INPUTB)
* EIGEN_INSERT_8i_INTO_16i(OUTPUT, INPUTA, INPUTB)

* PACK_OUTPUT_SQ_D(OUTPUT, INPUT, INDEX, STRIDE)
* PACK_OUTPUT_D(OUTPUT, INPUT, INDEX, STRIDE)

* SHUFFLE_EPI32(A, B, M)

> unpack

* Packet4f vec4f_movelh(Packet4f a, Packet4f b)
* Packet4f vec4f_movehl(Packet4f a, Packet4f b)
* Packet4f vec4f_unpacklo(Packet4f a, Packet4f b)
* Packet4f vec4f_unpackhi(Packet4f a, Packet4f b)
* Packet2d vec2d_unpacklo(Packet2d a, Packet2d b)
* Packet2d vec2d_unpackhi(Packet2d a, Packet2d b)

> conversion

* __m128i Pack16To8(Packet8f rf)
* __m256i Pack32To16(Packet16f rf)
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

| to \ from | Packet16i |     Packet16f      |      Packet8d      | Packet8f |
|:---------:|:---------:|:------------------:|:------------------:|:--------:|
| Packet16i |    --     |      :repeat:      |        :x:         |   :x:    |
| Packet16f | :repeat:  | :white_check_mark: |      :repeat:      |   :x:    |
| Packet8d  |    :x:    |      :repeat:      | :white_check_mark: |   :x:    |
| Packet8f  |    :x:    |      :repeat:      |        :x:         |    --    |

## MathFunctions.h

| function \ type |        Packet4f         |        Packet2d         | Packet16b |        Packet8f         |        Packet4d         | Packet8h | Packet8bf |        Packet16f        |        Packet8d         |        Packet16h        |       Packet16bf        |
|:----------------|:-----------------------:|:-----------------------:|:---------:|:-----------------------:|:-----------------------:|:--------:|:---------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| plog            | :ballot_box_with_check: | :ballot_box_with_check: |    :x:    | :ballot_box_with_check: | :ballot_box_with_check: |   :x:    |    :x:    | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| plog2           | :ballot_box_with_check: | :ballot_box_with_check: |    :x:    | :ballot_box_with_check: | :ballot_box_with_check: |   :x:    |    :x:    | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| plog1p          | :ballot_box_with_check: |           :x:           |    :x:    | :ballot_box_with_check: |           :x:           |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pexpm1          | :ballot_box_with_check: |           :x:           |    :x:    | :ballot_box_with_check: |           :x:           |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pexp            | :ballot_box_with_check: | :ballot_box_with_check: |    :x:    | :ballot_box_with_check: | :ballot_box_with_check: |   :x:    |    :x:    |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| psin            | :ballot_box_with_check: |           :x:           |    :x:    | :ballot_box_with_check: |           :x:           |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pcos            | :ballot_box_with_check: |           :x:           |    :x:    | :ballot_box_with_check: |           :x:           |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| psqrt           |        :repeat:         |        :repeat:         | :repeat:  |        :repeat:         |        :repeat:         |   :x:    |    :x:    |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| prsqrt          |        :repeat:         |           :x:           |    :x:    |        :repeat:         |           :x:           |   :x:    |    :x:    |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| preciprocal     |        :repeat:         |           :x:           |    :x:    |        :repeat:         |           :x:           |   :x:    |    :x:    |        :repeat:         |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| ptanh           | :ballot_box_with_check: |           :x:           |    :x:    | :ballot_box_with_check: |           :x:           |   :x:    |    :x:    | :ballot_box_with_check: |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pfrexp          |           :x:           |           :x:           |    :x:    |           :x:           |           :x:           | :repeat: | :repeat:  |           :x:           |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |
| pldexp          |           :x:           |           :x:           |    :x:    |           :x:           |           :x:           | :repeat: | :repeat:  |           :x:           |           :x:           | :ballot_box_with_check: | :ballot_box_with_check: |

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
