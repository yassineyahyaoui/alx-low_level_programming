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


/******************************************/

#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table.
 * @size: number of array slots to make the table.
 *
 * Return: pointer to the hash table created, or NULL if malloc failed.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (!ht)
        return (NULL);
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (!ht->array)
        return (NULL);
    for (i = 0; i < size; i++)
        ht->array[i] = NULL;
    ht->size = size;
    ht->shead = NULL;
    ht->stail = NULL;
    return (ht);
}

shash_node_t *shash_node_create(const char *key, const char *value)
{
    shash_node_t *new;

    new = malloc(sizeof(shash_node_t));
    if (!new)
        return (NULL);
    new->key = strdup(key);
    if (!new->key)
    {
        free(new);
        return (NULL);
    }
    new->value = strdup(value);
    if (!new->value)
    {
        free(new->key);
        free(new);
        return (NULL);
    }
    new->next = NULL;
    new->sprev = NULL;
    new->snext = NULL;
    return (new);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new, *temp;
    unsigned long int hash_code;

    if (!ht || !key)
        return (0);
    new = shash_node_create(key, value);
    if (!new)
        return (0);
    hash_code = key_index((unsigned char *)key, ht->size);
    temp = ht->array[hash_code];
    while (temp && temp->next)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value);
            temp->value = strdup(value);
            free(new->key);
            free(new->value);
            free(new);
            return (1);
        }
        temp = temp->next;
    }
    if (temp && strcmp(temp->key, key) == 0)
    {
        free(temp->value);
        temp->value = strdup(value);
        free(new->key);
        free(new->value);
        free(new);
        return (1);
    }
    if (ht->array[hash_code] == NULL)
    {
        ht->array[hash_code] = new;
        new->next = NULL;
    }
    else
        temp->next = new;
    new->sprev = ht->stail;
    if (ht->stail)
        ht->stail->snext = new;
        char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int hash_code;
    shash_node_t *node;

    if (!key || !ht)
        return (NULL);

    hash_code = key_index((unsigned char *)key, ht->size);
    node = ht->array[hash_code];

    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }
    return (NULL);
}
}

void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;

    if (!ht)
        return;

    node = ht->shead;
    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->snext;
        if (node)
            printf(", ");
    }
    printf("\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;

    if (!ht)
        return;

    node = ht->stail;
    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->sprev;
        if (node)
            printf(", ");
    }
    printf("\n");
}

void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *temp;
    unsigned long int i;

    if (!ht)
        return;

    node = ht->shead;
    while (node != NULL)
    {
        temp = node->snext;
        free(node->key);
        free(node->value);
        free(node);
        node = temp;
    }

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            temp = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = temp;
        }
    }
    free(ht->array);
    free(ht);
}
