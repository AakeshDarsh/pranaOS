/*
 * Copyright (c) 2021, Krisna Pranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

namespace Kernel::PCI {

enum VendorID {
    VirtIO = 0x1af4,
    Intel = 0x8086,
    WCH = 0x1c00,
    RedHat = 0x1b36,
    Realtek = 0x10ec,
    QEMUOld = 0x1234,
    VirtualBox = 0x80ee
};

enum DeviceID {
    VirtIOConsole = 0x1003,
    VirtIOEntropy = 0x1005,
    VirtIOGPU = 0x1050,
};

}