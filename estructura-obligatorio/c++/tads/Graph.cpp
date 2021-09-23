#include <unordered_map> // SU TABLA

template <class T>
class Graph
{
public:
    Graph(int maxSize, Hasher<T> *hasher)
    {
        this->lastVertex = 0;
        // creamos las tablas pasandole el hasher
        // inicializamos la matriz de adyacencia
    }

    void addVertex(T vertex)
    {
        indexToVertex[lastVertex] = vertex; //agregamos el vertice a la tabla
        vertexToIndex[vertex] = lastVertex; //agregamos el vertice a la tabla
        lastVertex++;
    }

    void addEdge(T vertex, T otherVertex, int cost)
    {
        int v = this->vertexToIndex[vertex];      //buscamos el indice en la tabla
        int w = this->vertexToIndex[otherVertex]; //buscamos el indice en la tabla
        //agregamos la arista con costo {cost}
    }

    Iterator<T> *adjacents(T vertex)
    {
        int v = vertexToIndex[vertex];
        return new GraphIterator(matrix[v], indexToVertex);
    }

    void bfs(T origen)
    {
        bool *visitado = initVisitados(size);
        int *anterior = initAnterior(origen, size);
        int *costos = initCostos(origen, size);
        std::queue<T> cola;
        cola.push(origen);
        while (cola.size()) //mientras cola no sea vacia
        {
            T v = cola.pop();
            int vIndex = vertexToIndex[v];
            if (!visitado[vIndex])
            {
                visitado[vIndex] = true;
                auto it = this->adjacents(v);
                while (it.hasNext())
                {
                    T w = it.next();
                    int wIndex = vertexToIndex[w];
                    if (!visitado[wIndex] && costo[wIndex] > costo[vIndex] + 1)
                    {
                        costos[wIndex] = costos[vIndex] + 1;
                        anterior[wIndex] = vIndex;
                        cola.push(w);
                    }
                }
            }
        }
    }

    void dfs(T origen)
    {
        bool *visitado = initVisitados(size);

        dfsRec(origen, visitado);
    }

    void dfsRec(T origen, bool *visitado)
    {
        int v = vertexToIndex[origen];
        if (!visitado[v])
        {
            visitado[v] = true;
            auto it = this->adjacents(origen);
            while (it.hasNext())
            {
                T w = it.next();
                int wIndex = vertexToIndex[w];
                if (!visitado[wIndex])
                {
                    //cout<< v;
                    dfsRec(w, visitado);
                }
            }
        }
    }

    // void dfs(T origen, int size)
    // {
    //     bool *visitado = initVisitados(size);
    //     int *anterior = initAnterior(origen, size);
    //     int *costos = initCostos(origen, size);
    //     std::stack<T> pila;
    //     pila.push(origen);
    //     while (pila.size()) //mientras pila no sea vacia
    //     {
    //         T v = pila.pop();
    //         int vIndex = vertexToIndex[v];
    //         if (!visitado[vIndex])
    //         {
    //             visitado[vIndex] = true;
    //             auto it = this->adjacents(v);
    //             while(it.hasNext())
    //             {
    //                 T w = it.next();
    //                 int wIndex = vertexToIndex[w];
    //                 if(!visitado[wIndex] && costo[wIndex]> costo[vIndex]+1){
    //                     costo[wIndex] = costo[vIndex]+1;
    //                     anterior[wIndex] = vIndex;
    //                     pila.push(w);
    //                 }
    //             }
    //         }
    //     }
    // }

private:
    int **matrix;
    int lastVertex;
    int size;
    std::unordered_map<int, T> indexToVertex; //SU TABLA
    std::unordered_map<T, int> vertexToIndex; // SU TABLA

    class GraphIterator : public Iterator<T>
    {
    public:
        GraphIterator(int *arr, std::unordered_map indexToVertex, int size)
        {
            this->arr = arr;
            this->indexToVertex = indexToVertex;
            this->size = size;
            this->lastVisited = -1;
        }

        bool hasNext() override
        {
            int pos = lastVisited + 1;
            while (pos < size)
            {
                if (arr[pos] != 0)
                {
                    return true;
                }
                pos++;
            }
            return false;
        }

        T next() override
        {
            lastVisited++;
            while (lastVisited < size)
            {
                if (arr[lastVisited] != 0)
                {
                    return indexToVertex[lastVisited];
                }
                lastVisited++;
            }
            return NULL;
        }

    private:
        int *arr;
        std::unordered_map<int, T> indexToVertex; //SU TABLA
        int size;
        int lastVisited;
    }
};