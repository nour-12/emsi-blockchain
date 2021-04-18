#include "hblk_crypto.h"


uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH])
{
    SHA256_CTX sha256;

    if(digest && s)
    {

        SHA256_Init(&sha256);
        SHA256_Update(&sha256,s,len);
        SHA256_Final(digest,&sha256);

        return digest;
    }

    else 
        return NULL;
}
