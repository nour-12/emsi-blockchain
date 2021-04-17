#include "hblk_crypto.h"


uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]){

    const EC_GROUP *group0, EC_POINT *point0;


    if(!key || !pub)
        return NULL;
    
    group0 = EC_KEY_get0_group (key);
    point0 = EC_KEY_get0_public_key (key);

    if(!EC_POINT_point2oct(group0, point0,POINT_CONVERSION_UNCOMPRESSED, pub, EC_PUB_LEN, NULL))
        return NULL;

    return pub;

}
