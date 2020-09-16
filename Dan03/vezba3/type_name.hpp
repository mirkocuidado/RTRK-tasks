#ifndef _TYPE_NAME_
#define _TYPE_NAME_

#include <string_view>

template <class T>
constexpr std::string_view type_name()
{
    std::string_view p = __PRETTY_FUNCTION__;
#ifdef __clang__
    return std::string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    return std::string_view(p.data() + 49, p.find(';', 49) - 49);
#endif
}

#endif
