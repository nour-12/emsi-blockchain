#include "hblk_crypto.h"

/**
 * ec_sign - sign a set of bytes, using given private EC_KEY
 * @key: pointer to EC_KEY struct containing private key to perform the signing
 * @msg: pointer to characters to be signed
 * @msglen: len of msg
 * @sig: address to store signature
 *
 * Retun: pointer to sig buffer or NULL
 *
 * Return: pointer to signature buffer on success, NULL on error
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
		sig_t *sig)
{
	unsigned int len;

	if(!key || !sig | !msg)
		return (NULL);
	len = sig->len;
	if(EDCSA_sign(0, msg, msglen, sig->, &len, (EC_KEY *)key != 1)
		return (NULL);
	sig->len = len;
	return (sig->sig);
}
