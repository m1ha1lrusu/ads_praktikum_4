#include <assert.h>
#include "DijkstraSP.h"
#include <algorithm>
#include <cfloat>
#include <iomanip>
#include <iostream>

/**
 * Füge eine Kante mit minimalen Kosten hinzu, die von einem
 * Baumknoten zu einem Nicht-Baumknoten verläuft und deren
 * Ziel w dem Startknoten s am nächsten ist.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  v		Zielknoten
 */
void DijkstraSP::relax(EdgeWeightedDigraph G, int v) {
    std::vector<DirectedEdge> edges = G[v];
    for (DirectedEdge e: edges) {
        int w = e.to();
        if (distToVect[w] > distToVect[v] + e.weight()) {
            distToVect[w] = distToVect[v] + e.weight();
            edgeTo[w] = e;

            if (pq.contains(w)) {
                pq.change(w, distToVect[w]);
            } else {
                pq.push(w, distToVect[w]);
            }
        }
    }
}

/**
 * Fuert den Dijkstra Algorithmus von s, im Graph G aus.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  s		Startknoten
 */
DijkstraSP::DijkstraSP(EdgeWeightedDigraph G, int s) {
    distToVect.resize(G.getV());

    for (int v = 0; v < G.getV(); v++) {
        distToVect[v] = DBL_MAX;
    }
    distToVect[s] = 0.0; // Startknoten immer 0.0
    pq.push(s, 0.0);
    while (!pq.empty()) {
        int min_node = pq.top().value;
        pq.pop();
        // Füge immer eine Kante mit minimalen Pfadkosten zu s hinzu
        relax(G, min_node);
    }

    std::cout << std::setw(9) << "Knoten i" << " |";

    for (int i = 0; i < G.getV(); i++) // Gibt alle Knoten aus
    {
        std::cout << std::setw(3) << i;
    }

    std::cout << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << std::setw(9) << "edgeTo[i]" << " |";

    for (int i = 0; i < G.getV(); ++i) // Gibt jeweils den Vorgänger von i aus
    {
        if (edgeTo.count(i)) {
            std::cout << std::setw(3) << edgeTo[i].from();
        } else {
            std::cout << "  -";
        }
    }

    std::cout << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << std::setw(9) << "distTo[i]" << " |";

    for (int i = 0; i < G.getV(); ++i) {
        if (distToVect[i] == DBL_MAX) {
            std::cout << "inf";
        } else {
            std::cout << std::setw(3) << distToVect[i];
        }
    }

    std::cout << std::endl;
}

/**
 * Gibt die Distanz von s zum Knoten v zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Summe der Gewichte auf dem Pfad zu v
 */
double DijkstraSP::distTo(int v) const {
    return this->distToVect[v];
}

/**
 * Gibt zurueck ob es einen Pfad zu v von s aus gibt
 *
 * \param[in]  v		Zielknoten
 * \return true, wenn es einen Pfad von s nach v gibt, sonst false
 */
bool DijkstraSP::hasPathTo(int v) const {
    return this->distToVect[v] < DBL_MAX;;
}

/**
 * Gibt den Pfad von s nach v als Vektor zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Vektor mit allen Kanten des Pfades von s nach v
 */
std::vector<DirectedEdge> DijkstraSP::pathTo(int v) {
    assert(("Es gibt keinen Pfad von s nach v!", this->hasPathTo(v)));
    //assert(("Vertex is out of bounds!", false));

    std::vector<DirectedEdge> path;
    DirectedEdge e = edgeTo[v];
    while (true) {
        path.push_back(e);
        if (edgeTo.count(e.from()) > 0) {
            e = edgeTo[e.from()];
        } else {
            break;
        }
    }

    std::reverse(path.begin(), path.end());

    return path;
}
