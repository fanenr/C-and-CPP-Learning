#include <iostream>
#include <memory>
#include <string>
#include <vector>

class HashMap {
private:
    int size;
    // max size of the bucket
    int size_max;
    // map element struct
    struct Node {
        int index;
        std::string data;
        std::shared_ptr<Node> next;
        Node(int in, const std::string& da)
        {
            index = in;
            data = da;
            next = nullptr;
        }
    };
    // maintain map index bucket
    using node = std::shared_ptr<Node>;
    std::vector<node> bucket;

    // hash function to get key
    int hash(int key)
    {
        return key % size_max;
    }

    node newn(int index, const std::string& str)
    {
        return std::make_shared<Node>(index, str);
    }

public:
    HashMap(int size = 10)
        : size(0)
        , size_max(size)
        , bucket(size_max, nullptr)
    {
    }

    // find element by index
    node find(int index)
    {
        node root = bucket[hash(index)];
        while (root != nullptr) {
            if (root->index == index)
                return root;
            root = root->next;
        }
        return nullptr;
    }

    // push function to push new element
    node push(int index, const std::string& data)
    {
        // return null if index existed
        if (find(index) != nullptr)
            return nullptr;

        node temp = newn(index, data);
        node root = bucket[hash(index)];

        if (root == nullptr)
            return bucket[hash(index)] = temp;

        while (root != nullptr)
            root = root->next;

        size++;
        return root->next = temp;
    }
};

int main(void)
{
    HashMap map = HashMap();
    map.push(1, "wufan");
    auto n = map.find(1);
    auto n2 = map.find(2);
    std::cout << n->data << std::endl;

    if (n2 == nullptr)
        std::cout << "null";
}