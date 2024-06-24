#pragma once
#include "EdgeWeightedDigraph.h"
#include "EdgeWeightedGraph.h"
#include <iostream>

namespace Graphsearch {
    /**
        * Fuehrt eine rekursive Tiefensuche im Graphen G,
        * ab dem Knoten v aus und markiert alle besuchten
        * Knoten in marked.
        * Alle besuchten Knoten werden ausgegeben.
        *
        * \param[in]	 G			Graph
        * \param[in]	 v			Startknoten
        * \param[in/out] marked		Bereits besuchte Knoten
        * \param[in/out] edgeTo		Vektor mit dem Nachfolgeknoten zu jedem Knoten
        */
    void DFS_recursive(const EdgeWeightedGraph &G, int v, std::vector<bool> &marked, std::vector<int> &edgeTo) {
        marked[v] = true;
        std::cout << v << " -> ";
        for (auto e: G[v]) {
            ///
            int w = e.other(v);
            if (!marked[w]) {
                edgeTo[w] = v;
                DFS_recursive(G, w, marked, edgeTo);
            }
        }
    }

    /**
        * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus.
        * Alle besuchten Knoten werden ausgegeben.
        * Starterfunktion zu DFS_recursive(EdgeWeigtedGraph, int, std::vector<bool>, std::vector<int>)
        *
        * \param[in]  G			Graph
        * \param[out] marked	Bereits besuchte Knoten
        * \param[out] edgeTo	Vektor mit dem Nachfolgeknoten zu jedem Knoten
        * \param[in]  v			Startknoten
        * \return	  true		Graph ist zusammenhaengend
        *			  false		Graph ist nicht zusammenhaengend
        */

    bool DFS(const EdgeWeightedGraph &G, int v, std::vector<bool> &marked, std::vector<int> &edgeTo) {
        std::vector<bool> marked(G.getV(), false);
        std::vector<int> edgeTo(G.getV(), -1);
        DFS_recursive(G, v, marked, edgeTo);
        for (bool m: marked) {
            if (!m) return false;
        }
        return true;
    }

    /**
        * Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus.
        * Alle besuchten Knoten werden ausgegeben.
        *
        * \param[in]  G			Graph
        * \param[in]  v			Startknoten
        * \param[out] marked	Gibt an welche Knoten besucht wurden bei der Suche
        * \param[out] edgeTo	Gibt den Nachfolgerknoten eines Knoten an
        * \return	  true		Graph ist zusammenhaengend
        *			  false		Graph ist nicht zusammenhaengend
        */
    bool Graphsearch::BFS(const EdgeWeightedGraph &G, int v, std::vector<bool> &marked, std::vector<int> &edgeTo) {
        std::vector<bool> marked(G.getV(), false);
        std::vector<int> edgeTo(G.getV(), -1);

        std::queue<int> q;
        q.push(v);
        marked[v] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            //if (marked[v]) continue;
            //marked[v] = true;

            std::cout << "Besuchter Knoten: " << v << std::endl;

            for (auto w: G[v]) {
                if (!marked[w]) {
                    edgeTo[w] = v;
                    marked[w] = true;
                    q.push(w);
                }
            }
        }

        // Ausgabe von edgeTo-Array
        std::cout << std::endl << "Knoten marked edgeTo:" << std::endl;
        for (int i = 0; i < edgeTo.size(); i++) {
            std::cout << i << ": " << marked[i] << " " << edgeTo[i] << std::endl;
        }

        // Überprüfen, ob alle Knoten markiert wurden
        for (bool m: marked) {
            if (!m) return false;
        }
        return true;
    }
}

