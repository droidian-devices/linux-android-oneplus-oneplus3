/*
 * Linux backport symbols for kernels 3.2.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/hex.h>

int hex2bin(u8 *dst, const char *src, size_t count)
{
    if (count % 2 != 0) {
        return -1; // Handle odd number of characters
    }

    for (size_t i = 0; i < count; i += 2) {
        int hi = hex_to_bin(src[i]);
        int lo = hex_to_bin(src[i + 1]);

        if ((hi < 0) || (lo < 0)) {
            return -1; // Handle invalid characters
        }

        *dst++ = (hi << 4) | lo;
    }

    return 0;
}
EXPORT_SYMBOL_GPL(hex2bin);
