#pragma once

#include "AVL.cpp"

template <class T>
class AVLSet
{
public:
    int size()
    {
        return tree.size();
    }

    bool contains(T data)
    {
        return tree.contains(data);
    }

    void clear()
    {
        tree.clear();
    }

    //post: el dato existe en el Set
    void add(T data)
    {
        if (!tree.contains(data))
        {
            tree.add(data);
        }
    }

    void remove(T data)
    {
        tree.remove(data);
    }

    void join(AVLSet<T> *other)
    {
        auto iter = other->iterator();
        while (iter->hasNext())
        {
            T otherData = iter->next();
            this->add(otherData);
        }
        // returns the union of this set and other set
        // TODO
    }

    void intersect(AVLSet<T> *other)
    {
        auto iter = this->iterator();
        while (iter->hasNext())
        {
            T data = iter->next();
            if (!other->contains(data))
            {
                this->remove(data);
            }
        }
    }

    void difference(AVLSet<T> *other)
    {
        auto iter = other->iterator();
        while (iter->hasNext())
        {
            T otherData = iter->next();
            if (this->contains(otherData))
            {
                this->remove(otherData);
            }
            else
            {
                this->add(otherData);
            }
        }
    }

    Iterator<T> *iterator()
    {
        return tree.iterator();
    }

private:
    AVL<T> tree = AVL<T>();
};
