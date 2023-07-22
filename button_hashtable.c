#include "button_hashtable.h"

HashTable *hash_table_create() {
    HashTable *hash_table = g_malloc(sizeof(HashTable));
    hash_table->table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
    return hash_table;
}

void hash_table_insert(HashTable *hash_table, const gchar *key, gpointer value) {
    g_hash_table_insert(hash_table->table, g_strdup(key), value);
}

gpointer hash_table_lookup(HashTable *hash_table, const gchar *key) {
    return g_hash_table_lookup(hash_table->table, key);
}

gboolean hash_table_contains(HashTable *hash_table, const gchar *key) {
    return g_hash_table_contains(hash_table->table, key);
}

guint hash_table_size(HashTable *hash_table) {
    return g_hash_table_size(hash_table->table);
}

void hash_table_remove(HashTable *hash_table, const gchar *key) {
    g_hash_table_remove(hash_table->table, key);
}

void hash_table_destroy(HashTable *hash_table) {
    g_hash_table_destroy(hash_table->table);
    g_free(hash_table);
}
