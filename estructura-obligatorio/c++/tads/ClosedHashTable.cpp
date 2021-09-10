#pragma once

#include <list>
#include "Hasher.h"

template <class K, class V>
class ClosedHashTable{
public:
    ClosedHashTable(Hasher<K> *hasher, int size=113)
    {
        this->hasher = hasher;
        this->table = new Pair[size];
    }

    ~ClosedHashTable(){
        delete[] table;
        delete hasher;
    }

    // pre: -
    // post: queda asociado la llave y el valor en la tabla
    void set(K key, V value){
        //TODO
    }


    // pre: key existe en la tabla
    // post: devuelve el valor asociado a key en la tabla
    V get(K key){
        //TODO
    }

    // pre: - 
    // post: devuelve true sii key esta en la tabla
    bool has(K key){
        //TODO
    }


    // pre: - 
    // post: key no esta en la tabla
    void remove(K key){
        //TODO
    }

    // pre: -
    // post: la tabla esta vacia
    void clear(){
        //TODO
    }

private:
    struct Pair{
        K key;
        V value;

        bool operator == (const Pair& other){
            return key == other.key;
        }
    };

    Pair *table;
    Hasher<K> *hasher;
};

