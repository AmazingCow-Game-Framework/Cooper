// header
#include "include/private/Logger/Logger.h"
// AmazingCow Libs
#include "acow/cpp_goodies.h"

CoreLog::Logger*
Cooper::Private::Logger() noexcept
{
    acow_local_persist CoreLog::Logger s_logger;
    return &s_logger;
}