#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 32
#define TABLE_SIZE 15

typedef struct dictionary {
    const char *key;
    const char *value;
} dictionary;

dictionary *table[TABLE_SIZE];

void init(){
    for (int i=0; i < TABLE_SIZE; i++){
        table[i] = NULL;
    }
}

unsigned int hash(const char *name){
    int length = strnlen(name, BUFFER_SIZE);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

bool insert(dictionary *item){
    if (item == NULL) return false;
    int index = hash(item->key);
    if (table[index] != NULL){
        return false;
    }
    table[index] = item;
    return true;
}

dictionary *lookup(const char *name){
    int index = hash(name);
    if (table[index] != NULL && strcmp(table[index]->key, name) == 0){
        return table[index];
    }
    return NULL;
}

void print_table(){
    for (int i = 0; i < TABLE_SIZE; i++){
        if (table[i] == NULL){
            printf("%i\t\t---\n", i);
        }else {
            printf("%i\t\t%s\n", i, table[i]->key);
        }
    }
}


int main() {
    dictionary anna = {"anna", "apple"};
    dictionary key = {"kent", "mango"};
    dictionary yuri = {"yuri", "apple"};
    dictionary jeje = {"jeje", "honey"};
    insert(&anna);
    insert(&key);
    insert(&yuri);
    insert(&jeje);
    print_table();
    printf("\n\n%s\n", lookup("je")->key);
    return 0;
}