import java.util.Scanner;

import tads.AVL;

public class ejemplo1 {
    public static void main(String[] args) {
        AVL<Integer> avl = new AVL<Integer>();
        // avl.add(10);

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for(int i = 0; i < N; i++){
            int val = sc.nextInt();
            System.out.println(val * 2);
        }
        sc.close();
    }
}

