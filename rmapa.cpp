// https://olimpiada.ic.unicamp.br/pratique/p2/2011/f2/rmapa/
#include <iostream>
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
        KruskalMST(int vv, std::vector<Edge> arestas) {
            this->peso = 0.;
            
            std::priority_queue<Edge> pq;
            for (auto edge : arestas)
                pq.push(edge);
        
            
            // Kruskal
            UnionFind* unionFind = new UnionFind(vv);

            while (!pq.empty() && this->mst.size() < vv - 1) {
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
    int qtdCidades, qtdRodovias;
    std::cin >> qtdCidades >> qtdRodovias;
    
    std::vector<Edge> arestas;
    for (int i = 0; i < qtdRodovias; i++) {
        int u, v, peso;
        std::cin >> u >> v >> peso;
        u--; v--;
        arestas.push_back(Edge(u, v, peso));
    }

    std::cout << KruskalMST(qtdCidades, arestas).getPeso() << '\n';
    
}