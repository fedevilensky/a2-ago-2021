package tads;

import java.util.Iterator;

public class AVL<T extends Comparable<T>> implements Iterable<T> {
    public class AVLIterator implements Iterator<T> {

      public class IteratorNode{
        public T data;
        public IteratorNode next;

        public IteratorNode(){
          this.next = null;
        }

        public IteratorNode(T data){
          this.data = data;
          this.next = null;
        }
      }

      private IteratorNode actual;

      public AVLIterator(AVLNode root){
        actual = new IteratorNode();
        actual.next = load(root);
      }


      @Override
      public boolean hasNext() {
        return this.actual != null;
      }

      @Override
      public T next() {
        T data = this.actual.data;
        this.actual = this.actual.next;
        return data;
      }

      private IteratorNode load(AVLNode node){
        if(node == null){
          return null;
        }
        else if(node.left == null){
          var itNode = new IteratorNode(node.data);
          itNode.next = load(node.right);
          return itNode;
        }
        else{
          var itNode = load(node.left);
          var aux = itNode;
          while(aux.next != null)
            aux = aux.next;
          aux.next = new IteratorNode(node.data);
          aux.next.next = load(node.right);
          return itNode;
        }
      }
    }    

    public class AVLNode {
      public T data;
      public AVLNode left;
      public AVLNode right;
      public AVLNode parent;
      public int height;

      public AVLNode(T data) {
        this.data = data;
        this.height = 1;
        this.left = null;
        this.right = null;
        this.parent = null;
      }

      public void updateHeight() {
        int leftHeight = left != null ? left.height : 0;
        int rightHeight = right != null ? right.height : 0;
        this.height = 1 + Math.max(leftHeight, rightHeight);
      }
    }

    private AVLNode root;
    private int elements;

    public T getMax(){
      if(root == null)
        return null;
      AVLNode node = this.root;
      while(node.right != null){
        node = node.right;
      }
      return node.data;
    }

    public T getMin(){
      if(root == null)
        return null;
      AVLNode node = this.root;
      while(node.left != null){
        node = node.left;
      }
      return node.data;
    }


    public void add(T data) {
      elements++;
      root = insert(root, data);
    }

    public void remove(T data) {
      elements--;
      root = remove(root, data);
    }

    public boolean contains(T data) {
      AVLNode node = root;
      while (node != null) {
        if (data.compareTo(node.data) == 0) {
          return true;
        } else if (data.compareTo(node.data) < 0) {
          node = node.left;
        } else {
          node = node.right;
        }
      }
      return false;
    }

    public T find(T data) {
      AVLNode node = root;
      while (node != null) {
        if (data.compareTo(node.data) == 0) {
          return node.data;
        } else if (data.compareTo(node.data) < 0) {
          node = node.left;
        } else {
          node = node.right;
        }
      }
      return null;
    }

    public int size() {
      return elements;
    }

    public void clear() {
      root = null;
      elements = 0;
    }

    private AVLNode insert(AVLNode node, T data) {
      if (node == null) {
        return new AVLNode(data);
      } else if (data.compareTo(node.data) < 0) {
        node.left = insert(node.left, data);
        node.left.parent = node;
      } else {
        node.right = insert(node.right, data);
        node.right.parent = node;
      }
      node.updateHeight();
      return balance(node);
    }

    private AVLNode remove(AVLNode node, T data) {
      // data not found
      if (node == null)
        return node;

      // go right if data is bigger
      if (data.compareTo(node.data) > 0) {
        node.right = remove(node.right, data);
      }
      // go left if data is smaller
      else if (data.compareTo(node.data) < 0)
        node.left = remove(node.left, data);

      // if data is same as node.data, then we need to remove this node
      else {
        // node with only one child or no child
        if (node.left == null && node.right == null)
          return null;
        else if (node.left == null){
          node.right.parent = node.parent;
          return node.right;
        }
        else if (node.right == null){
          node.left.parent = node.parent;
          return node.left;
        }
        

        // we need to find either biggest to the left or smallest to the right
        node.data = findMax(node.left);

        // delete the new node data to the left
        node.left = remove(node.left, node.data);
      }

      // after removing, we update height and rebalance the tree
      node.updateHeight();
      return balance(node);
    }

    private T findMax(AVLNode node) {
      // TODO
      return null;
    }

    private AVLNode balance(AVLNode Z) {
      var lHeight = Z.left!= null ? Z.left.height : 0;
      var rHeight = Z.right!= null ? Z.right.height : 0;
      
      // Z is unbalanced
      if (Math.abs(lHeight - rHeight) > 1) {

        // Y is to the right of Z
        if (rHeight > lHeight) {
          var Y = Z.right;
          var YRHeight = Y.right != null ? Y.right.height : 0;
          var YLHeight = Y.left != null ? Y.left.height : 0;
          // X is to the right of Y
          if (YRHeight > YLHeight) {
            // Right Right Case
            // we rotate left
            Z = LRotation(root);
          }
          // X is to the left of Y
          else {
            // Right Left case
            // we rotate right-left
            Z = RLRotation(root);
          }
        }
        // Y is to the left of Z
        else {
          var Y = Z.left;
          var YRHeight = Y.right != null ? Y.right.height : 0;
          var YLHeight = Y.left != null ? Y.left.height : 0;
          // X is to the right of Y
          if (YRHeight > YLHeight) {
            // Left Right Case
            // we rotate left-right
            Z = LRRotation(Z);
          }
          // X is to the left of Y
          else {
            // Left Left case
            // we rotate right
            Z = RRotation(Z);
          }
        }
      }
      return Z;
    }

    private AVLNode LRotation(AVLNode Z) {
      //      p
      //      |
      //      Z
      //       \
      //        Y
      //       / \
      //      l   X
      var Y = Z.right;

      //     p
      //     |
      //     Z <----Y /// Z is still parent of Y
      //      \      \
      //       t      X
      Z.right = Y.left;
      if (Y.left != null) {
        Y.left.parent = Z;
      }


      //     p
      //     |
      //     Y
      //    / \
      //   Z   X
      //    \
      //     t
      Y.left = Z;
      Y.parent = Z.parent;
      Z.parent = Y;

      // the only thing that's left is to add Y as p's child
      if(Y.parent != null){
        if(Y.data.compareTo(Y.parent.data) < 0){
          Y.parent.left = Y;
        } else {
          Y.parent.right = Y;
        }
      }
      return Y;
    }

    private AVLNode RRotation(AVLNode Z){
      // TODO
      return null;
    }

    private AVLNode LRRotation(AVLNode Z){
      // TODO
      return null;
    }

    private AVLNode RLRotation(AVLNode Z){
      // TODO
      return null;
    }

    @Override
    public Iterator<T> iterator() {
      return new AVLIterator(root);
    }
    
  }