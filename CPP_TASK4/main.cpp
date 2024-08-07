// adi.yohanann@gmail.com

/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include <SFML/Graphics.hpp>
#include "Complex.hpp"

using namespace std;

int main()
{

    // sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
    // Tree<double,3> three_ary_tree; // 3-ary tree.
    // Tree<double> tree;
    // auto root_node = new Node<double>(1.1);
    
    // tree.add_root(root_node);

    // auto n1 = new Node<double>(1.2);
    // auto n2 = new Node<double>(1.3);
    // auto n3 = new Node<double>(1.4);
    // auto n4 = new Node<double>(1.5);
    // auto n5 = new Node<double>(1.6);

    // tree.add_sub_node(root_node, n1);
    // tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(n1, n3);
    // tree.add_sub_node(n1, n4);
    // tree.add_sub_node(n2, n5);
    // // tree.display();
    // Tree<string> tree;
    // auto root_node = new Node<string>("a");
    // tree.add_root(root_node);

    // Tree<string,3> tree;
    // auto root_node = new Node<string>("a");
    // tree.add_root(root_node);

    // auto n1 = new Node<string>("b");
    // auto n2 = new Node<string>("c");
    // auto n3 = new Node<string>("d");
    // auto n4 = new Node<string>("e");
    // auto n5 = new Node<string>("f");
    // auto n6 = new Node<string>("g");
    // auto n7 = new Node<string>("h");
    // auto n8 = new Node<string>("i");

    // tree.add_sub_node(root_node, n1);
    // tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(root_node, n3);
    // tree.add_sub_node(n1, n4);
    // tree.add_sub_node(n1, n5);
    // tree.add_sub_node(n1, n6);
    // tree.add_sub_node(n3, n7);
    // tree.add_sub_node(n3, n8);

    // tree.display();

    
    Tree<Complex,3> tree;
    auto root_node = new Node<Complex>(Complex(1, 1));
    tree.add_root(root_node);

    auto n1 = new Node<Complex>(Complex(1, 2));
    auto n2 = new Node<Complex>(Complex(1, 3));
    auto n3 = new Node<Complex>(Complex(1, 4));
    auto n4 = new Node<Complex>(Complex(1, 5));
    auto n5 = new Node<Complex>(Complex(1, 6));
    auto n6 = new Node<Complex>(Complex(1, 7));

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n1, n6);
    cout << "Heapify: " << endl;
    for(auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
    {
        cout << node.get_value()<<", ";
    }
    std::cout << std::endl;
    


    

    //  tree.print(); // Should print the tree using GUI.

    
//      sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
//     // auto root =new Node<double>(1.2);
    // auto root_node = new Node<double>(1.1);
    // Tree<double> tree; // Binary tree that contains doubles.
    // tree.add_root(root_node);
    // auto n1 = new Node<double>(1.2);
    // auto n2 = new Node<double>(1.3);
    // auto n3 = new Node<double>(1.4);
    // auto n4 = new Node<double>(1.5);
    // auto n5 = new Node<double>(1.6);

    // tree.add_sub_node(root_node, n1);
    // tree.add_sub_node(root_node, n2);
    // tree.add_sub_node(n1, n3);
    // tree.add_sub_node(n1, n4);
    // tree.add_sub_node(n2, n5);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear(sf::Color::White);
//         tree.draw(window);
//         window.display();
//     }
   
//    tree.print(); // Should print the tree using GUI.

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "binary tree iterators " << endl;

    cout << "pre-order: " << endl;
    for (auto node = tree.begin_preorder(); node != tree.end_preorder(); ++node)
    {        
        cout << node.get_value()<<", ";        
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
     std::cout << std::endl;

    cout << "post-order: " << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node.get_value()<<", ";   
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    std::cout << std::endl;

    cout << "in-order: " << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node.get_value()<<", "; 
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    std::cout << std::endl;

    cout << "BFS: " << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node.get_value()<<", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    std::cout << std::endl;

    cout << "DFS: " << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) 
    {
        cout << node.get_value()<<", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    std::cout << std::endl;


    
    // cout << "Heapify: " << endl;
    // for(auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
    // {
    //     cout << node.get_value()<<", ";
    // }
    // std::cout << std::endl;

    
//     // tree.print(); // Should print the tree using GUI.

//     tree.build_min_heap();

//     std::cout << "After heapify:" << std::endl;
//     tree.print();

//     // for (auto node : tree)
//     // {
//     //     cout << node.get_value() << endl;
//     // } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

//     // cout << tree; // Should print the graph using GUI.


    auto n11 = new Node<double>(1.2);
    auto n22 = new Node<double>(1.3);
    auto n33 = new Node<double>(1.4);
    auto n44 = new Node<double>(1.5);
    auto n55 = new Node<double>(1.6);

    auto root_nodee = new Node<double>(1.1);
    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_nodee);
    three_ary_tree.add_sub_node(root_nodee, n11);
    three_ary_tree.add_sub_node(root_nodee, n22);
    three_ary_tree.add_sub_node(root_nodee, n33);
    three_ary_tree.add_sub_node(n11, n44);
    three_ary_tree.add_sub_node(n22, n55);
    three_ary_tree.display(); // Should print the tree using GUI.


    std::cout << "3-ary tree iterators " << std::endl;
    std::cout << "pre-order: ";
        for (auto node = three_ary_tree.begin_preorder(); node != three_ary_tree.end_preorder(); ++node) {
            std::cout << node.get_value()<<", ";
        }
        std::cout << std::endl;

    std::cout << "post-order: ";
    for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node) {
        std::cout << node.get_value()<<", ";
    }
    std::cout << std::endl;

    std::cout << "in-order: ";
    for (auto node = three_ary_tree.begin_in_order(); node != three_ary_tree.end_in_order(); ++node) {
        std::cout << node.get_value()<<", ";
    
    }
    std::cout << std::endl;

    // std::cout << "bfs-order: ";
    // for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node) {
    //     std::cout << node.get_value()<<", ";
        
    // }
    // std::cout << std::endl;

    std::cout << "DFS: ";
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
        std::cout << node.get_value()<<", ";
        
    }
    std::cout << std::endl;

    std::cout << "Heapify: ";
    for(auto node = three_ary_tree.begin_heap(); node != three_ary_tree.end_heap(); ++node)
    {
        cout << node.get_value()<<", ";
    }
    std::cout << std::endl;
    

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    return 0;
}