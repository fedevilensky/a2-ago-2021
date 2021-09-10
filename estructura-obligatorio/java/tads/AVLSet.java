package tads;

public class AVLSet<T extends Comparable<T>>{
    private AVL<T> tree;
    public int size(){
      //TODO
      return 0;
    }

    public boolean contains(T data){
      // returns true if data is in the set
      //TODO
      return false;
    }

    public void clear(){
      //TODO
    }

    public void add(T data){
      // add data to the set
      //TODO
    }

    public void remove(T data){
      // remove data from the set
      //TODO
    }

    public void join(AVLSet<T> other){
      // var it = other.tree.iterator();
      // while(it.hasNext()){
      //   T data = it.next();
      //   this.add(data);
      // }
      for (T data : other.tree) {
        this.add(data);
      }
    }

    public AVLSet<T> intersect(AVLSet<T> other){
      // returns the intersection of this set and other set
      //TODO
      return null;
    }

    public AVLSet<T> difference(AVLSet<T> other){
      // returns the difference of this set and other set
      //TODO
      return null;
    }
  }