/*
 * Copyright (c) 2021, Krisna Pranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

// includes
#include <kernel/devices/PCSpeaker.h>
#include <kernel/IO.h>
#include <kernel/time/PIT.h>

void PCSpeaker::tone_on(int frequency)
{
    IO::out8(PIT_CTL, TIMER2_SELECT | WRITE_WORD | MODE_SQUARE_WAVE);
    u16 timer_reload = BASE_FREQUENCY / frequency;

    IO::out8(TIMER2_CTL, LSB(timer_reload));
    IO::out8(TIMER2_CTL, MSB(timer_reload));

    IO::out8(0x61, IO::in8(0x61) | 3);
}

void PCSpeaker::tone_off()
{
    IO::out8(0x61, IO::in8(0x61) & ~3);
}