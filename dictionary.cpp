//
// Created by 30884 on 2025/2/18.
//

#include <iostream>
#include "dictionary.h"

using namespace std;

template <typename K,typename V>
Dictionary<K,V>::Dictionary(){
    this->size_array = 0;
    this->maxSize = 50;
    this->array = new pairs[50];
};

template<typename K, typename V>
Dictionary<K, V>::~Dictionary() = default;

template<typename K, typename V>
int Dictionary<K, V>::size() const{
    return this->size_array;
}

template<typename K, typename V>
void Dictionary<K, V>::doubleSize(){
    pairs *temp = new pairs[this->maxSize*2];
    for(int i = 0;i < this->size();++i){
        temp[i] = this->array[i];
    }
    this->array = temp;
    this->maxSize *= 2;
}

template<typename K, typename V>
V Dictionary<K, V>::get(K key) const {
    if(this->size() == 0){
        return NULL;
    }
    for(int i = 0;i < this->size_array;++i){
        if(key == this->array[i].key){
            return this->array[i].value;
        }
    }
    return NULL;
}

template<typename K, typename V>
bool Dictionary<K, V>::put(K key, V value) {
    if(this->maxSize == this->size_array){
        doubleSize();
    }
    if(this->get(key) == NULL){
        this->array[size_array].key = key;
        this->array[size_array].value = value;
        this->size_array ++;
        return true;
    }
    return false;
}

template<typename K, typename V>
bool Dictionary<K, V>::remove(K key) {
    if(this->get(key) == NULL){
        return false;
    }
    int i;
    for(i = 0;i < this->size_array;++i){
        if(key == this->array[i].key){
            break;
        }
    }
    for(int pos = i;pos < this->size_array - 1;++pos){
        this->array[pos].key = this->array[pos+1].key;
        this->array[pos].value = this->array[pos+1].value;
    }
    this->size_array -- ;
    return true;
}

template<typename K, typename V>
void Dictionary<K, V>::printAll() const {
    if(this->size() == 0){
        cout<<"Empty dictionary!"<<endl;
        return;
    }
    cout<<"Dictionary:totally "<<this->size()<<" keys:"<<endl;
    cout<<"KEYS\tVALUES"<<endl;
    for(int i = 0;i < this->size_array;++i){
        cout<<this->array[i].key<<'\t'<<this->array[i].value<<endl;
    }
}
