#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>
#include <stack>
#include <cmath>
#include <SFML/Graphics.hpp>

// template<typename T>
// class Tree {
// private:
//     Node<T>* root;
//     int max_children;

template<typename T, int K = 2>
class Tree {
private:
    Node<T>* root;
    void heapify(Node<T>* node);
    void print_gui(Node<T>* node, int depth);

public:
    // Tree(int max_children = 2);
    Tree();
    ~Tree();

    void add_root(Node<T>* node);
    void add_sub_node(Node<T>* parent, Node<T>* child);
    void print();
    void print_structure();
    void build_min_heap();
    void draw(sf::RenderWindow& window, Node<T>* node, float x, float y, float offset, sf::Font& font);
    void draw(sf::RenderWindow& window);
    
    



    class PreOrderIterator {
    private:
        std::stack<Node<T>*> nodes;

    public:
        PreOrderIterator(Node<T>* root);
        bool operator!=(const PreOrderIterator& other) const;
        PreOrderIterator& operator++();
        Node<T>* operator*();
        T get_value() const;
    };

    class PostOrderIterator {
    private:
        std::stack<Node<T>*> nodes;
        std::stack<Node<T>*> output;

    public:
        PostOrderIterator(Node<T>* root);
        bool operator!=(const PostOrderIterator& other) const;
        PostOrderIterator& operator++();
        Node<T>* operator*();
        T get_value() const;
    };

    class InOrderIterator {
    private:
        std::stack<Node<T>*> nodes;
        Node<T>* current;

    public:
        InOrderIterator(Node<T>* root);
        bool operator!=(const InOrderIterator& other) const;
        InOrderIterator& operator++();
        Node<T>* operator*();
        T get_value() const;
    };

    class BFSIterator {
    private:
        std::queue<Node<T>*> nodes;

    public:
        BFSIterator(Node<T>* root);
        bool operator!=(const BFSIterator& other) const;
        BFSIterator& operator++();
        Node<T>* operator*();
        T get_value() const;
    };
    class DFSIterator {
    private:
        std::stack<Node<T>*> nodes;

    public:
        DFSIterator(Node<T>* root);
        bool operator!=(const DFSIterator& other) const;
        DFSIterator& operator++();
        Node<T>* operator*();
        T get_value() const;
    };

    PreOrderIterator begin_pre_order();
    PreOrderIterator end_pre_order();
    PostOrderIterator begin_post_order();
    PostOrderIterator end_post_order();
    InOrderIterator begin_in_order();
    InOrderIterator end_in_order();
    BFSIterator begin_bfs_scan();
    BFSIterator end_bfs_scan();
    DFSIterator begin_dfs_scan();
    DFSIterator end_dfs_scan();
};



#include "Tree.cpp"

#endif // TREE_HPP
