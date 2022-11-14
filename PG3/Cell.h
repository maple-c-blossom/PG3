#pragma once
//#include <stdio.h>
//#include <stdlib.h>
//
//template<class T>
//class Cell
//{
//private:
//	T val;
//	Cell* prev = nullptr;
//	Cell* next = nullptr;
//public:
//	
//};

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
template <class T>
class Node //Cell単体のクラス
{
private:
    T value;
    Node* prev;
    Node* next;
public:
    template<class T>
    inline Node<T>::Node()
    {
        {
            this->prev = this;
            this->next = this;
        }
    }

    template<class T>
    inline Node<T>::Node(T value, Node* prev, Node* next)
    {
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};
template <class T>
class List
{
private:
    Node<T>* dummy;
    int size;
public:
    List()
    {
        dummy = new Node<T>();
        size = 0;
    }
    ~List()
    {
        clear();
    }

    void Add(T v, Node<T>* node)
    {
        //引数で渡されたノードと次のノードの間に新たにノードを追加。
        Node<T>* newNode = new Node<T>(v, node, node->next_);
        //次のノードのprevの対象を挿入したノードに変更
        node->next->prev = newNode;
        //ノードのnextの対象を挿入したノードに変更
        node->next = newNode;
        //引数で渡されたノードを更新
        node = newNode;
        size_++;
    }
    void PushFront(T value);
        //{
        //    Node<T>* cur = dummy_;
        //    add(value, cur);
        //}
    void PushBack(T value);
        //{
        //    Node<T>* cur = dummy_->prev_;
        //    add(value, cur);
        //}
    bool Empty();
    //{
    //    return dummy_->next_ == dummy_;
    //}

    T Remove(Node<T>* node)
    {
        if (empty())
        {
            throw std::logic_error("node is empty!");
        }
        T ret = node->value;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        node = node->prev;
        size--;
        return ret;
    }
    T Pop_front()
    {
        Node<T>* cur = dummy->next;
        return Remove(cur);
    }

    T Pop_back()
    {
        Node<T>* cur = dummy->prev;
        return Remove(cur);
    }
    void Dump()
    {
        Node<T>* ptr = dummy->next;
        while (ptr != dummy)
        {
            //cout << ptr->value << ' ';
            ptr = ptr->next;
        }
        printf("\n");
    }

    void Clear()
    {
        while (!Empty())
        {
            Pop_front();
        }
    }

    int Size()
    {
        return size;
    }
};


