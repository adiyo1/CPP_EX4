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

template <typename T, size_t K = 2>
class Tree
{
private:
    Node<T> *root;
    // void heapify(Node<T> *node);
    void print_gui(Node<T> *node, int depth);

public:
    // Tree(int max_children = 2);
    Tree() : root(nullptr) {}
    ~Tree() {}

    void add_root(Node<T> *node)
    {
        // root = node;
        root = node;
    }

    void add_sub_node(Node<T> *parent, Node<T> *child)
    {
        if (parent->children.size() < K)
        {
            parent->children.push_back(child);
        }
        else
        {
            throw std::runtime_error("Cannot add more children to this node.");
        }
    }
    void draw(sf::RenderWindow &window);
    void display();

    // void add_root(Node<T> *node);
    // void add_sub_node(Node<T> *parent, Node<T> *child);
    // void print();
    // void print_structure();
    // void build_min_heap();

    class PreOrderIterator
    {
    private:
        std::stack<Node<T> *> nodes;

    public:
        PreOrderIterator(Node<T> *root)
        {
            if (root != nullptr)
            {
                nodes.push(root);
            }
        }
        bool operator!=(const PreOrderIterator &other) const
        {
            return !nodes.empty() || !other.nodes.empty();
        }
        PreOrderIterator &operator++()
        {
            // if (nodes.empty())
            //     return *this;
            // if (K > 2)
            // {
            //     DFSIterator(*root);
            //     // throw std::runtime_error("Operator in-order can work only on a binary tree.");
            // }
            Node<T> *node = nodes.top();
            nodes.pop();

            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
            {
                nodes.push(*it);
            }

            return *this;
        }
        Node<T> *operator*()
        {
            return nodes.top();
        }
        T get_value() const
        {
            return nodes.top()->key;
        }
    };

    class PostOrderIterator
    {
    private:
        std::stack<Node<T> *> output;

    public:
        PostOrderIterator(Node<T> *root)
        {
            if (root)
            {
                std::stack<Node<T> *> temp;
                temp.push(root);
                while (!temp.empty())
                {
                    Node<T> *node = temp.top();
                    temp.pop();
                    output.push(node);
                    for (auto &child : node->children)
                    {
                        temp.push(child);
                    }
                }
            }
        }

        bool operator!=(const PostOrderIterator &other) const
        {
            return !output.empty() || !other.output.empty();
        }

        PostOrderIterator &operator++()
        {
            // if (K > 2)
            // {
            //     DFSIterator(*root);
            //     // throw std::runtime_error("Operator in-order can work only on a binary tree.");
            // }
            if (!output.empty())
            {
                output.pop();
            }
            return *this;
        }

        Node<T> *operator*()
        {
            return output.top();
        }

        T get_value() const
        {
            return output.top()->key;
        }
    };

    class InOrderIterator
    {
    private:
        std::stack<Node<T> *> nodes;
        Node<T> *current;

    public:
        InOrderIterator(Node<T> *root)
        {
            // if (K > 2)
            // {
            //     DFSIterator(*root);
            //     // return;
            //     // throw std::runtime_error("Operator in-order can work only on a binary tree.");
            // }
            while (root)
            {
                nodes.push(root);
                if (!root->children.empty())
                {
                    root = root->children[0];
                }
                else
                {
                    root = nullptr;
                }
            }
        }
        bool operator!=(const InOrderIterator &other) const
        {
            return !nodes.empty() || !other.nodes.empty();
        }
        InOrderIterator &operator++()
        {
            // if (nodes.empty())
            //     return *this;
            // if (K > 2)
            // {
            //     DFSIterator(*root);
            //     // return ;
            //     // throw std::runtime_error("Operator in-order can work only on a binary tree.");
            // }
            Node<T> *node = nodes.top();
            nodes.pop();

            if (!node->children.empty())
            {
                Node<T> *current = node->children.size() > 1 ? node->children[1] : nullptr;
                while (current)
                {
                    nodes.push(current);
                    if (!current->children.empty())
                    {
                        current = current->children[0];
                    }
                    else
                    {
                        current = nullptr;
                    }
                }
            }

            return *this;
        }
        Node<T> *operator*()
        {
            return nodes.top();
        }
        T get_value() const
        {
            return nodes.top()->key;
        }
    };

    class BFSIterator
    {
    private:
        std::queue<Node<T> *> nodes;

    public:
        BFSIterator(Node<T> *root)
        {
            if (root != nullptr)
            {
                nodes.push(root);
            }
        }
        bool operator!=(const BFSIterator &other) const
        {
            return !nodes.empty() || !other.nodes.empty();
        }
        BFSIterator &operator++()
        {
            if (nodes.empty())
                return *this;
            Node<T> *node = nodes.front();
            nodes.pop();
            for (auto child : node->children)
            {
                nodes.push(child);
            }
            return *this;
        }
        Node<T> *operator*()
        {
            return nodes.front();
        }
        T get_value() const
        {
            return nodes.front()->key;
        }
    };
    class DFSIterator
    {
    private:
        std::stack<Node<T> *> nodes;

    public:
        DFSIterator(Node<T> *root)
        {
            if (root != nullptr)
            {
                nodes.push(root);
            }
        }
        bool operator!=(const DFSIterator &other) const
        {
            return !nodes.empty() || !other.nodes.empty();
        }
        DFSIterator &operator++()
        {
            if (nodes.empty())
                return *this;
            Node<T> *node = nodes.top();
            nodes.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
            {
                nodes.push(*it);
            }
            return *this;
        }
        Node<T> *operator*()
        {
            return nodes.top();
        }
        T get_value() const
        {
            return nodes.top()->key;
        }
    };

    class HeapIterator
    {
    private:
        std::vector<Node<T> *> heap;

        void heapify(Node<T> *node)
        {
            if (!node)
                return;
            heap.push_back(node);
            for (auto &child : node->children)
            {
                heapify(child);
            }
        }

        void build_min_heap()
        {
            for (int i = heap.size() / 2 - 1; i >= 0; --i)
            {
                min_heapify(i);
            }
        }

        void min_heapify(int i)
        {
            int smallest = i;
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;

            if (left < heap.size() && heap[left]->key < heap[smallest]->key)
            {
                smallest = left;
            }

            if (right < heap.size() && heap[right]->key < heap[smallest]->key)
            {
                smallest = right;
            }

            if (smallest != i)
            {
                std::swap(heap[i], heap[smallest]);
                min_heapify(smallest);
            }
        }

    public:
        HeapIterator(Node<T> *root)
        {
            heapify(root);
            build_min_heap();
        }

        bool operator!=(const HeapIterator &other) const
        {
            return !heap.empty() || !other.heap.empty();
        }

        HeapIterator &operator++()
        {
            if (heap.empty())
                return *this;

            std::pop_heap(heap.begin(), heap.end(), [](Node<T> *a, Node<T> *b)
                          { return a->key > b->key; });
            heap.pop_back();

            return *this;
        }
        Node<T> *operator*()
        {
            return heap.front();
        }

        T get_value() const
        {
            return heap.front()->key;
        }
    };

    auto begin_preorder() const
    {
        if constexpr (K == 2)
        {
            return PreOrderIterator(root);
        }

        else
        {
            return DFSIterator(root);
        }
    }

    auto end_preorder()
    {
        if constexpr (K == 2)
        {
            return PreOrderIterator(nullptr);
        }
        else
        {
            return DFSIterator(nullptr);
        }
        
    }

    auto begin_post_order()
    {
        if constexpr (K == 2)
        {
            return PostOrderIterator(root);
        }
        else
        {
            return DFSIterator(root);
        }
        
    }
    auto end_post_order()
    {
        if constexpr (K == 2)
        {
            return PostOrderIterator(nullptr);
        }
        else
        {
            return DFSIterator(nullptr);
        }
        //     return PostOrderIterator(nullptr);
        // return DFSIterator(nullptr);
    }

    auto begin_in_order()
    {
        if constexpr (K == 2)
        {
            return InOrderIterator(root);
        }
        else
        {
            return DFSIterator(root);
        }
        //     return InOrderIterator(root);
        // return DFSIterator(root);
    }
    auto end_in_order()
    {
        if constexpr (K == 2)
        {
            return InOrderIterator(nullptr);
        }
        else
        {
            return DFSIterator(nullptr);
        }
        //     return InOrderIterator(nullptr);
        // return DFSIterator(nullptr);
    }

    BFSIterator begin_bfs_scan()
    {
        return BFSIterator(root);
    }
    BFSIterator end_bfs_scan()
    {
        return BFSIterator(nullptr);
    }
    DFSIterator begin_dfs_scan()
    {
        return DFSIterator(root);
    }
    DFSIterator end_dfs_scan()
    {
        return DFSIterator(nullptr);
    }

    HeapIterator begin_heap()
    {
        return HeapIterator(root);
    }

    HeapIterator end_heap()
    {
        return HeapIterator(nullptr);
    }

private:
    // std::unique_ptr<Node<T>> root;
    size_t maxChildren;

    void draw(sf::RenderWindow &window, Node<T> *node, float x, float y, float offset, sf::Font &font);
    void print(Node<T> *node, int depth) const;
};

template <typename T, size_t K>
void Tree<T, K>::draw(sf::RenderWindow &window, Node<T> *node, float x, float y, float offset, sf::Font &font)
{
    if (!node)
        return;

    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x, y);
    window.draw(circle);

    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(node->key));
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 10, y + 10);
    window.draw(text);

    float child_y = y + 80;
    for (auto &child : node->children)
    {
        float child_x = x + offset * (&child - &node->children[0] - node->children.size() / 2.0);
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20), sf::Color::Black),
            sf::Vertex(sf::Vector2f(child_x + 20, child_y + 20))};

        window.draw(line, 2, sf::Lines);
        draw(window, child, child_x, child_y, offset / 2.0, font);
    }
}

template <typename T, size_t K>
void Tree<T, K>::draw(sf::RenderWindow &window)
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }

    draw(window, this->root, 400, 50, 200, font);
}

template <typename T, size_t K>
void Tree<T, K>::display()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        this->draw(window);
        window.display();
    }
}

// class HeapIterator
// {
// private:
//     std::vector<Node<T> *> nodes;
// public:
//     HeapIterator(Node<T> *root){
//         if (root != nullptr)
//         {
//             nodes.push_back(root);
//         }
//     }
//     bool operator!=(const HeapIterator &other) const{
//         return !nodes.empty() || !other.nodes.empty();
//     }
//     HeapIterator &operator++(){
//         if (nodes.empty())
//             return *this;
//         Node<T> *node = nodes.front();
//         nodes.erase(nodes.begin());
//         for (auto child : node->children)
//         {
//             nodes.push_back(child);
//         }
//         return *this;
//     }
//     Node<T> *operator*(){
//         return nodes.front();
//     }
//     T get_value() const{
//         return nodes.front()->key;
//     }
// };

// PreOrderIterator begin_pre_order();
// PreOrderIterator end_pre_order();
// PostOrderIterator begin_post_order();
// PostOrderIterator end_post_order();
// InOrderIterator begin_in_order();
// InOrderIterator end_in_order();
// BFSIterator begin_bfs_scan();
// BFSIterator end_bfs_scan();
// DFSIterator begin_dfs_scan();
// DFSIterator end_dfs_scan();
// };

#include "Tree.cpp"

#endif // TREE_HPP
