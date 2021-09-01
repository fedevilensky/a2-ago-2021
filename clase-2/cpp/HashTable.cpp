#include <list>
#include <string>

template<class T>
class Hasher{
    public:
    virtual int hash(T key) =0;
};

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

        bool operator == (const Pair& other) override{
            return key == other.key;
        }
    }

    int Pair *table;
    int Hasher<K> *hasher;
};

template <class K, class V>
class OpenHashTable{
public:
    OpenHashTable(Hasher<K> *hasher, int size=113)
    {
        this->hasher = hasher;
        this->table = new std::list<Pair>[size];
    }

    ~OpenHashTable(){
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

        bool operator == (const Pair& other) override{
            return key == other.key;
        }
    };

    int std::list<Pair> *table;
    Hasher<K> *hasher;
};

class StringHasher : public Hasher<std::string>
{
    int hash(std::string str) override
    {
        return str[0];
    }
};