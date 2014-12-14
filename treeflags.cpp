#include "treeflags.h"

TreeFlags::TreeFlags(TreeFlags::TreeFlag flag) :
    _flags((unsigned long)flag)
{
}

TreeFlags::TreeFlags(unsigned long flags) :
    _flags(flags)
{
}

TreeFlags TreeFlags::operator~() const
{
    return TreeFlags(~_flags);
}

TreeFlags TreeFlags::operator&(const TreeFlags::TreeFlag &flag) const
{
    return TreeFlags(_flags & (unsigned long)flag);
}

TreeFlags TreeFlags::operator|(const TreeFlags::TreeFlag &flag) const
{
    return TreeFlags(_flags | (unsigned long)flag);
}

TreeFlags TreeFlags::operator^(const TreeFlags::TreeFlag &flag) const
{
    return TreeFlags(_flags ^ (unsigned long)flag);
}

TreeFlags& TreeFlags::operator&=(const TreeFlags::TreeFlag &flag)
{
    _flags = _flags & (unsigned long)flag;
    return *this;
}

TreeFlags& TreeFlags::operator|=(const TreeFlags::TreeFlag &flag)
{
    _flags |= _flags | (unsigned long)flag;
    return *this;
}

TreeFlags& TreeFlags::operator^=(const TreeFlags::TreeFlag &flag)
{
    _flags |= _flags ^ (unsigned long)flag;
    return *this;
}

TreeFlags::operator bool() const
{
    return _flags != TreeFlags::NoNodeFlags;
}

bool TreeFlags::operator!() const
{
    return _flags == TreeFlags::NoNodeFlags;
}
