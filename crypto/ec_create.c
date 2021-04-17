#include <stdio.h>
#include "hblk_crypto.h"

EC_KEY *ec_create(void)
{
    EC_KEY *pointer;

    pointer = EC_KEY_new(EC_CURVE);
    if (!pointer) return NULL;

    if (EC_KEY_gen_key(pointer) != 1)
    {
        EC_KEY_free(pointer);
        return NULL;
    }

    return pointer;
}
