package tads;

public class ClosedHashTable<K, V> {
    private Object[] table;
    private Hasher<K> hasher;

    ClosedHashTable(Hasher<K> hasher){
        this.hasher = hasher;
        this.table = new Object[123];
    }

    ClosedHashTable(Hasher<K> hasher, int size){
        this.hasher = hasher;
        this.table = new Object[size];
    }

    // pre: -
    // post: queda asociado la llave y el valor en la tabla
    public void set(K key, V value) {
        int hash = hasher.hash(key);
        //...
        int pos = 0;
        // ...
        var pair = (Pair<K,V>) table[pos];
        // ...
        // TODO
    }

    // pre: key existe en la tabla
    // post: devuelve el valor asociado a key en la tabla
    public V get(K key) {
        int hash = hasher.hash(key);
        //...
        int pos = 0;
        // ...
        var pair = (Pair<K,V>) table[pos];
        // ...
        // TODO
        return null;
    }

    // pre: -
    // post: devuelve true sii key esta en la tabla
    public boolean has(K key) {
        int hash = hasher.hash(key);
        //...
        int pos = 0;
        // ...
        var pair = (Pair<K,V>) table[pos];
        // ...
        // TODO
        return false;
    }

    // pre: -
    // post: key no esta en la tabla
    public void remove(K key) {
        int hash = hasher.hash(key);
        //...
        int pos = 0;
        // ...
        var pair = (Pair<K,V>) table[pos];
        // ...
        // TODO
    }

    // pre: -
    // post: la tabla esta vacia
    public void clear() {
        int pos = 0;
        // ...
        var pair = (Pair<K,V>) table[pos];
        // ...
        // TODO
    }

    public class Pair<K, V> {
        K key;
        V value;

        Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }
}