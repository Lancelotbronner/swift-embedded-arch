#include <AArch64.h>

static_assert((sizeof(struct CurrentEL) == 8), "64-bit register");
static_assert((sizeof(struct MIPDR) == 8), "64-bit register");
