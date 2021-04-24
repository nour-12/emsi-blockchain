#include "hblk_crypto.h"

/**
 * ec_to_pub - extracting public key from EC_KEY struct
 * @key: point to EC_KEY structure
 * @pub: adr of buffer to populate with pub key
 * Return: adr of populated buffer or NULL
 */

uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
const EC_POINT  *publicKey;
const EC_GROUP  *group;

if (key == NULL || pub == NULL)
return (NULL);


publicKey = EC_KEY_get0_public_key(key);
group = EC_KEY_get0_group(key);

if (!EC_POINT_point2oct(group, publicKey, POINT_CONVERSION_UNCOMPRESSED, pub,
				EC_PUB_LEN, NULL))
return (NULL);

return (pub);
}
