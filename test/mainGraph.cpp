#include "Graph.hpp"

#include <iostream>
#include <string>

void printSection(const std::string& title) {
    std::cout << "\n========================================\n";
    std::cout << title << '\n';
    std::cout << "========================================\n";
}

int main() {
    std::cout << std::boolalpha;

    Graph<std::string> friends;

    printSection("1. Insert vertices and edges");

    friends.insertVertex("Alice");
    friends.insertVertex("Bob");
    friends.insertVertex("Emma");
    friends.insertVertex("John");
    friends.insertVertex("Maria");
    friends.insertVertex("Daniel");

    friends.insertEdge("Alice", "Bob");
    friends.insertEdge("Alice", "Emma");
    friends.insertEdge("Alice", "John");
    friends.insertEdge("Bob", "Emma");
    friends.insertEdge("Bob", "Maria");
    friends.insertEdge("Emma", "John");
    friends.insertEdge("Emma", "Maria");
    friends.insertEdge("Maria", "Daniel");

    // Duplicate edges must not be inserted.
    friends.insertEdge("Alice", "Bob");

    friends.print();

    std::cout << "\nAlice -> Bob: " << friends.hasEdge("Alice", "Bob") << '\n';
    std::cout << "Bob -> Alice: " << friends.hasEdge("Bob", "Alice") << '\n';

    printSection("2. Insert and remove self-loops");

    friends.insertEdge("Alice", "Alice");
    friends.insertEdge("Daniel", "Daniel");

    std::cout << "Before removeSelfEdges:\n";
    std::cout << "Alice has a self-loop: " << friends.hasEdge("Alice", "Alice") << '\n';
    std::cout << "Daniel has a self-loop: " << friends.hasEdge("Daniel", "Daniel") << '\n';
    friends.print();

    friends.removeSelfEdges();

    std::cout << "\nAfter removeSelfEdges:\n";
    std::cout << "Alice has a self-loop: " << friends.hasEdge("Alice", "Alice") << '\n';
    std::cout << "Daniel has a self-loop: " << friends.hasEdge("Daniel", "Daniel") << '\n';
    friends.print();

    printSection("3. Print common neighbours");

    friends.printCommonNeighbors();

    printSection("4. Remove a regular edge");

    std::cout << "Before removing Alice--John:\n";
    std::cout << "Alice -> John: " << friends.hasEdge("Alice", "John") << '\n';
    std::cout << "John -> Alice: " << friends.hasEdge("John", "Alice") << '\n';

    friends.removeEdge("Alice", "John");

    std::cout << "\nAfter removing Alice--John:\n";
    std::cout << "Alice -> John: " << friends.hasEdge("Alice", "John") << '\n';
    std::cout << "John -> Alice: " << friends.hasEdge("John", "Alice") << '\n';
    friends.print();

    printSection("5. Remove a self-loop with removeEdge");

    friends.insertEdge("Daniel", "Daniel");
    std::cout << "Before removing Daniel--Daniel: " << friends.hasEdge("Daniel", "Daniel") << '\n';

    friends.removeEdge("Daniel", "Daniel");

    std::cout << "After removing Daniel--Daniel: " << friends.hasEdge("Daniel", "Daniel") << '\n';

    printSection("6. Remove a vertex");

    std::cout << "Before removing Emma:\n";
    friends.print();

    friends.removeVertex("Emma");

    std::cout << "\nAfter removing Emma:\n";
    friends.print();

    std::cout << "\nEdges involving the removed vertex:\n";
    std::cout << "Alice -> Emma: " << friends.hasEdge("Alice", "Emma") << '\n';
    std::cout << "Bob -> Emma: " << friends.hasEdge("Bob", "Emma") << '\n';
    std::cout << "John -> Emma: " << friends.hasEdge("John", "Emma") << '\n';

    printSection("7. Verify the graph after vertex removal");

    std::cout << "Common neighbours after removing Emma:\n";
    friends.printCommonNeighbors();

    std::cout << "\nBFS and DFS after removing Emma:\n";
    friends.BFS("Alice");
    friends.DFS("Alice");

    std::cout << "\nGraph is connected: " << friends.isConnected() << '\n';

    printSection("8. Invalid removal requests");

    friends.removeEdge("Alice", "Unknown");
    friends.removeVertex("Unknown");

    return 0;
}
