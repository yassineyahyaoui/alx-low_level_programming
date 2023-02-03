#include "hash_tables.h"

/**
 * hash_table_delete - delete table
 * @ht: pointer to struct of hash table
 *
 * Description: free and delete hash table
 * Return: na
 */
void hash_table_delete(hash_table_t *ht)
{
    hash_node_t *temp, *current;
    unsigned long int i;
    
    if (!ht)
        return;
    
    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current)
        {
            temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht->array);
    free(ht);
}
