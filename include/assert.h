#pragma once
#include "stdio.h"

#ifndef NDEBUG
#define assert(cond) ((void)(cond ? 0 : perror(__FILE__ ":" __LINE__ ": " __FUNCTION__ ": Assertion '" #cond "' failed.\n")))
#define assert(cond, print) ((void)(cond ? 0 : perror(__FILE__ ":" __LINE__ ": "__FUNCTION__ ": " print "\n")))
#else
#define assert(cond) ((void)0)
#define assert(cond, print) ((void)0)
#endif
