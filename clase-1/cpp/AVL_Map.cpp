#include <stdlib.h>  //abs
#include <algorithm> //max
#include <iostream>  //cout

template <class T>
class AVL
{
    class AVLIterator
    {
        struct IteratorNode
        {
            T data;
            IteratorNode next;

            IteratorNode(T data)
            {
                this.data = data;
                this.next = null;
            }
        };

    public:
        AVLIterator(AVLNode root)
        {
            actual = load(root);
        }

        boolean hasNext()
        {
            return this.actual->next != nullptr;
        }

        T next()
        {
            this.actual = this.actual->next;
            return this.actual->data;
        }

    private:
        IteratorNode *actual;

        IteratorNode load(AVLNode node)
        {
            if (node == nullptr)
            {
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                auto itNode = new IteratorNode(node->data);
                itNode->next = load(node->right);
                return itNode;
            }
            else
            {
                auto itNode = load(node->left);
                itNode->next = new IteratorNode(node->data);
                itNode->next->next = load(node->right);
                return itNode;
            }
        }
    };

    struct AVLNode
    {
        AVLNode *left;
        AVLNode *right;
        AVLNode *parent;
        T data;
        int height;

        AVLNode(T data)
        {
            this->data = data;
            this->height = 1;
            this->left = nullptr;
            this->right = nullptr;
            this->parent = nullptr;
        }

        ~AVLNode()
        {
            if (this->left != nullptr)
                delete this->left;
            if (this->right != nullptr)
                delete this->right;
        }

        void updateHeight()
        {
            int leftH = this->left != nullptr ? this->left->height : 0;
            int rightH = this->right != nullptr ? this->right->height : 0;
            // int rightH = 0;
            // if (right != nullptr)
            // {
            //     rightH = right->height;
            // }
            this->height = 1 + std::max(leftH, rightH);
        }
    };

public:

    AVLIterator iterator()
    {
        return AVLIterator(root);
    }

    void add(T data)
    {
        //chequear si pertenece antes de sumar
        elements++;
        //TODO
        root = insert(root, data);
    }

    void remove(T data)
    {
        //chequear si pertenece antes de restar
        elements--;
        root = remove(root, data);
        //TODO
    }

    bool contains(T data)
    {
        auto node = root;
        while (node != nullptr)
        {
            if (data < node->data)
            {
                node = node->left;
            }
            else if (data > node->data)
            {
                node = node->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    T find(T data)
    {
        auto node = root;
        while (node != nullptr)
        {
            if (data < node->data)
            {
                node = node->left;
            }
            else if (data > node->data)
            {
                node = node->right;
            }
            else
            {
                return node->data;
            }
        }
        return nullptr;
    }

    int size()
    {
        return elements;
    }

    void clear()
    {
        elements = 0;
        delete root;
    }

private:
    AVLNode *root;
    int elements;

    AVLNode *insert(AVLNode *node, T data)
    {
        if (node == nullptr)
        {
            return new AVLNode(data);
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
            node->left->parent = node;
        }
        else
        {
            node->right = insert(node->right, data);
            node->right->parent = node;
        }
        node->updateHeight();
        return balance(node);
    }

    AVLNode *remove(AVLNode *node, T data)
    {
        if (node == nullptr)
            return nullptr;
        if (data < node->data)
        {
            node->left = remove(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = remove(node->right, data);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                if (node->parent != nullptr)
                {
                    if (data > node->parent->data)
                    {
                        node->parent->right = nullptr;
                    }
                    else
                    {
                        node->parent->left = nullptr;
                    }
                }
                delete node;
            }
            else if (node->left == nullptr)
            {
                auto temp = node->right;
                if (node->parent != nullptr)
                {
                    if (data > node->parent->data)
                    {
                        node->parent->right = temp;
                    }
                    else
                    {
                        node->parent->left = temp;
                    }
                }
                temp->parent = node->parent;
                node->right = nullptr;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                // TODO
            }
            else
            {
                node->data = findMax(node->left);
                //node->data = finMin(node->right);
                node->left = remove(node->left, node->data);
                //node->right = ;
            }
        }
        node->updateHeight();
        return balance(node);
    }

    T findMax(AVLNode *node)
    {
        // TODO
    }

    AVLNode *balance(AVLNode *Z)
    {
        int lHeight = Z->left != nullptr ? Z->left->height : 0;
        int rHeight = Z->right != nullptr ? Z->right->height : 0;

        if (std::abs(lHeight - rHeight) > 1)
        {
            if (lHeight > rHeight)
            {
                // Left - X
                auto Y = Z->left;
                int YlHeight = Y->left != nullptr ? Y->left->height : 0;
                int YrHeight = Y->right != nullptr ? Y->right->height : 0;
                if (YlHeight > YrHeight)
                {
                    //Left-Left
                    Z = RightRotation(Z);
                }
                else
                {
                    //Left-Right
                    Z = LeftRightRotation(Z);
                }
            }
            else
            {
                //Right - X
                auto Y = Z->right;
                int YlHeight = Y->left != nullptr ? Y->left->height : 0;
                int YrHeight = Y->right != nullptr ? Y->right->height : 0;
                if (YlHeight > YrHeight)
                {
                    //Right-Left
                    Z = RightLeftRotation(Z);
                }
                else
                {
                    //Right-Right
                    Z = LeftRotation(Z);
                }
            }
        }
        return Z;
    }

    AVLNode *RightRotation(AVLNode *Z)
    {
        //      p
        //      |
        //      Z
        //     /
        //    Y
        //   / \
        //  X   r
        AVLNode *Y = Z->left;

        //     p
        //     |
        //     Z <----Y /// Z is still parent of Y
        //    / \    /
        //   r      X
        Z->left = Y->right;
        if (Y->right != nullptr)
        {
            Y->right->parent = Z;
        }
        Z->updateHeight();

        //     p
        //     |
        //     Y
        //    / \
        //   X   Z
        //      /
        //     r
        Y->right = Z;
        Y->parent = Z->parent;
        Z->parent = Y;

        if (Y->parent != nullptr)
        {
            if (Y->data > Y->parent->data)
            {
                Y->parent->right = Y;
            }
            else
            {
                Y->parent->left = Y;
            }
            Y->parent->updateHeight();
        }
        return Y;
    }

    AVLNode *LeftRotation(AVLNode *Z)
    {
        //TODO
    }

    AVLNode *LeftRightRotation(AVLNode *Z)
    {
        Z->left = LeftRotation(Z->left);
        return RightRotation(Z);
    }

    AVLNode *RightLeftRotation(AVLNode *Z)
    {
        Z->right = RightRotation(Z->right);
        return LeftRotation(Z);
    }
};

template <class T>
class Set
{
public:
    int size()
    {
        //TODO
    }

    bool contains(T data)
    {
        //TODO
    }

    void clear()
    {
        //TODO
    }

    void add(T data)
    {
        //TODO
    }

    void remove(T data)
    {
        //TODO
    }

    Set<T> join(Set<T> *other)
    {
        // returns the union of this set and other set
        // TODO
    }

    Set<T> intersect(Set<T> *other)
    {
        // returns the insersection of this set and other set
        //TODO
    }

    Set<T> difference(Set<T> *other)
    {
        // returns the difference of this set and other set
        //TODO
    }
};

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

template <class K, class V>
class Map
{
public:
    Map()
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
    AVL<Pair<K, V>> *tree;
};

int main()
{
    Pair<int, char *> p1 = Pair<int, char *>(1, "hola");
    Pair<int, char *> p2 = Pair<int, char *>(2, "hola");
    Pair<int, char *> p3 = Pair<int, char *>(1, "chau");

    std::cout << (p1 < p2) << " | " << (p1 > p2) << " | " << (p1 == p3) << std::endl;
}