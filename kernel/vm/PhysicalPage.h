/*
 * Copyright (c) 2021, Krisna Pranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

// includes
#include <base/NonnullRefPtr.h>
#include <kernel/PhysicalAddress.h>

namespace Kernel {

enum class MayReturnToFreeList : bool {
    No,
    Yes
};

class PhysicalPage {
    BASE_MAKE_NONCOPYABLE(PhysicalPage);
    BASE_MAKE_NONMOVABLE(PhysicalPage);

    friend class MemoryManager;

public:
    PhysicalAddress paddr() const;

    void ref()
    {
        m_ref_count.fetch_add(1, Base::memory_order_acq_rel);
    }

    void unref()
    {
        if (m_ref_count.fetch_sub(1, Base::memory_order_acq_rel) == 1)
            free_this();
    }

    static NonnullRefPtr<PhysicalPage> create(PhysicalAddress, MayReturnToFreeList may_return_to_freelist = MayReturnToFreeList::Yes);

    u32 ref_count() const { return m_ref_count.load(Base::memory_order_consume); }

    bool is_shared_zero_page() const;
    bool is_lazy_committed_page() const;

private:
    explicit PhysicalPage(MayReturnToFreeList may_return_to_freelist);
    ~PhysicalPage() = default;

    void free_this();

    Atomic<u32> m_ref_count { 1 };
    MayReturnToFreeList m_may_return_to_freelist { MayReturnToFreeList::Yes };
};

struct PhysicalPageEntry {
    union {
        struct {
            PhysicalPage physical_page;
        } allocated;

        struct {
            i16 next_index;
            i16 prev_index;
        } freelist;
    };
};

}