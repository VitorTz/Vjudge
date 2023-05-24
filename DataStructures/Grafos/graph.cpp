#include <iostream>
#include <vector>


class Aresta {

    private:
        float peso;
        int u, v;

    public:
        Aresta(float peso, int u, int v) {
            this->peso = peso;
            this->u = u;
            this->v = v;
        }

        float getPeso() {
            return this->peso;
        }

        int getU() {
            return this->u;
        }

        int getV() {
            return this->v;
        }

        Aresta invert() {
            return Aresta(this->peso, this->v, this->u);
        }

        

        bool operator< (Aresta& a) {
            this->peso < a.getPeso();
        }

        bool operator== (Aresta a) {
            return this->peso == a.getPeso();
        }

        bool operator> (Aresta a) {
            return this->peso > a.getPeso();
        }

};


class Graph {

    private:
        int vertices;
        std::vector<std::vector<Aresta>> e;
    public:
        Graph(int v) {
            this->vertices = v;
            this->e = std::vector<std::vector<Aresta>> (this->vertices);
        }

        void addAresta(Aresta& a) {
            this->e[a.getU()].push_back(a);
            this->e[a.getV()].push_back(a.invert());
        }

        std::vector<Aresta>& getEdge(int e) {
            return this->e[e];
        }

        std::vector<Aresta&> getArestas() {

        }

};