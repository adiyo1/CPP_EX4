// adi.yohanann@gmail.com

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
#include "Complex.hpp"

template <typename T, size_t K = 2> // default is binary tree
class Tree
{
private:
    Node<T> *root;
    void delete_subtree(Node<T> *node)
    {
        if (!node)
            return;
        for (auto &child : node->children)
        {
            delete_subtree(child); // recursively delete children of the current node
        }
        delete node;
    }

public:
    Tree() : root(nullptr) {}
    ~Tree() { delete_subtree(root); }

    void add_root(Node<T> *node)
    {
        root = node;
    }

    void add_sub_node(Node<T> *parent, Node<T> *child)
    {
        if (parent->children.size() < K) // check if the parent has less than K children
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

    class PreOrderIterator
    {
    private:
        std::stack<Node<T> *> nodes; // stack to store nodes

    public:
        PreOrderIterator(Node<T> *root) // constructor
        {
            if (root != nullptr) // if the root is not null, push it to the stack
            {
                nodes.push(root);
            }
        }
        
        bool operator!=(const PreOrderIterator &other) const
        {
            return !nodes.empty() || !other.nodes.empty(); // check if the stack is empty
        }
        
        PreOrderIterator &operator++() // increment operator
        {
            Node<T> *node = nodes.top();
            nodes.pop();

            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) // iterate over the children of the current node
            {
                nodes.push(*it);
            }

            return *this; // return the iterator
        }
        
        Node<T> *operator*() // dereference operator
        {
            return nodes.top(); // return the top element of the stack
        }
        
        T get_value() const // get the value of the node
        {
            return nodes.top()->key;
        }
    };

    class PostOrderIterator
    {
    private:
        std::stack<Node<T> *> output; // stack to store the output

    public:
        PostOrderIterator(Node<T> *root) // constructor
        {
            if (root)
            {
                std::stack<Node<T> *> temp; // temporary stack
                temp.push(root);
                while (!temp.empty()) // iterate over the stack
                {
                    Node<T> *node = temp.top();        // get the top element
                    temp.pop();                        // pop the top element
                    output.push(node);                 // push the element to the output stack
                    for (auto &child : node->children) // iterate over the children of the current node
                    {
                        temp.push(child); // push the children to the temporary stack
                    }
                }
            }
        }

        bool operator!=(const PostOrderIterator &other) const // check if the stack is empty
        {
            return !output.empty() || !other.output.empty(); //
        }

        PostOrderIterator &operator++() // increment operator
        {
            if (!output.empty())
            {
                output.pop();
            }
            return *this;
        }

        Node<T> *operator*() // dereference operator
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
        InOrderIterator(Node<T> *root) // constructor
        {
            while (root) // iterate over the tree
            {
                nodes.push(root);
                if (!root->children.empty()) // check if the node has children
                {
                    root = root->children[0]; // get the first child
                }
                else
                {
                    root = nullptr;
                }
            }
        }
        
        bool operator!=(const InOrderIterator &other) const // check if the stack is empty
        {
            return !nodes.empty() || !other.nodes.empty();
        }
        
        InOrderIterator &operator++() // increment operator
        {
            Node<T> *node = nodes.top();
            nodes.pop();

            if (!node->children.empty())
            {
                Node<T> *current = node->children.size() > 1 ? node->children[1] : nullptr; // get the next child
                while (current)                                                             // iterate over the children
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
        
        Node<T> *operator*() // dereference operator
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
        BFSIterator(Node<T> *root) // constructor
        {
            if (root != nullptr)
            {
                nodes.push(root);
            }
        }
        
        bool operator!=(const BFSIterator &other) const // check if the queue is empty
        {
            return !nodes.empty() || !other.nodes.empty();
        }
        
        BFSIterator &operator++() // increment operator
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
        
        Node<T> *operator*() // dereference operator
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
        DFSIterator(Node<T> *root) // constructor
        {
            if (root != nullptr)
            {
                nodes.push(root);
            }
        }
        
        bool operator!=(const DFSIterator &other) const // check if the stack is empty
        {
            return !nodes.empty() || !other.nodes.empty();
        }
        
        DFSIterator &operator++() // increment operator
        {
            if (nodes.empty())
                return *this;
            Node<T> *node = nodes.top();
            nodes.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) // iterate over the children of the current node
            {
                nodes.push(*it);
            }
            return *this;
        }
        
        Node<T> *operator*() // dereference operator
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

        void heapify(Node<T> *node) // heapify the tree
        {
            if (!node)
                return;
            heap.push_back(node);
            for (auto &child : node->children) // iterate over the children of the current node
            {
                heapify(child);
            }
        }

        void build_min_heap()
        {
            for (int i = heap.size() / 2 - 1; i >= 0; --i) // iterate over the heap
            {
                min_heapify(i); // heapify the heap
            }
        }

        void min_heapify(int i)
        {
            double smallest = i;      // set the current node as the smallest
            double left = 2 * i + 1;  // get the left child
            double right = 2 * i + 2; // get the right child

            if (left < heap.size() && heap[left]->key < heap[smallest]->key) // check if the left child is smaller than the current node
            {
                smallest = left; // set the left child as the smallest
            }

            if (right < heap.size() && heap[right]->key < heap[smallest]->key) // check if the right child is smaller than the current node
            {
                smallest = right; // set the right child as the smallest
            }

            if (smallest != i) // swap the current node with the smallest node
            {
                std::swap(heap[i], heap[smallest]);
                min_heapify(smallest); // heapify the heap
            }
        }

    public:
        HeapIterator(Node<T> *root) // constructor
        {
            heapify(root);    // for each node in the tree, heapify the tree
            build_min_heap(); // build the min heap from the heap
        }

        bool operator!=(const HeapIterator &other) const // check if the heap is empty
        {
            return !heap.empty() || !other.heap.empty();
        }

        HeapIterator &operator++() // increment operator
        {
            if (heap.empty())
                return *this;

            std::pop_heap(heap.begin(), heap.end(), [](Node<T> *a, Node<T> *b) // pop the smallest element from the heap
                          { return a->key >= b->key; });
            heap.pop_back();

            return *this;
        }
        
        Node<T> *operator*() // dereference operator
        {
            return heap.front();
        }

        T get_value() const
        {
            return heap.front()->key;
        }
    };

    auto begin_preorder() const // begin the preorder traversal
    {
        if constexpr (K == 2) // check if the tree is binary
        {
            return PreOrderIterator(root);
        }

        else // if the tree is not binary do a DFS traversal
        {
            return DFSIterator(root);
        }
    }

    auto end_preorder() // end the preorder traversal
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

    auto begin_post_order() // begin the postorder traversal
    {
        if constexpr (K == 2) // check if the tree is binary
        {
            return PostOrderIterator(root);
        }
        else // if the tree is not binary do a DFS traversal
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
        else // if the tree is not binary do a DFS traversal
        {
            return DFSIterator(nullptr);
        }
    }

    auto begin_in_order()
    {
        if constexpr (K == 2)
        {
            return InOrderIterator(root);
        }
        else // if the tree is not binary do a DFS traversal
        {
            return DFSIterator(root);
        }
    }
    
    auto end_in_order()
    {
        if constexpr (K == 2)
        {
            return InOrderIterator(nullptr);
        }
        else // if the tree is not binary do a DFS traversal
        {
            return DFSIterator(nullptr);
        }
    }

    BFSIterator begin_bfs_scan()
    {
        return BFSIterator(root); // begin the BFS traversal
    }
    
    BFSIterator end_bfs_scan()
    {
        return BFSIterator(nullptr); // end the BFS traversal
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

    size_t maxChildren;
    void draw(sf::RenderWindow &window, Node<T> *node, float x, float y, float offset, sf::Font &font);
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
    if constexpr (std::is_same_v<T, std::string>)
    {
        text.setString(node->key);
    }
    else if constexpr (std::is_same_v<T, Complex>)
    {
        text.setString(node->key.to_string());
    }
    else
    {
        text.setString(std::to_string(node->key));
    }
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
void Tree<T, K>::display()// display the tree
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

#endif // TREE_HPP
