package tads;

public class AVLMap<K extends Comparable<K>, V>{

    private class Pair implements Comparable<Pair>{
      public K key;
      public V value;
      public Pair(K key, V value){
        this.key = key;
        this.value = value;
      }

      @Override
      public int compareTo(Pair o) {
        return key.compareTo(o.key);
      }

    }

    public int size(){
      // returns how many elements are in the map
      //TODO
      return 0;
    }

    public V get(K key){
      // get the value asoociated with the key
      //TODO
      return null;
    }

    public void set(K key, V value){
      // add a key to the table, if it already exists, remove it and add it again
      //TODO
    }

    public void remove(K key){
      //TODO
    }

    public boolean exists(K key){
      //TODO
      return false;
    }

    public void clear(){
      //TODO
    }

  }
  

