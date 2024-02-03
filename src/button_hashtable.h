#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <glib.h>

typedef struct {
    GHashTable *table;
} HashTable;

HashTable *hash_table_create();

void hash_table_insert(HashTable *hash_table, const gchar *key, gpointer value);

gpointer hash_table_lookup(HashTable *hash_table, const gchar *key);

gboolean hash_table_contains(HashTable *hash_table, const gchar *key);

guint hash_table_size(HashTable *hash_table);

void hash_table_remove(HashTable *hash_table, const gchar *key);

void hash_table_destroy(HashTable *hash_table);

#endif  // HASH_TABLE_H
