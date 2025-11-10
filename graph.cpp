#include <iostream>

// *--Edge--*
class Edge {
private:
    char vertex1;
    char vertex2;

public: 

    Edge(): vertex1('\0'), vertex2('\0') {}
    Edge(char v1, char v2): vertex1(v1), vertex2(v2) {}

    //  *--Getter Functions--*
    char getVertex1() const {
        return vertex1;
    }
    char getVertex2()const {
        return vertex2;
    } 

    // *--Utility Functions--*
    void swap(){
        char temp = vertex1;
        vertex1 = vertex2;
        vertex2 = temp; 
    }

    // *--Friend Functions--*
    friend std::ostream& operator<<(std::ostream& os, const Edge& edge);

};

std::ostream& operator<< (std::ostream& os, const Edge& edge) {
    os << edge.vertex1 << edge.vertex2;
    return os;
}


// *--Graph--*
class Graph {
private: 
    size_t vN;
    size_t eN;
    char* vSet;
    Edge* eSet;

public: 

    Graph(): vN(0), eN(0) {
        vSet = nullptr;
        eSet = nullptr;
    }
    
    Graph(size_t vN, size_t eN, char*vSet, Edge* eSet): vN(vN), eN(eN) {
        this->vSet = new char[vN];
        
        for(size_t i = 0; i < vN; ++i){
            this->vSet[i] = vSet[i];
        }

        this->eSet = new Edge[eN];

        for(size_t i = 0; i < eN; ++i){
            this->eSet[i] = eSet[i];            
        }
    }

    //I want a complete graph constructor


    ~Graph(){
        delete[] vSet;
        delete[] eSet;
    }
};

int main(){
    Edge sample ('a','b');
    std::cout << sample << std::endl;
    return 0;
}