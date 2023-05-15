#include <iostream>
#include <vector>
#include <list>


class DiGraph {

    private:
        int V, E;
    public:
        std::vector<std::vector<int>> adjs;
        DiGraph(int v) {
            this->V = v;
            this->E = 0;
            this->adjs = std::vector<std::vector<int>> (this->V);
        }

        void addEdge(int u, int v) {
            this->adjs[u].push_back(v);
            this->E++;
        }

        std::vector<int>* adj(int u) {
            return &this->adjs[u];
        }

        int getV() { return this->V; }
        int getE() { return this->E; }

        DiGraph* reverso() {
            DiGraph* d = new DiGraph(this->V);
            for (int i = 0; i < this->V; i++) {
                for (int v : this->adjs[i]) {
                    d->addEdge(v, i);
                }
            }
            return d;
        }

        std::vector<int> alcance(int s) {
            std::vector<int> range;
            std::list<int> queue;
            std::vector<bool> mk = std::vector<bool> (this->V, false);
            queue.push_back(s);
            mk[s] = true;

            while (!queue.empty()) {
                int u = queue.front(); queue.pop_front();
                for (int v : this->adjs[u]) {
                    if (!mk[v]) {
                        queue.push_back(v);
                        range.push_back(v);
                        mk[v] = true;
                    }
                }
            }
            return range;
        }

        void print(DiGraph* d) {
            for (int u = 0; u < d->getV(); u++) {
                for (int v : *d->adj(u)) {
                    std::cout << u << " -> " << v << '\n';
                }
            }
        }

};

void printVector(std::vector<int>& vec) {
    if (vec.size() >= 1) {
        std::cout << "(" << vec[0];
        for (int i = 1; i < vec.size()-1; i++) {
            std::cout << ", " << vec[i];
        }
        std::cout << ", " << vec[vec.size()-1] << ")\n";
    }
}

int main() {
    int V, E;
    std::cin >> V >> E;
    DiGraph g = DiGraph(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        std::cin >> u >> v;
        g.addEdge(u, v);
    }

    std::vector<int> a = g.alcance(1);
    std::vector<int> b = g.alcance(2);
    std::vector<int> c = g.alcance(6);
    g.print(&g);
    printVector(a);
    printVector(b);
    printVector(c);

}