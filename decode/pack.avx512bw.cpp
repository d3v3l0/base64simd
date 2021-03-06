namespace base64 {

    namespace avx512bw {

#define packed_dword(x) _mm512_set1_epi32(x)

        __m512i pack_madd(const __m512i values) {

            const __m512i merge_ab_and_bc = _mm512_maddubs_epi16(values, packed_dword(0x01400140));

            return _mm512_madd_epi16(merge_ab_and_bc, packed_dword(0x00011000));
         }

#undef packed_dword

    } // namespace avx512bw

} // namespace base64
