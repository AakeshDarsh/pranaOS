/*
 * Copyright (c) 2021, Krisna Pranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

// includes
#include <base/Types.h>
#include <kernel/bus/pci/Definitions.h>

namespace Kernel {
class PCI::DeviceController {
public:
    Address pci_address() const { return m_pci_address; };

    virtual ~DeviceController() = default;
    void enable_pin_based_interrupts() const;
    void disable_pin_based_interrupts() const;

    bool is_msi_capable() const;
    bool is_msix_capable() const;

    void enable_message_signalled_interrupts();
    void disable_message_signalled_interrupts();

    void enable_extended_message_signalled_interrupts();
    void disable_extended_message_signalled_interrupts();

protected:
    explicit DeviceController(Address pci_address);

private:
    Address m_pci_address;
};
}