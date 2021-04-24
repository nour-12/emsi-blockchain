#include "blockchain.h"


/**
* get_blocks - read blocks from a file
* @fp: file pointer
* @swap_endian: a flag to swap endianness
* @blockchain: blockchain
* @size: number of blocks to read
*
* Return: 0 | -1
*/
int get_blocks(FILE *fp, uint8_t swap_endian,
		blockchain_t *blockchain, int size)
{
	block_t *b;
	uint32_t data_len;
	long int genesis_size;
	int i = LOOP_START;

	genesis_size = sizeof(b->info) + sizeof(b->hash) + 20L;
	fseek(fp, genesis_size, SEEK_CUR);

	for (i = 0; i < size - 1; ++i)
	{
		b = malloc(sizeof(*b));
		if (!b)
			return (-1);
		fread(&b->info, sizeof(b->info), 1, fp);
		fread(&data_len, sizeof(data_len), 1, fp);
		if (swap_endian)
		{
			_swap_endian(&b->info.index, sizeof(b->info.index));
			_swap_endian(&b->info.difficulty, sizeof(b->info.difficulty));
			_swap_endian(&b->info.timestamp, sizeof(b->info.timestamp));
			_swap_endian(&b->info.nonce, sizeof(b->info.nonce));
		}

		fread(&b->data.buffer, data_len, 1, fp);
		fread(&b->hash, SHA256_DIGEST_LENGTH, 1, fp);
		if (swap_endian)
		{
			_swap_endian(&b->info.index, sizeof(b->info.index));
			_swap_endian(&b->info.difficulty, sizeof(b->info.difficulty));
			_swap_endian(&b->info.timestamp, sizeof(b->info.timestamp));
			_swap_endian(&b->info.nonce, sizeof(b->info.nonce));
		}
		b->data.len = data_len;
		*(b->data.buffer + data_len) = '\0';
		llist_add_node(blockchain->chain, b, ADD_NODE_REAR);
	}
	return (0);
}

/**
 * blockchain_deserialize - deserializes blockchain from file
 * @path: contains the path to a file to load the Blockchain from
 *
 * Return: pointer to the deserialized Blockchain upon success, or NULL
 */
blockchain_t *blockchain_deserialize(char const *path)
{
	header_t h;
	blockchain_t *bc;
	int size;
	uint8_t swap_endian;
	FILE *fp = NULL;

	if (path)
	{
		fp = fopen(path, "r");
		if (!fp)
			return (NULL);
	}
	else
	{
		return (NULL);
	}

	fread(&h, sizeof(h), 1, fp);
	if (memcmp(h.hblk_magic, "HBLK", 4) ||
		memcmp(h.hblk_version, "0.1", 3))
		return (fclose(fp), NULL);

	bc = blockchain_create();
	if (!bc)
		return (fclose(fp), NULL);

	swap_endian = _get_endianness() != h.hblk_endian;
	size = h.hblk_blocks;

	if (swap_endian)
		_swap_endian(&size, sizeof(size));

	if (get_blocks(fp, swap_endian, bc, size) == -1)
		return (blockchain_destroy(bc), fclose(fp), NULL);

	fclose(fp);
	return (bc);
}
