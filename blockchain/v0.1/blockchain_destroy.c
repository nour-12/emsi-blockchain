#include "blockchain.h"

/**
 * blockchain_destroy - deletes an existing Blockchain
 * @blockchain: points to the Blockchain structure to delete
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	if (!blockchain)
		return;
	llist_destroy(blockchain->chain, 1, NULL);
	free(blockchain);
}
