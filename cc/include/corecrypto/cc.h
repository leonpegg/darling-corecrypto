/**
 * Copyright (c) 2016 Lubos Dolezel
 *
 * This file is part of Darling CoreCrypto.
 *
 * Darling is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _CORECRYPTO_CC_H
#define _CORECRYPTO_CC_H

#include <corecrypto/cc_config.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define cc_aligned_struct(alignment) \
    typedef struct \
    { \
        uint8_t dummy[alignment]; \
    } __attribute__((aligned(alignment)))

#define cc_ctx_n(type, size) ((sizeof(type) + size - 1) / sizeof(type))

#define cc_ctx_sizeof(type, size) sizeof(type[cc_ctx_n(type, size)])

#define cc_ctx_decl(type, size, name) type name[cc_ctx_n(type, size)]

/**
 * @fn void cc_zero(size_t size, void *data)
 * @param size
 * @param data 
 */
void cc_zero(size_t size, void *data);

/**
 * @fn void cc_clear(size_t len, void *dst)
 * @param len
 * @param dst 
 */
void cc_clear(size_t len, void *dst);

/**
 * @fn void *cc_copy(size_t size, void *dst, const void *src)
 * @param size
 * @param dst
 * @param src
 */
void *cc_copy(size_t size, void *dst, const void *src);

/**
 * @fn void cc_xor(size_t size, void *result, const void *left, const void *right)
 * @param size
 * @param result
 * @param left
 * @param right
 */
void cc_xor(size_t size, void *result, const void *left, const void *right);

/**
 * @fn int cc_cmp_safe(size_t num, const void *ptr1, const void *ptr2)
 * @brief Constant-time comparison function
 * @param num
 * @param ptr1
 * @param ptr2
 * @see https://cryptocoding.net/index.php/Coding_rules#Compare_secret_strings_in_constant_time
 */
int cc_cmp_safe(size_t num, const void *ptr1, const void *ptr2);

/**
 * @fn void *cc_muxp(int s, const void *a, const void *b)
 * @param s
 * @param a
 * @param b
 * @see https://cryptocoding.net/index.php/Coding_rules#Avoid_branchings_controlled_by_secret_data 
 */
void *cc_muxp(int s, const void *a, const void *b);

#define CC_SWAP(a, b) \
    { \
        __typeof__(a) tmp = a; \
        a = b; \
        b = tmp; \
    }

// Like the max macro, but params are evaluated only once
#define CC_MAX(a, b) ({ \
    __typeof__(a) ax = a; \
    __typeof__(b) bx = b; \
    ax > bx ? ax : bx; \
})

// Like the min macro, but params are evaluated only once
#define CC_MIN(a, b) ({ \
    __typeof__(a) ax = a; \
    __typeof__(b) bx = b; \
    ax < bx ? ax : bx; \
})

#endif // _CORECRYPTO_CC_H
