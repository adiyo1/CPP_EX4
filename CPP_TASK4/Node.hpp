#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template<typename T>
class Node {
public:
    T key;
    std::vector<Node<T>*> children;

    Node(const T& key) : key(key) {}
};

#endif // NODE_HPP
