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

* :white_check_mark: implement with MIPP
* :ballot_box_with_check: nothing to do
* :repeat: todo
* :no_entry_sign: not implemented
* :x: not implementable in MIPP
* \* multiple kernel

> SSE

| function \ type                    |        Packet4f         |        Packet2d         |        Packet4i         |        Packet16b        |
|:-----------------------------------|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| pset1                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| pset1frombits                      |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pzero                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |     :no_entry_sign:     |
| peven_mask                         |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |
| pload1                             |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| padd                               |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| padd + umask                       |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| plset                              |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |
| psub                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| paddsub                            |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pnegate                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: |
| pconj                              | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| pmul                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pdiv                               |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pmadd                              |        :repeat:         |        :repeat:         | :ballot_box_with_check: |     :no_entry_sign:     |
| pmsub                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pnmadd                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pnmsub                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pselect                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ptrue                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pand                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| por                                |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pxor                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pandnot                            |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |
| pcmp_le                            |        :repeat:         |        :repeat:         | :ballot_box_with_check: |     :no_entry_sign:     |
| pcmp_lt                            |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |
| pcmp_lt_or_nan                     |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pcmp_eq                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pmin                               |        :repeat:         |        :repeat:         |     :no_entry_sign:     |        :repeat:         |
| pmax                               |        :repeat:         |        :repeat:         |     :no_entry_sign:     |        :repeat:         |
| parithmetic_shift_right            |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |
| plogical_shift_right               |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |
| plogical_shift_left                |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |
| pabs                               |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |
| pround                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| print                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pceil                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pfloor                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pload                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| ploadu                             |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| ploadu + umask                     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| ploaddup                           |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |
| ploadquad                          |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |
| pstore                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu + umask                    |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pgather                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pscatter                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstore1                            |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pfirst                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| preverse                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| predux                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pfrexp_generic_get_biased_exponent |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pfrexp                             | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |     :no_entry_sign:     |
| pldexp                             | :ballot_box_with_check: |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pbroadcast4                        |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| punpackp                           |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| predux_half_dowto4                 |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| predux_mul                         |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |
| predux_min                         |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |
| predux_max                         |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |
| predux_any                         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| ptranspose                         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:*        |
| pblend                             |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |
| extract256                         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| extract128                         |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| cat256                             |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |

> AVX / AVX2

| function \ type                    |        Packet8f         |        Packet4d         |        Packet8i         |        Packet8h         |        Packet8bf        |        Packet4l         |
|:-----------------------------------|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| pset1                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| pset1frombits                      |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pzero                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |     :no_entry_sign:     |     :no_entry_sign:     |   :white_check_mark:    |
| peven_mask                         |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |
| pload1                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |
| padd                               |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    | :ballot_box_with_check: | :ballot_box_with_check: |   :white_check_mark:    |
| padd + umask                       |   :white_check_mark:    |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| plset                              |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| psub                               |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    | :ballot_box_with_check: | :ballot_box_with_check: |   :white_check_mark:    |
| paddsub                            |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pnegate                            |   :white_check_mark:    |   :white_check_mark:    | :ballot_box_with_check: |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| pconj                              | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pmul                               |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    | :ballot_box_with_check: | :ballot_box_with_check: |           :x:           |
| pdiv                               |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| pmadd                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pmsub                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pnmadd                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pnmsub                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pselect                            |        :repeat:         |        :repeat:         |     :no_entry_sign:     |        :repeat:         |        :repeat:         |     :no_entry_sign:     |
| ptrue                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pand                               |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |        :repeat:         |        :repeat:         |
| por                                |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pxor                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pandnot                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pcmp_le                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pcmp_lt                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pcmp_lt_or_nan                     |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| pcmp_eq                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pmin                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pmax                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| parithmetic_shift_right            |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |
| plogical_shift_right               |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |
| plogical_shift_left                |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |
| pabs                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pround                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| print                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| pceil                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| pfloor                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| pload                              |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| ploadu                             |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |   :white_check_mark:    |
| ploadu + umask                     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| ploaddup                           |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |
| ploadquad                          |        :repeat:         |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pstore                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu + umask                    |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pgather                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pscatter                           |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |        :repeat:         |
| pstore1                            | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |     :no_entry_sign:     | :ballot_box_with_check: |
| pfirst                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| preverse                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| predux                             |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |
| pfrexp_generic_get_biased_exponent |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pfrexp                             |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pldexp                             | :ballot_box_with_check: |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pbroadcast4                        |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| punpackp                           |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| predux_half_dowto4                 |        :repeat:         |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| predux_mul                         |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| predux_min                         |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| predux_max                         |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |
| predux_any                         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| ptranspose                         |        :repeat:*        |        :repeat:         |        :repeat:*        |        :repeat:         |        :repeat:*        |        :repeat:         |
| pblend                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| extract256                         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| extract128                         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| cat256                             |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |

> AVX512

| function \ type                    |        Packet16f        |        Packet8d         |        Packet16i        |        Packet16h        |       Packet16bf        |
|:-----------------------------------|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| pset1                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pset1frombits                      |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pzero                              |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| peven_mask                         |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pload1                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| padd                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| padd + umask                       |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| plset                              |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| psub                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| paddsub                            |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pnegate                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pconj                              | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pmul                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pdiv                               |        :repeat:         |        :repeat:         |                         | :ballot_box_with_check: | :ballot_box_with_check: |
| pmadd                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pmsub                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pnmadd                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pnmsub                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pselect                            |        :repeat:         |        :repeat:         |     :no_entry_sign:     |        :repeat:         |        :repeat:         |
| ptrue                              |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pand                               |        :repeat:         |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: |
| por                                |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pxor                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pandnot                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pcmp_le                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pcmp_lt                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pcmp_lt_or_nan                     |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| pcmp_eq                            |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pmin                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pmax                               |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| parithmetic_shift_right            |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| plogical_shift_right               |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| plogical_shift_left                |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |
| pabs                               |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pround                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| print                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| pceil                              |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| pfloor                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| pload                              |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadu                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadu + umask                     |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| ploaddup                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| ploadquad                          |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstore                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pstoreu + umask                    |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pgather                            |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| pscatter                           |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pstore1                            | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |     :no_entry_sign:     |     :no_entry_sign:     |
| pfirst                             |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| preverse                           |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| predux                             |        :repeat:         |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| pfrexp_generic_get_biased_exponent |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pfrexp                             | :ballot_box_with_check: |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pldexp                             |        :repeat:         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pbroadcast4                        |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| punpackp                           |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| predux_half_dowto4                 |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| predux_mul                         |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| predux_min                         |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| predux_max                         |        :repeat:         |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| predux_any                         |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| ptranspose                         |        :repeat:*        |        :repeat:*        |        :repeat:*        |        :repeat:*        |        :repeat:*        |
| pblend                             |       :question:        |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| extract256                         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| extract128                         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| cat256                             |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |

| function \ type |  float   |  double  |   int    |
|:----------------|:--------:|:--------:|:--------:|
| prefetch        | :repeat: | :repeat: | :repeat: |

> AVX

| to \ from |    Packet8h     |  Packet8f  |    Packet8bf    |
|:---------:|:---------------:|:----------:|:---------------:|
| Packet8h  |       --        | float2half | :no_entry_sign: |
| Packet8f  |   half2float    |     --     |    Bf16ToF32    |
| Packet8bf | :no_entry_sign: | F32ToBf16  |       --        |

> AVX512

| to \ from  |    Packet16h    | Packet16f  |   Packet16bf    |
|:----------:|:---------------:|:----------:|:---------------:|
| Packet16h  |       --        | float2half | :no_entry_sign: |
| Packet16f  |   half2float    |     --     |    Bf16ToF32    |
| Packet16bf | :no_entry_sign: | F32ToBf16  |       --        |

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

| to \ from |    Packet4i     | Packet4f |    Packet2d     |
|:---------:|:---------------:|:--------:|:---------------:|
| Packet4i  |       --        | :repeat: | :no_entry_sign: |
| Packet4f  |    :repeat:     |    --    |    :repeat:*    |
| Packet2d  | :no_entry_sign: | :repeat: |       --        |

| to \ from |    Packet8i     | Packet8f |    Packet8h     |    Packet8bf    |
|:---------:|:---------------:|:--------:|:---------------:|:---------------:|
| Packet8i  |       --        | :repeat: | :no_entry_sign: | :no_entry_sign: |
| Packet8f  |    :repeat:     |    --    |    :repeat:     |    :repeat:     |
| Packet8h  | :no_entry_sign: | :repeat: |       --        | :no_entry_sign: |
| Packet8bf | :no_entry_sign: | :repeat: | :no_entry_sign: |       --        |

| to \ from  |    Packet16i    | Packet16f |    Packet16h    |   Packet16bf    |
|:----------:|:---------------:|:---------:|:---------------:|:---------------:|
| Packet16i  |       --        | :repeat:  | :no_entry_sign: | :no_entry_sign: |
| Packet16f  |    :repeat:     |    --     |    :repeat:     |    :repeat:     |
| Packet16h  | :no_entry_sign: | :repeat:  |       --        | :no_entry_sign: |
| Packet16bf | :no_entry_sign: | :repeat:  | :no_entry_sign: |       --        |

### `preinterpret` functions

| to \ from | Packet4i |    Packet4f     |    Packet2d     |
|:---------:|:--------:|:---------------:|:---------------:|
| Packet4i  |    --    |    :repeat:     |    :repeat:     |
| Packet4f  | :repeat: |       --        | :no_entry_sign: |
| Packet2d  | :repeat: | :no_entry_sign: |       --        |

| to \ from | Packet8i | Packet8f |
|:----------|:--------:|:--------:|
| Packet8i  |    --    | :repeat: |
| Packet8f  | :repeat: |    --    |

| to \ from |    Packet16i    |        Packet16f        |        Packet8d         |    Packet8f     |
|:---------:|:---------------:|:-----------------------:|:-----------------------:|:---------------:|
| Packet16i |       --        |        :repeat:         |     :no_entry_sign:     | :no_entry_sign: |
| Packet16f |    :repeat:     | :ballot_box_with_check: |        :repeat:         | :no_entry_sign: |
| Packet8d  | :no_entry_sign: |        :repeat:         | :ballot_box_with_check: | :no_entry_sign: |
| Packet8f  | :no_entry_sign: |        :repeat:         |     :no_entry_sign:     |       --        |

## MathFunctions.h

| function \ type |        Packet4f         |        Packet2d         |    Packet16b    |        Packet8f         |        Packet4d         |    Packet8h     |    Packet8bf    |        Packet16f        |        Packet8d         |        Packet16h        |       Packet16bf        |
|:----------------|:-----------------------:|:-----------------------:|:---------------:|:-----------------------:|:-----------------------:|:---------------:|:---------------:|:-----------------------:|:-----------------------:|:-----------------------:|:-----------------------:|
| plog            | :ballot_box_with_check: | :ballot_box_with_check: | :no_entry_sign: | :ballot_box_with_check: | :ballot_box_with_check: | :no_entry_sign: | :no_entry_sign: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| plog2           | :ballot_box_with_check: | :ballot_box_with_check: | :no_entry_sign: | :ballot_box_with_check: | :ballot_box_with_check: | :no_entry_sign: | :no_entry_sign: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| plog1p          | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| pexpm1          | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| pexp            | :ballot_box_with_check: | :ballot_box_with_check: | :no_entry_sign: | :ballot_box_with_check: | :ballot_box_with_check: | :no_entry_sign: | :no_entry_sign: |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| psin            | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| pcos            | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| psqrt           |        :repeat:         |        :repeat:         |    :repeat:     |        :repeat:         |        :repeat:         | :no_entry_sign: | :no_entry_sign: |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| prsqrt          |        :repeat:         |     :no_entry_sign:     | :no_entry_sign: |        :repeat:         |     :no_entry_sign:     | :no_entry_sign: | :no_entry_sign: |        :repeat:         |        :repeat:         | :ballot_box_with_check: | :ballot_box_with_check: |
| preciprocal     |        :repeat:         |     :no_entry_sign:     | :no_entry_sign: |        :repeat:         |     :no_entry_sign:     | :no_entry_sign: | :no_entry_sign: |        :repeat:         |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| ptanh           | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :no_entry_sign: | :no_entry_sign: | :ballot_box_with_check: |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| pfrexp          |     :no_entry_sign:     |     :no_entry_sign:     | :no_entry_sign: |     :no_entry_sign:     |     :no_entry_sign:     |    :repeat:     |    :repeat:     |     :no_entry_sign:     |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |
| pldexp          |     :no_entry_sign:     |     :no_entry_sign:     | :no_entry_sign: |     :no_entry_sign:     |     :no_entry_sign:     |    :repeat:     |    :repeat:     |     :no_entry_sign:     |     :no_entry_sign:     | :ballot_box_with_check: | :ballot_box_with_check: |

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
| ploadquad       |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |
| pstore          | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pstoreu         | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| pgather         |        :repeat:         |        :repeat:         |     :no_entry_sign:     |        :repeat:         |        :repeat:         |        :repeat:         |
| pscatter        |        :repeat:         |        :repeat:         |     :no_entry_sign:     |        :repeat:         |        :repeat:         |        :repeat:         |
| prefetch        |        :repeat:         |     :no_entry_sign:     |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| pfirst          |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |        :repeat:         |
| preverse        |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| predux          |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| predux_mul      |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| pcplxflip       |        :repeat:         |        :repeat:         | :ballot_box_with_check: |        :repeat:         |        :repeat:         |        :repeat:         |
| pdiv            | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |
| ptranspose      |        :repeat:         |        :repeat:         |     :no_entry_sign:     |        :repeat:         |        :repeat:*        |        :repeat:         |
| pblend          |        :repeat:         |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |     :no_entry_sign:     |
| psqrt           | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: | :ballot_box_with_check: |

* `Packet4cf predux_half_dowto4<Packet8cf>(const Packet8cf& a)`
