//
// Created by 30884 on 2025/2/18.
//

#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H
#define initialSize 50

template <typename K,typename V>
class Dictionary{
private:
    struct pairs{
        K key;
        V value;
    };
    pairs *array;
    int size_array;
    int maxSize;
public:

    Dictionary();
    ~Dictionary();

    int size()const;
    void doubleSize();
    V get(K key)const;
    void printAll()const;
    bool put(K key,V value);
    bool remove(K key);
};



#endif //DICTIONARY_DICTIONARY_H
