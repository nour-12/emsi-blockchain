#include "hblk_crypto.h"

/**
 * ec_sign - sign a message using an EC private key
 *
 * @key: pointer to the EC key pair containing the private key to be used
 * @msg: message to be signed
 * @msglen: length of @message
 * @sig: address at which to store the signature
 *
 * Return: If key, msg, or sig is NULL, or if an error occurs, return NULL.
 * Otherwise, return a pointer to the buffer containing the signature.
 */


uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
	size_t msglen, sig_t *sig)
{
if (!key || !msg)
{
return (NULL);
}

if (ECDSA_sign(0, msg, msglen, sig->sig,
		(unsigned int *)&sig->len, (EC_KEY *)key)==0)
{
	return (NULL);
}

return ((unit8_t *)sig->sig);

}
