#include "blockchain.h"


/**
 * block_destroy - frees a block
 * @block: points to the Block to delete
 */
void block_destroy(block_t *block)
{
	free(block);
}
