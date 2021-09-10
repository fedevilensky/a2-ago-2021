#pragma once

#include "AVL.cpp"

template <class K, class V>
class AVLTable
{
public:
    AVLTable()
    {
        tree = new AVL<Pair<K, V>>();
    }

    int size()
    {
        tree->size();
    }

    V get(K key)
    {
        Pair<K, V> p = Pair<K, V>(key);
        Pair<K, V> found = tree->find(p);
        if (found == nullptr)
        {
            return nullptr;
        }
        return found.value;
    }

    void set(K key, V value)
    {
        // add a key value pair to the map, if the key already exists, delete it and add the new value key pair
        Pair<K, V> p = Pair<K, V>(key, value);
        if (tree->contains(p))
        {
            tree->remove(p);
        }
        tree->add(p);
    }

    bool exists(K key)
    {
        //returns true if the key exists on the map
        Pair<K, V> p = Pair<K, V>(key);
        return tree->contains(p);
    }

    void clear()
    {
        tree->clear();
    }

private:
    template <class K, class V>
    struct Pair
    {
        K key;
        V value;

        Pair(K key)
        {
            this->key = key;
        }

        Pair(K key, V value)
        {
            this->key = key;
            this->value = value;
        }

        bool operator<(const Pair &other)
        {
            return key < other.key;
        }

        bool operator>(const Pair &other)
        {
            return key > other.key;
        }

        bool operator==(const Pair &other)
        {
            return key == other.key;
        }
    };
    AVL<Pair<K, V>> *tree;
};
