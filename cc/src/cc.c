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

#include <corecrypto/cc.h>

void cc_zero(size_t size, void *data)
{
    memset(data, 0, size);
}

void cc_clear(size_t len, void *dst)
{
    cc_zero(len, dst);
}

void *cc_copy(size_t size, void *dst, const void *src)
{
    return memcpy(dst, src, size);
}

void cc_xor(size_t size, void *result, const void *left, const void *right)
{
    size_t i;
    uint8_t *res8 = (uint8_t *)result;
    const uint8_t *l8 = (const uint8_t *)left;
    const uint8_t *r8 = (const uint8_t *)right;

    for (i = 0; i < size; i++)
    res8[i] = l8[i] ^ r8[i];
}

int cc_cmp_safe(size_t size, const void *a, const void *b)
{
    const unsigned char *_a = (const unsigned char *)a;
    const unsigned char *_b = (const unsigned char *)b;
    unsigned char result = 0;
    size_t i;

    for (i = 0; i < size; i++)
    {
	    result |= _a[i] ^ _b[i];
    }

    return result;
}

void *cc_muxp(int s, const void *a, const void *b)
{
    uintptr_t mask = -(s != 0);
    uintptr_t ret = mask & (((uintptr_t)a) ^ ((uintptr_t)b));
    ret = ret ^ ((uintptr_t)a);
    return (void *)ret;
}
