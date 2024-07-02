// adi.yohanann@gmail.com

#include "doctest.h"
#include "Tree.hpp"
#include "Complex.hpp"
#include <string>

using namespace std;

TEST_CASE("Tree with string: K = 2")
{
    Tree<string> tree;
    auto root_node = new Node<string>("shahar");
    tree.add_root(root_node);

    auto n1 = new Node<string>("raanan");
    auto n2 = new Node<string>("adi");
    auto n3 = new Node<string>("neta");
    auto n4 = new Node<string>("oriya");
    auto n5 = new Node<string>("oran");

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    SUBCASE("Test 1: Preorder")
    {

        string expected = "shahar, raanan, neta, oriya, adi, oran, ";
        string actual = "";
        for (auto node = tree.begin_preorder(); node != tree.end_preorder(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 2: Postorder")
    {
        string expected = "neta, oriya, raanan, oran, adi, shahar, ";
        string actual = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 3: Inorder")
    {
        string expected = "neta, raanan, oriya, shahar, oran, adi, ";
        string actual = "";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 4: BFS order")
    {
        string expected = "shahar, raanan, adi, neta, oriya, oran, ";
        string actual = "";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 5: DFS order")
    {
        string expected = "shahar, raanan, neta, oriya, adi, oran, ";
        string actual = "";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    
}

TEST_CASE("Tree with string: K =2")
{
    Tree<string> tree;
    auto root_node = new Node<string>("shahar");
    tree.add_root(root_node);

    auto n1 = new Node<string>("raanan");
    auto n2 = new Node<string>("adi");
    auto n3 = new Node<string>("neta");
    auto n4 = new Node<string>("oriya");
    auto n5 = new Node<string>("oran");
    auto n6 = new Node<string>("shir");

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.add_sub_node(n2, n6);

    SUBCASE("Test 1: Preorder")
    {
        string expected = "shahar, raanan, neta, oriya, adi, oran, shir, ";
        string actual = "";
        for (auto node = tree.begin_preorder(); node != tree.end_preorder(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 2: Postorder")
    {
        string expected = "neta, oriya, raanan, oran, shir, adi, shahar, ";
        string actual = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 3: Inorder")
    {
        string expected = "neta, raanan, oriya, shahar, oran, adi, shir, ";
        string actual = "";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 4: BFS order")
    {
        string expected = "shahar, raanan, adi, neta, oriya, oran, shir, ";
        string actual = "";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 5: DFS order")
    {
        string expected = "shahar, raanan, neta, oriya, adi, oran, shir, ";
        string actual = "";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
}

TEST_CASE("Test with complex object: K = 2")
{
    Tree<Complex> tree;
    auto root_node = new Node<Complex>(Complex(1, 1));
    tree.add_root(root_node);

    auto n1 = new Node<Complex>(Complex(1, 2));
    auto n2 = new Node<Complex>(Complex(1, 3));
    auto n3 = new Node<Complex>(Complex(1, 4));
    auto n4 = new Node<Complex>(Complex(1, 5));
    auto n5 = new Node<Complex>(Complex(1, 6));
    // auto n6 = new Node<Complex>(Complex(1, 7));

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    // tree.add_sub_node(n2, n6);

    SUBCASE("Test 1: Preorder")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 3.000000i, 1.000000 + 6.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_preorder(); node != tree.end_preorder(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 2: Postorder")
    {
        std::string expected = "1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 2.000000i, 1.000000 + 6.000000i, 1.000000 + 3.000000i, 1.000000 + 1.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 3: Inorder")
    {

        std::string expected = "1.000000 + 4.000000i, 1.000000 + 2.000000i, 1.000000 + 5.000000i, 1.000000 + 1.000000i, 1.000000 + 6.000000i, 1.000000 + 3.000000i, "; ///////////
        std::string actual = "";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 4: BFS order")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 3.000000i, 1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 6.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 5: DFS order")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 3.000000i, 1.000000 + 6.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 6: minHeap order") ////////
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 3.000000i, 1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 6.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
}

TEST_CASE("Test with integer: K = 2")
{
    Tree<int> tree;
    auto root_node = new Node<int>(1);
    tree.add_root(root_node);

    auto n1 = new Node<int>(2);
    auto n2 = new Node<int>(3);
    auto n3 = new Node<int>(4);
    auto n4 = new Node<int>(5);
    auto n5 = new Node<int>(6);
    auto n6 = new Node<int>(7);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.add_sub_node(n2, n6);

    SUBCASE("Test 1: Preorder")
    {
        string expected = "1, 2, 4, 5, 3, 6, 7, ";
        string actual = "";
        for (auto node = tree.begin_preorder(); node != tree.end_preorder(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("Test 2: Postorder")
    {
        string expected = "4, 5, 2, 6, 7, 3, 1, ";
        string actual = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("Test 3: Inorder")
    {
        string expected = "4, 2, 5, 1, 6, 3, 7, ";
        string actual = "";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("Test 4: BFS order")
    {
        string expected = "1, 2, 3, 4, 5, 6, 7, ";
        string actual = "";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("Test 5: DFS order")
    {
        string expected = "1, 2, 4, 5, 3, 6, 7, ";
        string actual = "";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("Test 6: minHeap order") ////////
    {
        string expected = "1, 2, 3, 4, 5, 6, 7, ";
        string actual = "";
        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }
}

TEST_CASE("Test with complex object: K = 2")
{
    Tree<Complex> tree;
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
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.add_sub_node(n2, n6);

    SUBCASE("Test 1: Preorder")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 3.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_preorder(); node != tree.end_preorder(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 2: Postorder")
    {
        std::string expected = "1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 2.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, 1.000000 + 3.000000i, 1.000000 + 1.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 3: Inorder")
    {
        std::string expected = "1.000000 + 4.000000i, 1.000000 + 2.000000i, 1.000000 + 5.000000i, 1.000000 + 1.000000i, 1.000000 + 6.000000i, 1.000000 + 3.000000i, 1.000000 + 7.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 4: BFS order")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 3.000000i, 1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 5: DFS order")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 3.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 6: minHeap order") ////////
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 3.000000i, 1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
}

TEST_CASE("Test with string: K = 3")
{
    Tree<string, 3> tree;
    auto root_node = new Node<string>("a");
    tree.add_root(root_node);

    auto n1 = new Node<string>("b");
    auto n2 = new Node<string>("c");
    auto n3 = new Node<string>("d");
    auto n4 = new Node<string>("e");
    auto n5 = new Node<string>("f");
    auto n6 = new Node<string>("g");
    auto n7 = new Node<string>("h");
    auto n8 = new Node<string>("i");

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n1, n6);
    tree.add_sub_node(n3, n7);
    tree.add_sub_node(n3, n8);

    SUBCASE("Test 1: Preorder")
    {
        string expected = "a, b, e, f, g, c, d, h, i, ";
        string actual = "";
        for (auto node = tree.begin_preorder(); node != tree.end_preorder(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 2: Postorder")
    {
        string expected = "a, b, e, f, g, c, d, h, i, ";
        string actual = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 3: Inorder")
    {
        string expected = "a, b, e, f, g, c, d, h, i, ";
        string actual = "";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 4: BFS order")
    {
        string expected = "a, b, c, d, e, f, g, h, i, ";
        string actual = "";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 5: DFS order")
    {
        string expected = "a, b, e, f, g, c, d, h, i, ";
        string actual = "";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += (*node)->key + ", ";
        }
        CHECK(expected == actual);
    }
}

TEST_CASE("Test with integer: K = 3")
{
    Tree<int, 3> tree;
    auto root_node = new Node<int>(1);
    tree.add_root(root_node);

    auto n1 = new Node<int>(2);
    auto n2 = new Node<int>(3);
    auto n3 = new Node<int>(4);
    auto n4 = new Node<int>(5);
    auto n5 = new Node<int>(6);
    auto n6 = new Node<int>(7);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n1, n6);

    SUBCASE("Test 1: Preorder")
    {
        string expected = "1, 2, 5, 6, 7, 3, 4, ";
        string actual = "";
        for (auto node = tree.begin_preorder(); node != tree.end_preorder(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 2: Postorder")
    {
        string expected = "1, 2, 5, 6, 7, 3, 4, ";
        string actual = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 3: Inorder")
    {
        string expected = "1, 2, 5, 6, 7, 3, 4, ";
        string actual = "";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 4: BFS order")
    {
        string expected = "1, 2, 3, 4, 5, 6, 7, ";
        string actual = "";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 5: DFS order")
    {
        string expected = "1, 2, 5, 6, 7, 3, 4, ";
        string actual = "";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += to_string((*node)->key) + ", ";
        }
        CHECK(expected == actual);
    }
    
}

TEST_CASE("Test with complex object: K = 3")
{
    Tree<Complex, 3> tree;
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

    SUBCASE("Test 1: Preorder")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 5.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, 1.000000 + 3.000000i, 1.000000 + 4.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_preorder(); node != tree.end_preorder(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 2: Postorder")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 5.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, 1.000000 + 3.000000i, 1.000000 + 4.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 3: Inorder")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 5.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, 1.000000 + 3.000000i, 1.000000 + 4.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 4: BFS order")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 3.000000i, 1.000000 + 4.000000i, 1.000000 + 5.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
    SUBCASE("Test 5: DFS order")
    {
        std::string expected = "1.000000 + 1.000000i, 1.000000 + 2.000000i, 1.000000 + 5.000000i, 1.000000 + 6.000000i, 1.000000 + 7.000000i, 1.000000 + 3.000000i, 1.000000 + 4.000000i, ";
        std::string actual = "";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += (*node)->key.to_string() + ", ";
        }
        CHECK(expected == actual);
    }
}
