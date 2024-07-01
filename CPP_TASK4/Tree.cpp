// #include "Tree.hpp"

// template<typename T>
// Tree<T>::Tree(int max_children) : root(nullptr), max_children(max_children) {}

// template<typename T>
// Tree<T>::~Tree() {
//     // Implement proper memory management if needed
// }

// template<typename T>
// void Tree<T>::add_root(Node<T>* node) {
//     root = node;
// }

// template<typename T>
// void Tree<T>::add_sub_node(Node<T>* parent, Node<T>* child) {
//     if (parent->children.size() < max_children) {
//         parent->children.push_back(child);
//     } else {
//         std::cerr << "Cannot add more children to this node." << std::endl;
//     }
// }

// template<typename T>
// void Tree<T>::print() {
//     print_structure();
// }

// template<typename T>
// void Tree<T>::print_structure() {
//     if (!root) return;

//     std::vector<std::vector<Node<T>*>> levels;
//     std::queue<Node<T>*> current_level;
//     current_level.push(root);

//     while (!current_level.empty()) {
//         std::vector<Node<T>*> level_nodes;
//         int level_size = current_level.size();

//         while (level_size > 0) {
//             Node<T>* node = current_level.front();
//             current_level.pop();
//             level_nodes.push_back(node);

//             for (Node<T>* child : node->children) {
//                 current_level.push(child);
//             }

//             level_size--;
//         }

//         levels.push_back(level_nodes);
//     }

//     int depth = levels.size();
//     int max_width = pow(2, depth) * 2;

//     for (int i = 0; i < depth; ++i) {
//         int node_count = levels[i].size();
//         int spacing = max_width / (node_count + 1);

//         for (int j = 0; j < node_count; ++j) {
//             if (j == 0) {
//                 std::cout << std::string(spacing / 2, ' ');
//             } else {
//                 std::cout << std::string(spacing, ' ');
//             }

//             std::cout << levels[i][j]->key;
//         }

//         std::cout << std::endl;

//         if (i < depth - 1) {
//             for (int j = 0; j < node_count; ++j) {
//                 if (j == 0) {
//                     std::cout << std::string(spacing / 2 - 1, ' ');
//                 } else {
//                     std::cout << std::string(spacing - 1, ' ');
//                 }

//                 if (levels[i][j]->children.size() > 0) {
//                     std::cout << "/";
//                 } else {
//                     std::cout << " ";
//                 }

//                 std::cout << std::string(spacing - 2, ' ');

//                 if (levels[i][j]->children.size() > 1) {
//                     std::cout << "\\";
//                 } else {
//                     std::cout << " ";
//                 }
//             }
//             std::cout << std::endl;
//         }
//     }
// }
// // Pre-order iterator
// template<typename T>
// Tree<T>::PreOrderIterator::PreOrderIterator(Node<T>* root) {
//     if (root) {
//         nodes.push(root);
//     }
// }

// template<typename T>
// bool Tree<T>::PreOrderIterator::operator!=(const PreOrderIterator& other) const {
//     return !nodes.empty() || !other.nodes.empty();
// }

// template<typename T>
// typename Tree<T>::PreOrderIterator& Tree<T>::PreOrderIterator::operator++() {
//     if (nodes.empty()) return *this;

//     Node<T>* node = nodes.top();
//     nodes.pop();

//     for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
//         nodes.push(*it);
//     }

//     return *this;
// }

// template<typename T>
// Node<T>* Tree<T>::PreOrderIterator::operator*() {
//     return nodes.top();
// }

// template<typename T>
// T Tree<T>::PreOrderIterator::get_value() const {
//     return nodes.top()->key;
// }

// template<typename T>
// typename Tree<T>::PreOrderIterator Tree<T>::begin_pre_order() {
//     return PreOrderIterator(root);
// }

// template<typename T>
// typename Tree<T>::PreOrderIterator Tree<T>::end_pre_order() {
//     return PreOrderIterator(nullptr);
// }

// // Post-order iterator
// template<typename T>
// Tree<T>::PostOrderIterator::PostOrderIterator(Node<T>* root) {
//     if (root) {
//         std::stack<Node<T>*> temp;
//         temp.push(root);
//         while (!temp.empty()) {
//             Node<T>* node = temp.top();
//             temp.pop();
//             output.push(node);
//             for (auto child : node->children) {
//                 temp.push(child);
//             }
//         }
//     }
// }

// template<typename T>
// bool Tree<T>::PostOrderIterator::operator!=(const PostOrderIterator& other) const {
//     return !output.empty() || !other.output.empty();
// }

// template<typename T>
// typename Tree<T>::PostOrderIterator& Tree<T>::PostOrderIterator::operator++() {
//     if (!output.empty()) {
//         output.pop();
//     }
//     return *this;
// }

// template<typename T>
// Node<T>* Tree<T>::PostOrderIterator::operator*() {
//     return output.top();
// }

// template<typename T>
// T Tree<T>::PostOrderIterator::get_value() const {
//     return output.top()->key;
// }

// template<typename T>
// typename Tree<T>::PostOrderIterator Tree<T>::begin_post_order() {
//     return PostOrderIterator(root);
// }

// template<typename T>
// typename Tree<T>::PostOrderIterator Tree<T>::end_post_order() {
//     return PostOrderIterator(nullptr);
// }

// // In-order iterator
// template<typename T>
// Tree<T>::InOrderIterator::InOrderIterator(Node<T>* root) : current(root) {
//     while (current) {
//         nodes.push(current);
//         if (!current->children.empty()) {
//             current = current->children[0];
//         } else {
//             current = nullptr;
//         }
//     }
// }

// template<typename T>
// bool Tree<T>::InOrderIterator::operator!=(const InOrderIterator& other) const {
//     return !nodes.empty() || !other.nodes.empty();
// }

// template<typename T>
// typename Tree<T>::InOrderIterator& Tree<T>::InOrderIterator::operator++() {
//     if (nodes.empty()) return *this;

//     Node<T>* node = nodes.top();
//     nodes.pop();

//     if (!node->children.empty()) {
//         Node<T>* current = node->children.size() > 1 ? node->children[1] : nullptr;
//         while (current) {
//             nodes.push(current);
//             if (!current->children.empty()) {
//                 current = current->children[0];
//             } else {
//                 current = nullptr;
//             }
//         }
//     }

//     return *this;
// }

// template<typename T>
// Node<T>* Tree<T>::InOrderIterator::operator*() {
//     return nodes.top();
// }

// template<typename T>
// T Tree<T>::InOrderIterator::get_value() const {
//     return nodes.top()->key;
// }

// template<typename T>
// typename Tree<T>::InOrderIterator Tree<T>::begin_in_order() {
//     return InOrderIterator(root);
// }

// template<typename T>
// typename Tree<T>::InOrderIterator Tree<T>::end_in_order() {
//     return InOrderIterator(nullptr);
// }

// // BFS iterator
// template<typename T>
// Tree<T>::BFSIterator::BFSIterator(Node<T>* root) {
//     if (root) {
//         nodes.push(root);
//     }
// }

// template<typename T>
// bool Tree<T>::BFSIterator::operator!=(const BFSIterator& other) const {
//     return !nodes.empty() || !other.nodes.empty();
// }

// template<typename T>
// typename Tree<T>::BFSIterator& Tree<T>::BFSIterator::operator++() {
//     if (nodes.empty()) return *this;

//     Node<T>* node = nodes.front();
//     nodes.pop();

//     for (auto child : node->children) {
//         nodes.push(child);
//     }

//     return *this;
// }

// template<typename T>
// Node<T>* Tree<T>::BFSIterator::operator*() {
//     return nodes.front();
// }

// template<typename T>
// T Tree<T>::BFSIterator::get_value() const {
//     return nodes.front()->key;
// }

// template<typename T>
// typename Tree<T>::BFSIterator Tree<T>::begin_bfs_scan() {
//     return BFSIterator(root);
// }

// template<typename T>
// typename Tree<T>::BFSIterator Tree<T>::end_bfs_scan() {
//     return BFSIterator(nullptr);
// }


#include "Tree.hpp"
// #include <SFML/Graphics.hpp>


template<typename T, int K>
Tree<T, K>::Tree() : root(nullptr) {}

template<typename T, int K>
Tree<T, K>::~Tree() {
    // Implement proper memory management if needed
    delete root;
}

template<typename T, int K>
void Tree<T, K>::add_root(Node<T>* node) {
    // root = node;
     this->root = node;
}

template<typename T, int K>
void Tree<T, K>::add_sub_node(Node<T>* parent, Node<T>* child) {
    if (parent->children.size() < K) {
        parent->children.push_back(child);
    } else {
        throw std::runtime_error("Cannot add more children to this node.");
    }
}

template<typename T, int K>
void Tree<T, K>::print() {
    print_structure();
}

template<typename T, int K>
void Tree<T, K>::print_structure() {
    if (!root) return;

    std::vector<std::vector<Node<T>*>> levels;
    std::queue<Node<T>*> current_level;
    current_level.push(root);

    while (!current_level.empty()) {
        std::vector<Node<T>*> level_nodes;
        int level_size = current_level.size();

        while (level_size > 0) {
            Node<T>* node = current_level.front();
            current_level.pop();
            level_nodes.push_back(node);

            for (Node<T>* child : node->children) {
                current_level.push(child);
            }

            level_size--;
        }

        levels.push_back(level_nodes);
    }

    int depth = levels.size();
    int max_width = pow(2, depth) * 2;

    for (int i = 0; i < depth; ++i) {
        int node_count = levels[i].size();
        int spacing = max_width / (node_count + 1);

        for (int j = 0; j < node_count; ++j) {
            if (j == 0) {
                std::cout << std::string(spacing / 2, ' ');
            } else {
                std::cout << std::string(spacing, ' ');
            }

            std::cout << levels[i][j]->key;
        }

        std::cout << std::endl;

        if (i < depth - 1) {
            for (int j = 0; j < node_count; ++j) {
                if (j == 0) {
                    std::cout << std::string(spacing / 2 - 1, ' ');
                } else {
                    std::cout << std::string(spacing - 1, ' ');
                }

                if (levels[i][j]->children.size() > 0) {
                    std::cout << "/";
                } else {
                    std::cout << " ";
                }

                std::cout << std::string(spacing - 2, ' ');

                if (levels[i][j]->children.size() > 1) {
                    std::cout << "\\";
                } else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}

// Pre-order iterator
template<typename T, int K>
Tree<T, K>::PreOrderIterator::PreOrderIterator(Node<T>* root) {
    if (root) {
        nodes.push(root);
    }
}

template<typename T, int K>
bool Tree<T, K>::PreOrderIterator::operator!=(const PreOrderIterator& other) const {
    return !nodes.empty() || !other.nodes.empty();
}

template<typename T, int K>
typename Tree<T, K>::PreOrderIterator& Tree<T, K>::PreOrderIterator::operator++() {
    if (nodes.empty()) return *this;
    if(K> 2){
        throw std::runtime_error("Operator pre-order can work only on a binary tree.");
    }
    Node<T>* node = nodes.top();
    nodes.pop();

    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        nodes.push(*it);
    }

    return *this;
}

template<typename T, int K>
Node<T>* Tree<T, K>::PreOrderIterator::operator*() {
    return nodes.top();
}

template<typename T, int K>
T Tree<T, K>::PreOrderIterator::get_value() const {
    return nodes.top()->key;
}

template<typename T, int K>
typename Tree<T, K>::PreOrderIterator Tree<T, K>::begin_pre_order() {
    return PreOrderIterator(root);
}

template<typename T, int K>
typename Tree<T, K>::PreOrderIterator Tree<T, K>::end_pre_order() {
    return PreOrderIterator(nullptr);
}

// Post-order iterator
template<typename T, int K>
Tree<T, K>::PostOrderIterator::PostOrderIterator(Node<T>* root) {
    if(K> 2){
        throw std::runtime_error("Operator in-order can work only on a binary tree.");
    }
    if (root) {
        std::stack<Node<T>*> temp;
        temp.push(root);
        while (!temp.empty()) {
            Node<T>* node = temp.top();
            temp.pop();
            output.push(node);
            for (auto child : node->children) {
                temp.push(child);
            }
        }
    }
}

template<typename T, int K>
bool Tree<T, K>::PostOrderIterator::operator!=(const PostOrderIterator& other) const {
    return !output.empty() || !other.output.empty();
}

template<typename T, int K>
typename Tree<T, K>::PostOrderIterator& Tree<T, K>::PostOrderIterator::operator++() {
    if (!output.empty()) {
        output.pop();
    }
    return *this;
}

template<typename T, int K>
Node<T>* Tree<T, K>::PostOrderIterator::operator*() {
    return output.top();
}

template<typename T, int K>
T Tree<T, K>::PostOrderIterator::get_value() const {
    return output.top()->key;
}

template<typename T, int K>
typename Tree<T, K>::PostOrderIterator Tree<T, K>::begin_post_order() {
    return PostOrderIterator(root);
}

template<typename T, int K>
typename Tree<T, K>::PostOrderIterator Tree<T, K>::end_post_order() {
    return PostOrderIterator(nullptr);
}

// In-order iterator
template<typename T, int K>
Tree<T, K>::InOrderIterator::InOrderIterator(Node<T>* root) : current(root) {
    while (current) {
        nodes.push(current);
        if (!current->children.empty()) {
            current = current->children[0];
        } else {
            current = nullptr;
        }
    }
}

template<typename T, int K>
bool Tree<T, K>::InOrderIterator::operator!=(const InOrderIterator& other) const {
    return !nodes.empty() || !other.nodes.empty();
}

template<typename T, int K>
typename Tree<T, K>::InOrderIterator& Tree<T, K>::InOrderIterator::operator++() {
    if (nodes.empty()) return *this;
    if(K> 2){
        throw std::runtime_error("Operator in-order can work only on a binary tree.");
    }
    Node<T>* node = nodes.top();
    nodes.pop();

    if (!node->children.empty()) {
        Node<T>* current = node->children.size() > 1 ? node->children[1] : nullptr;
        while (current) {
            nodes.push(current);
            if (!current->children.empty()) {
                current = current->children[0];
            } else {
                current = nullptr;
            }
        }
    }

    return *this;
}

template<typename T, int K>
Node<T>* Tree<T, K>::InOrderIterator::operator*() {
    return nodes.top();
}

template<typename T, int K>
T Tree<T, K>::InOrderIterator::get_value() const {
    return nodes.top()->key;
}

template<typename T, int K>
typename Tree<T, K>::InOrderIterator Tree<T, K>::begin_in_order() {
    return InOrderIterator(root);
}

template<typename T, int K>
typename Tree<T, K>::InOrderIterator Tree<T, K>::end_in_order() {
    return InOrderIterator(nullptr);
}

// BFS iterator
template<typename T, int K>
Tree<T, K>::BFSIterator::BFSIterator(Node<T>* root) {
    if (root) {
        nodes.push(root);
    }
}

template<typename T, int K>
bool Tree<T, K>::BFSIterator::operator!=(const BFSIterator& other) const {
    return !nodes.empty() || !other.nodes.empty();
}

template<typename T, int K>
typename Tree<T, K>::BFSIterator& Tree<T, K>::BFSIterator::operator++() {
    if (nodes.empty()) return *this;

    Node<T>* node = nodes.front();
    nodes.pop();

    for (auto child : node->children) {
        nodes.push(child);
    }

    return *this;
}

template<typename T, int K>
Node<T>* Tree<T, K>::BFSIterator::operator*() {
    return nodes.front();
}

template<typename T, int K>
T Tree<T, K>::BFSIterator::get_value() const {
    return nodes.front()->key;
}

template<typename T, int K>
typename Tree<T, K>::BFSIterator Tree<T, K>::begin_bfs_scan() {
    return BFSIterator(root);
}

template<typename T, int K>
typename Tree<T, K>::BFSIterator Tree<T, K>::end_bfs_scan() {
    return BFSIterator(nullptr);
}

// DFS iterator
template<typename T, int K>
Tree<T, K>::DFSIterator::DFSIterator(Node<T>* root) {
    if (root) {
        nodes.push(root);
    }
}

template<typename T, int K>
bool Tree<T, K>::DFSIterator::operator!=(const DFSIterator& other) const {
    return !nodes.empty() || !other.nodes.empty();
}

template<typename T, int K>
typename Tree<T, K>::DFSIterator& Tree<T, K>::DFSIterator::operator++() {
    if (nodes.empty()) return *this;

    Node<T>* node = nodes.top();
    nodes.pop();

    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        nodes.push(*it);
    }

    return *this;
}

template<typename T, int K>
Node<T>* Tree<T, K>::DFSIterator::operator*() {
    return nodes.top();
}

template<typename T, int K>
T Tree<T, K>::DFSIterator::get_value() const {
    return nodes.top()->key;
}

template<typename T, int K>
typename Tree<T, K>::DFSIterator Tree<T, K>::begin_dfs_scan() {
    return DFSIterator(root);
}

template<typename T, int K>
typename Tree<T, K>::DFSIterator Tree<T, K>::end_dfs_scan() {
    return DFSIterator(nullptr);
}

template<typename T, int K>
void Tree<T, K>::heapify(Node<T>* node) {
    if (!node) return;

    for (Node<T>* child : node->children) {
        if (child->key < node->key) {
            std::swap(child->key, node->key);
            heapify(child);
        }
    }
}

template<typename T, int K>
void Tree<T, K>::build_min_heap() {
    if (!root) return;
    if(K> 2){
        throw std::runtime_error("Operator min-heap can work only on a binary tree.");
    }
    std::queue<Node<T>*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        Node<T>* node = nodes.front();
        nodes.pop();

        for (Node<T>* child : node->children) {
            nodes.push(child);
        }

        heapify(node);
    }
}

template <typename T, int K>
void Tree<T, K>::draw(sf::RenderWindow& window, Node<T>* node, float x, float y, float offset, sf::Font& font) {
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
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 10, y + 10);
    window.draw(text);

    float child_y = y + 80;
    for (auto& child : node->children) {
        float child_x = x + offset * (&child - &node->children[0] - node->children.size() / 2.0);
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x + 20, y + 20)),
            sf::Vertex(sf::Vector2f(child_x + 20, child_y + 20))
        };

        window.draw(line, 2, sf::Lines);
        draw(window, child, child_x, child_y, offset / 2.0, font);
    }
}

template <typename T, int K>
void Tree<T, K>::draw(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }

    draw(window, this->root, 400, 50, 200, font);
}


// Explicit template instantiation
// template class Tree<double>;