#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include "Graphsearch.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"

int main() {
    // Starte Unit-Tests
    Catch::Session().run();

    //------------------------------------------------------------------------
    // 1. Ausgabe eines Graphen als Adjazenzliste implementieren
    //------------------------------------------------------------------------


    //------------------------------------------------------------------------
    // 2. Suche in Graphen
    //------------------------------------------------------------------------
    // Verwenden Sie hierf�r die Vorlagen in Graphsearch.h
    //
    // Beispielaufruf der Tiefensuche:
    // std::vector<bool> marked;
    // std::vector<int>  edgeTo;
    // bool connected = Graphsearch::DFS(G1, start, marked, edgeTo);


    //------------------------------------------------------------------------
    // 3. Minimaler Spannbaum mit Prim und Kruskal
    //------------------------------------------------------------------------
    // Vorlage f�r Prim ist die Klasse PrimMST (PrimMST.h + PrimMST.cpp)
    // Vorlage f�r Kruskal ist die Klasse KruskalMST (KruskalMST.h + KruskalMST.cpp)
    //
    // Beispielaufruf von Prim:
    // PrimMST prim(G, 0);


    //------------------------------------------------------------------------
    // 4. Kuerzeste Wege mit Dijkstra
    //------------------------------------------------------------------------
    // Beispielaufruf von Dijkstra
    //
    // EdgeWeightedDigraph G1_directed("graph1.txt");
    // Dijkstra dijkstra(G1_directed, start);
    // path = dijkstra.pathTo(target);


    //------------------------------------------------------------------------
    // 5. Men� f�r Benutzereingaben
    //------------------------------------------------------------------------
    // Alle Funktionalit�ten aus der Aufgabenstellung muessen umgesetzt werden

    int eingabe = 0;
    EdgeWeightedDigraph dGraph("graph1.txt");
    EdgeWeightedGraph Graph("graph1.txt");

    while (eingabe != 10) {
        std::cout << "Praktikum 5: Graphenalgorithem:" << std::endl;
        std::cout << "1) Graph aussuchen" << std::endl;
        std::cout << "2) Tiefensuche" << std::endl;
        std::cout << "3) Breitensuche" << std::endl;
        std::cout << "4) MST nach Prim (Eingabe: Startknoten)" << std::endl;
        std::cout << "5) MST nach Kruskal" << std::endl;
        std::cout << "6) Kürzeste Wege nach Dijkstra (Eingabe: Startknoten)" << std::endl;
        std::cout << "7) Ausgabe der Adjazenzliste" << std::endl;
        std::cout << "8) Kante löschen" << std::endl;
        std::cout << "9) Kante hinzufügen" << std::endl;
        std::cout << "10)Programm beenden" << std::endl;
        std::cout << "Weiter mit beliebiger Eingabe ..." << std::endl;
        std::cout << "?> ";

        std::cin >> eingabe;
        std::cin.ignore();
        std::cout << std::endl;

        switch (eingabe) {
            // Graph wählen
            case 1: {
                int einlesen;
                std::cout << "Bitte wählen einen der Graphen 1 - 3 aus: " << std::endl;
                std::cout << "?> ";
                std::cin >> einlesen;
                std::cin.ignore();

                switch (einlesen) {
                    case 1: {
                        dGraph = EdgeWeightedDigraph("graph1.txt");
                        Graph = EdgeWeightedGraph("graph1.txt");
                        break;
                    }
                    case 2: {
                        dGraph = EdgeWeightedDigraph("graph2.txt");
                        Graph = EdgeWeightedGraph("graph2.txt");
                        break;
                    }
                    case 3: {
                        dGraph = EdgeWeightedDigraph("graph2.txt");
                        Graph = EdgeWeightedGraph("graph2.txt");
                        break;
                    }
                    default: {
                        std::cout << "Ungültige Eingabe" << std::endl;
                        break;
                    }
                }
                break;
            }

            // Tiefensuche
            case 2: {
                int start = 0;
                std::cout << "Tiefensuche (Depth-First-Search (DFS)) - Startknoten: 0" << std::endl;
                std::vector<bool> marked;
                std::vector<int> edgeTo;
                std::cout << "Besuchsreihenfolge:" << std::endl
                        << start;
                bool connected = Graphsearch::DFS(Graph, start, marked, edgeTo);
                std::cout << std::endl
                        << std::endl;
                std::cout << "EdgeTo_Array:" << std::endl;
                for (int i = 0; i < edgeTo.size(); i++) {
                    std::cout << i << " -> " << edgeTo[i];
                    if (i == start) {
                        std::cout << " (Startknoten)";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                std::cout << "Marked-Array:" << std::endl;
                for (int i = 0; i < marked.size(); i++) {
                    std::cout << i << " -> ";
                    if (marked[i]) {
                        std::cout << "true";
                    } else {
                        std::cout << "false";
                    }
                    if (i == start) {
                        std::cout << " (Startknoten)";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                std::cout << "Graph ist ";
                if (!connected) {
                    std::cout << "nicht ";
                }
                std::cout << "zusammenhängend" << std::endl;
                break;
            }

            // Breitensuche
            case 3: {
                int start = 0;
                std::cout << "Breitensuche (Breadth-First-Search (BFS)) - Startknoten: 0" << std::endl;
                std::vector<bool> marked;
                std::vector<int> edgeTo;
                std::cout << "Besuchsreihenfolge:" << std::endl << start;
                bool connected = Graphsearch::BFS(Graph, start, marked, edgeTo);
                std::cout << std::endl
                        << std::endl;
                std::cout << "EdgeTo_Array:" << std::endl;
                for (int i = 0; i < edgeTo.size(); i++) {
                    std::cout << i << " -> " << edgeTo[i];
                    if (i == start) {
                        std::cout << " (Startknoten)";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                std::cout << "Marked-Array:" << std::endl;
                for (int i = 0; i < marked.size(); i++) {
                    std::cout << i << " -> ";
                    if (marked[i]) {
                        std::cout << "true";
                    } else {
                        std::cout << "false";
                    }
                    if (i == start) {
                        std::cout << " (Startknoten)";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                std::cout << "Graph ist ";
                if (!connected) {
                    std::cout << "nicht ";
                }
                std::cout << "zusammenhängend" << std::endl;
                break;
            }

            // Prim
            case 4: {
                int start = 0;
                std::cout << "Startknoten: ? ";
                std::cin >> start;
                std::cin.ignore();
                std::cout << std::endl;
                std::cout << "Minimaler Spannbaum (MST) nach Prim: " << std::endl;
                PrimMST prim(Graph, start);
                std::cout << "Gewicht: " << prim.weight() << std::endl;
                std::cout << "Adjazenzliste: " << std::endl;
                struct node {
                    int w;
                    int weight;
                };

                std::vector<std::vector<node> > ergebnis;
                ergebnis.resize(Graph.getV());

                for (Edge edge: prim.edges()) {
                    int v = edge.either();
                    int w = edge.other(v);

                    node p;
                    p.w = w;
                    p.weight = edge.weight();
                    ergebnis[v].push_back(p);
                }

                for (int i = 0; i < ergebnis.size(); i++) {
                    if (ergebnis[i].empty()) {
                        continue;
                    }

                    std::cout << i;
                    for (int j = 0; j < ergebnis[i].size(); j++) {
                        std::cout << " -> " << ergebnis[i][j].w << " [" << ergebnis[i][j].weight << "]";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                break;
            }

            // Kruskal
            case 5: {
                std::cout << "Minimaler Spannbaum (MST) nach Kruskal: " << std::endl;
                KruskalMST kruskal(Graph);

                std::cout << "Gewicht: " << kruskal.weight() << std::endl;
                std::cout << "Adjazenzliste:" << std::endl;

                struct node {
                    int w;
                    int weight;
                };

                std::vector<std::vector<node> > ergebnis;
                ergebnis.resize(Graph.getV());

                for (Edge edge: kruskal.edges()) {
                    int v = edge.either();
                    int w = edge.other(v);

                    node p;
                    p.w = w;
                    p.weight = edge.weight();
                    ergebnis[v].push_back(p);
                }
                for (int i = 0; i < ergebnis.size(); i++) {
                    if (ergebnis[i].empty()) {
                        continue;
                    }

                    std::cout << i;
                    for (int j = 0; j < ergebnis[i].size(); j++) {
                        std::cout << " -> " << ergebnis[i][j].w << " [" << ergebnis[i][j].weight << "]";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                break;
            }

            // Dijkstra
            case 6: {
                int start = 0;
                int ziel = 6;
                std::cout << "Startknoten: ? ";
                std::cin >> start;

                std::cout << "Zielknoten: ? ";
                std::cin >> ziel;

                DijkstraSP dijkstra(dGraph, start);
                if (dijkstra.hasPathTo(ziel)) {
                    std::vector<DirectedEdge> path = dijkstra.pathTo(ziel);

                    std::cout << std::endl;

                    std::cout << std::endl
                            << "Kurzerster Weg (Djikstra):" << std::endl
                            << "Start:  " << start << std::endl
                            << "Ziel:   " << ziel << std::endl
                            << "Pfad:   " << start;

                    for (DirectedEdge p: path) {
                        std::cout << " [" << p.weight() << "] -> " << p.to();
                    }
                    std::cout << std::endl
                            << "Kosten: " << dijkstra.distTo(ziel) << std::endl
                            << std::endl;
                    break;
                } else {
                    std::cout << "Es gibt keinen Pfad vom Start zum Zielknoten" << std::endl;
                    break;
                }
            }

            //Ausgabe
            case 7: {
                for (int i = 0; i < Graph.getV(); i++) {
                    std::cout << i;
                    for (Edge e: Graph[i]) {
                        std::cout << " -> " << e.other(i) << " [" << e.weight() << "]";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                break;
            }

            // Kante löschen
            case 8: {
                int v = 0;
                int w = 0;
                int weight = 0;
                std::cout << "Bitte ersten Knoten eingeben: " << std::endl;
                std::cout << "?> ";
                std::cin >> v;
                std::cout << "Bitte zweiten Knoten eingeben: " << std::endl;
                std::cout << "?> ";
                std::cin >> w;
                std::cout << "Bitte Kantengewicht eingeben: " << std::endl;
                std::cout << "?> ";
                std::cin >> weight;
                if (dGraph.del_Edge(DirectedEdge(v, w, weight)) && Graph.del_Edge(Edge(v, w, weight))) {
                    std::cout << "Kante gelöscht" << std::endl;
                } else {
                    std::cout << "Kante nicht gefunden" << std::endl;
                }
                break;
            }

            // Kante Hinzufügen
            case 9: {
                int v = 0;
                int w = 0;
                int weight = 0;
                std::cout << "Bitte ersten Knoten eingeben: " << std::endl;
                std::cout << "?> ";
                std::cin >> v;
                std::cout << "Bitte zweiten Knoten eingeben: " << std::endl;
                std::cout << "?> ";
                std::cin >> w;
                std::cout << "Bitte Kantengewicht eingeben: " << std::endl;
                std::cout << "?> ";
                std::cin >> weight;
                dGraph.add(DirectedEdge(v, w, weight));
                Graph.add(Edge(v, w, weight));
                std::cout << "Kante hinzugefügt" << std::endl;
                break;
            }

            // Programm beenden
            case 10: {
                break;
            }

            default: {
                std::cout << "Ungültige Eingabe" << std::endl;
                break;
            }
        }
    }

    return 0;
}
