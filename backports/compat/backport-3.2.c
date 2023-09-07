/*
 * Linux backport symbols for kernels 3.2.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/export.h>

int hex2bin(u8 *dst, const char *src, size_t count)
{
    while (count--) {
        int hi = (*src <= '9') ? (*src - '0') : ((*src & ~0x20) - 'A' + 10);
        int lo = (*(++src) <= '9') ? (*src - '0') : ((*src & ~0x20) - 'A' + 10);
        *dst++ = (hi << 4) | lo;
        src++;
    }
    return 0;
}
EXPORT_SYMBOL_GPL(hex2bin);
