#ifndef HASHNODE_HPP
#define HASHNODE_HPP

template <typename T>
class HashNode {
public:
    HashNode(int key, const T& value) : key(key), value(value) {

    }

    bool empty() const {
        return key == -1;
    }

    bool deleted() const {
        return key == -2;
    }
    
    int key;
    T value;
};

#endif 