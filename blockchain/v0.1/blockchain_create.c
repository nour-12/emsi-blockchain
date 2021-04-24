#include "blockchain.h"


/**
 * blockchain_create - creates a genesis blockchain
 *
 * Return: ptr to the new blockchain
 */
blockchain_t *blockchain_create(void)
{
	blockchain_t *c = calloc(1, sizeof(*c));
	block_t *block = calloc(1, sizeof(*block));
	llist_t *list = llist_create(MT_SUPPORT_TRUE);

	if (!c || !block || !list)
	{
		free(c), free(block), llist_destroy(list, 1, NULL);
		return (NULL);
	}

	block->info.timestamp = G_TIMESTAMP;
	memcpy(&(block->data.buffer), G_DATA, G_DATA_LEN);
	block->data.len = G_DATA_LEN;
	memcpy(&(block->hash), G_HASH, SHA256_DIGEST_LENGTH);

	if (llist_add_node(list, block, ADD_NODE_FRONT))
	{
		free(c), free(block), llist_destroy(list, 1, NULL);
		return (NULL);
	}

	c->chain = list;
	return (c);
}
