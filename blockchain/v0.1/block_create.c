#include "blockchain.h"


/**
 * block_create - creates a new block in the sequence
 * @prev: pointer to the previous Block in the Blockchain
 * @data: points to a memory area to duplicate in the Block’s data
 * @data_len: stores the number of bytes to duplicate in data
 *
 * Return: ptr to a new block
 */
block_t *block_create(block_t const *prev,
					int8_t const *data, uint32_t data_len)
{
	block_t *newB = calloc(1, sizeof(*newB));
	uint32_t maxL = B_DATA_MAX;

	if (!newB)
		return (NULL);

	if (data_len < B_DATA_MAX)
		maxL = data_len;

	memcpy(&(newB->data.buffer), data, maxL);
	newB->data.len = maxL;
	newB->info.index = prev->info.index + 1;
	newB->info.timestamp = (uint64_t)time(NULL);

	memcpy(&(newB->info.prev_hash), prev->hash, SHA256_DIGEST_LENGTH);

	return (newB);
}
