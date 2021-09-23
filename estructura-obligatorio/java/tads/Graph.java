package tads;

import java.util.HashMap; //SU TABLA
import java.util.Iterator;
import java.util.Queue;

class Graph<T> {
    private HashMap<T, Integer> vertexToIndex;
    private HashMap<Integer, T> indexToVertex;
    private int[][] matrix;
    private int lastVertex;

    public Graph(int maxSize, Hasher<T> hasher) {
        this.vertexToIndex = new HashMap<T, Integer>();
        this.indexToVertex = new HashMap<Integer, T>();
        this.matrix = new int[maxSize][maxSize];
        this.lastVertex = 0;
    }

    public void addVertex(T vertex) {
        indexToVertex.put(lastVertex, vertex);
        vertexToIndex.put(vertex, lastVertex);
        lastVertex++;
    }

    public void addEdge(T source, T destination, int cost) {
        int v = vertexToIndex.get(source); // buscamos el indice en la tabla
        int w = vertexToIndex.get(destination); // buscamos el indice en la tabla
        // agregamos la arista con costo {cost}
    }

    public Iterator<T> adjacents(T vertex) {
        int v = vertexToIndex.get(vertex);
        return new GraphIterator(matrix[v], indexToVertex);
    }

    public void bfs(T origen) {
        boolean[] visitado = initVisitados(matrix.length);
        int[] anterior = initAnterior(origen, matrix.length);
        int[] costos = initCostos(origen, matrix.length);
        Queue<T> cola;// SU COLA
        cola.add(origen);
        while (!cola.isEmpty()) // mientras cola no sea vacia
        {
            T v = cola.remove();
            int vIndex = vertexToIndex.get(v);
            if (!visitado[vIndex]) {
                visitado[vIndex] = true;
                var it = adjacents(v);
                while (it.hasNext()) {
                    T w = it.next();
                    int wIndex = vertexToIndex.get(w);
                    if (!visitado[wIndex] && costos[wIndex] > costos[vIndex] + 1) {
                        costos[wIndex] = costos[vIndex] + 1;
                        anterior[wIndex] = vIndex;
                        cola.add(w);
                    }
                }
            }
        }
    }

    public void dfs(T origen) {
        boolean[] visitado = initVisitados(matrix.length);

        dfsRec(origen, visitado);
    }

    private void dfsRec(T origen, boolean[] visitado) {
        int v = vertexToIndex.get(origen);
        if (!visitado[v]) {
            visitado[v] = true;
            var it = adjacents(origen);
            while (it.hasNext()) {
                T w = it.next();
                int wIndex = vertexToIndex.get(w);
                if (!visitado[wIndex]) {
                    // cout<< v;
                    dfsRec(w, visitado);
                }
            }
        }
    }

    class GraphIterator implements Iterator<T> {
        private int[] arr;
        private HashMap<Integer, T> indexToVertex; // SU TABLA
        private int lastVisited;

        public GraphIterator(int[] arr, HashMap<Integer, T> indexToVertex) {
            this.arr = arr;
            this.indexToVertex = indexToVertex;
            this.lastVisited = -1;
        }

        public boolean hasNext() {
            int pos = lastVisited + 1;
            while (pos < arr.length) {
                if (arr[pos] != 0) {
                    return true;
                }
                pos++;
            }
            return false;
        }

        public T next() {
            lastVisited++;
            while (lastVisited < arr.length) {
                if (arr[lastVisited] != 0) {
                    return indexToVertex.get(lastVisited);
                }
                lastVisited++;
            }
            return null;
        }
    }
}