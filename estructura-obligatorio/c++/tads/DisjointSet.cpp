class DisjointSet
{
public:
  DisjointSet(int n)
  {
    this->sets = new Node[n];
    this->size = n;
    for (int i = 0; i < n; i++)
    {
      this->sets[i].parent = i;
      this->sets[i].rank = 0;
    }
  }

  ~DisjointSet()
  {
    delete[] this->sets;
  }

  int find(int x)
  {
    if (this->sets[x].parent != x)
    {
      return this->find(this->sets[x].parent);
    }
    return x;
  }

  void merge(int x, int y)
  {
    int xRoot = this->find(x);
    int yRoot = this->find(y);
    if (xRoot == yRoot)
    {
      return;
    }
    if (this->sets[xRoot].rank < this->sets[yRoot].rank)
    {
      this->sets[xRoot].parent = yRoot;
    }
    else if (this->sets[xRoot].rank > this->sets[yRoot].rank)
    {
      this->sets[yRoot].parent = xRoot;
    }
    else
    {
      this->sets[yRoot].parent = xRoot;
      this->sets[xRoot].rank++;
    }
  }

private:
  struct Node
  {
    int parent;
    int rank;
  };

  Node *sets;
  int size;
};
