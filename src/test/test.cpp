#include "test.hpp"

#ifdef MACRO
    #define MACRO 1
#else
    #define MACRO 0
#endif

namespace test 
{
    int invoke()
    {
        return MACRO ? 1 : 0;
    }
};