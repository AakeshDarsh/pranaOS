/*
 * Copyright (c) 2021, johnsmith5c12
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <libgfx/PNGLoader.h>
#include <stddef.h>
#include <stdint.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    Gfx::load_png_from_memory(data, size);
    return 0;
}
