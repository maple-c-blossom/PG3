#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
//一先ずネットで調べた方法でコードを書く(一部理解の上流用)
namespace MCB
{
    template <class T>
    class Cell //listの1要素(Cell）用の定義
    {
    public:
        T value;
        Cell* prev;
        Cell* next;
        Cell()
        {
            prev = this;
            next = this;
        }
        Cell(T value, Cell* prev, Cell* next)
        {
            this->value = value;
            this->prev = prev;
            this->next = next;
        }
    };
    template <class T>
    class List //Listクラス
    {
    private:
        Cell<T>* dummy = {};//実際にデータを入れるようではなく、nextで先頭要素へのポインタ、prevで末尾要素へのポインタを持ってこれるようにするための物
        int size;//要素数
    public:
        List()
        {
            dummy = new Cell<T>();
            size = 0;
        }
        ~List()
        {
            Clear();
            delete dummy;
        }

        inline void Add(T v, Cell<T>* node)//要素の追加
        {
            //引数で渡されたノードと次のノードの間に新たにノードを追加。
            Cell<T>* newNode = new Cell<T>(v, node, node->next);//malloc()はC++では非推奨という意見がネットにあり、かつ使い慣れていないため、newで生成        //引数で渡されたノードの次のノードのprevの対象を挿入したノードに変更
            node->next->prev = newNode;
            //引数で渡されたノードのnextの対象を挿入したノードに変更
            node->next = newNode;
            //引数で渡されたノードを更新
            node = newNode;
            size++;
        }
        inline void PushFront(T value)//先頭に挿入
        {
            Cell<T>* cur = dummy;
            Add(value, cur);
        }
        inline void PushBack(T value)//末尾に挿入
        {
            Cell<T>* cur = dummy->prev;
            Add(value, cur);
        }
        inline bool Empty()//要素が無いか
        {
            return dummy->next == dummy;
        }

        inline Cell<T>* GetNodeAddress(int itr)
        {
            if (Empty()) return nullptr;
            Cell<T>* address = dummy->next;//先頭へのアドレス
            if (itr >= size) return dummy->prev;
            for (int i = 0; i < itr; i++)
            {
                if (address == dummy->prev)//末尾に到達していたら
                {
                    break;
                }
                else
                {
                    address = address->next;
                }
            }
            return address;
        }

        inline T Remove(Cell<T>* node)//要素の取得と移動
        {
            if (Empty())
            {
                cout << "error! List is enpty!" << endl;
                //int temp = 0 / 1;
                return dummy->value;//dummy->valueをリターンしてerror扱いに
            }
            T ret = node->value;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            //node = node->prev;
            size--;
            return ret;
        }

        inline void Delete(Cell<T>* node)
        {
            if (Empty())
            {
                cout << "error! List is enpty!" << endl;
                return;
            }
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
          
            size--;
        }
        inline T PopFront()
        {
            Cell<T>* cur = dummy->next;
            return Remove(cur);
        }

        inline T PopBack()
        {
            Cell<T>* cur = dummy->prev;
            return Remove(cur);
        }
        inline void AllPrint()
        {
            if (Empty())
            {
                cout << "error! List is enpty! Return is inf" << endl;
                return;
            }
            Cell<T>* ptr = dummy->next;
            int num = 0;
            while (ptr != dummy)
            {

                cout << num << ":\"" << ptr->value << "\"" << endl;//テンプレートのフォーマット指定子がわからなかったので、ネットから拾ってきた方法で描画
                ptr = ptr->next;
                num++;
            }
            cout << '\n';
        }

        inline void Clear()
        {
            while (!Empty())
            {
                PopFront();
            }
        }

        inline int Size()
        {
            return size;
        }
    };
}

