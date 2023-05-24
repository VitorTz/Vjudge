// https://olimpiada.ic.unicamp.br/pratique/p2/2008/f2/frete/
#include <iostream>
#include <string>
#include <vector>
#include <queue>


class Edge {
    
    private:
        int v, u;
        double peso;
    
    public:

        Edge(int v, int u, double peso) {
            this->v = v;
            this->u = u;
            this->peso = peso;
        }

        int getV() {
            return v;
        }

        int getU() {
            return u;
        }

        int outro(int ve) {
            if (ve == u) return v;
            return u;
        }

        double getPeso() const {
            return peso;
        }

        friend bool operator< (const Edge& l, const Edge& r) {
            return l.getPeso() > r.getPeso();
        }

        std::string toString() {
            return '{' + std::to_string(peso) + ", {" + std::to_string(v) + ", "  + std::to_string(u) + "}}";
        }            

};


class Graph {

    private:
        int V, E;
        std::vector<std::vector<Edge>> adjs;

    public:
        Graph(int v, int e) {
            this->V = v;
            this->E = e;
            this->adjs = std::vector<std::vector<Edge>> (this->V);
        }

        void addEdge(int v, int u, double peso) {
            this->addEdge(Edge(v, u, peso));
        }

        void addEdge(Edge e) {
            int u = e.getU();
            int v = e.getV();
            this->adjs[u].push_back(e);
            this->adjs[v].push_back(e);
        }

        std::vector<Edge>* adj(int u) {
            return &this->adjs[u];
        }

        std::vector<Edge> getEdges() {
            std::vector<Edge> ed;
            for (int u = 0; u < this->V; u++) {
                for (auto ee : this->adjs[u]) {
                    if (ee.outro(u) > u)
                        ed.push_back(ee);
                }
            }
            return ed;
        }

        int getV() {
            return this->V;
        }

        int getE() {
            return this->E;
        }

        std::string toString() {
            std::string r = "";
            std::vector<Edge> edges = this->getEdges();
            for (auto ee : edges)
                r += ee.toString() + '\n';
            return r;
        }

};


class UnionFind {

    private:
        std::vector<int> idComponente; // Id de cada componente
        int qtdComponents;  // Quantidade de componentes

    public:
        UnionFind(int vertices) {
            this->idComponente = std::vector<int> (vertices);
            this->qtdComponents = vertices;
            for (int i = 0; i < this->qtdComponents; i++)
                this->idComponente[i] = i;
        }

        int getQtdComponentes() {
            return this->qtdComponents;
        }

        bool estaoConectados(int p, int q) {
            return this->find(p) == this->find(q);
        }


        int find(int p) {
            if (this->idComponente[p] == p) 
                return p;
            this->idComponente[p] = this->find(this->idComponente[p]);
            return this->idComponente[p];
        }

        void unir(int p, int q) {
            int raiz_p = this->find(p);
            int raiz_q = this->find(q);
            if (raiz_p == raiz_q) return;
            this->idComponente[raiz_p] = raiz_q;
            this->qtdComponents--;
        }

};


class KruskalMST {

    private:
        std::vector<Edge> mst;
        double peso;  // Peso total da mst
    
    public:
        KruskalMST(Graph& g) {
            this->peso = 0.;
            
            std::priority_queue<Edge> pq;
            for (auto edge : g.getEdges())
                pq.push(edge);
        
            
            // Kruskal
            UnionFind* unionFind = new UnionFind(g.getV());

            while (!pq.empty() && this->mst.size() < g.getV() - 1) {
                Edge e = pq.top(); pq.pop();
                int u = e.getU();
                int v = e.getV();

                if (unionFind->estaoConectados(u, v)) continue;
                unionFind->unir(u, v);
                mst.push_back(e);
                this->peso += e.getPeso();
            }
        }

        std::vector<Edge> getEdges() {
            return this->mst;
        }

        double getPeso() {
            return this->peso;
        }

        std::string toString() {
            std::string r = "";
            for (auto e : this->mst)
                r += e.toString() + '\n';            
            return r;
        }      

};


int main() {
    int qtdColonias, qtdEstradas;
    std::cin >> qtdColonias >> qtdEstradas;
    
    Graph g(qtdColonias, qtdEstradas);

    for (int i = 0; i < qtdEstradas; i++) {
        int estradaP, estradaQ, custoViagem;
        std::cin >> estradaP >> estradaQ >> custoViagem;
        g.addEdge(estradaP, estradaQ, custoViagem);
    }

    KruskalMST kruskal(g);

    std::cout << kruskal.getPeso() << '\n';
    return 0;
}