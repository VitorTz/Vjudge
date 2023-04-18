#include <iostream>
#include <vector>
#include <list>
// https://olimpiada.ic.unicamp.br/pratique/p2/2013/f2/troia

class Graph {

    private:
        int v;
        int e;
        std::vector<std::vector<int>> adjs;
    
    public:
        Graph(int v) {
            this->v = v;
            this->e = 0;
            this->adjs = std::vector<std::vector<int>> (this->v);
        }

        void addEdge(std::pair<int, int> p) {
            this->adjs[p.first].push_back(p.second);
            this->adjs[p.second].push_back(p.first);
            this->e += 1;
        }

        std::vector<int>* adj(int u) {
            return &this->adjs[u];
        }

        int getV() { return this->v; }
        int getE() { return this->e; }

};


class CC {

    private:
        Graph* g;
        std::vector<bool> mk;
        std::vector<int> id;
        int cont;

        void dfs(int u) {
            std::list<int> stack;
            stack.push_back(u);
            this->mk[u] = true;
            this->id[u] = this->cont;

            while (!stack.empty()) {
                int v = stack.back(); stack.pop_back();
                for (int& vv : *this->g->adj(v)) {
                    if (!this->mk[vv]) {
                        this->mk[vv] = true;
                        this->id[vv] = this->cont;
                        stack.push_back(vv);
                    }
                }
            }
        }

        void setUp() {
            for (int u = 0; u < this->g->getV(); u++) {
                if (!this->mk[u]) {
                    this->dfs(u);
                    this->cont += 1;
                }
            }
        }

    public:
        CC(Graph* g) {
            this->g = g;
            this->cont = 0;
            this->mk = std::vector<bool> (this->g->getV(), false);
            this->id = std::vector<int> (this->g->getV());
            this->setUp();
        }

        bool conectados(int u, int v) { return this->id[u] == this->id[v]; }
        int contagem() { return this->cont; }
        int getId(int u) { return this->id[u]; } 

};



int main() {
    int n, linhas;
    std::cin >> n >> linhas;
    Graph* g = new Graph(n);

    for (int i = 0; i < linhas; i++) {
        int u, v;
        std::cin >> u >> v;
        g->addEdge({u-1, v-1});
    }

    std::cout << CC(g).contagem() << std::endl;

    delete g;
    return 0;
}