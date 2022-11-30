#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
//��悸�l�b�g�Œ��ׂ����@�ŃR�[�h������(�ꕔ�����̏㗬�p)
namespace MCB
{
    template <class T>
    class Cell //list��1�v�f(Cell�j�p�̒�`
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
    class List //List�N���X
    {
    private:
        Cell<T>* dummy = {};//���ۂɃf�[�^������悤�ł͂Ȃ��Anext�Ő擪�v�f�ւ̃|�C���^�Aprev�Ŗ����v�f�ւ̃|�C���^�������Ă����悤�ɂ��邽�߂̕�
        int size;//�v�f��
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

        inline void Add(T v, Cell<T>* node)//�v�f�̒ǉ�
        {
            //�����œn���ꂽ�m�[�h�Ǝ��̃m�[�h�̊ԂɐV���Ƀm�[�h��ǉ��B
            Cell<T>* newNode = new Cell<T>(v, node, node->next);//malloc()��C++�ł͔񐄏��Ƃ����ӌ����l�b�g�ɂ���A���g������Ă��Ȃ����߁Anew�Ő���        //�����œn���ꂽ�m�[�h�̎��̃m�[�h��prev�̑Ώۂ�}�������m�[�h�ɕύX
            node->next->prev = newNode;
            //�����œn���ꂽ�m�[�h��next�̑Ώۂ�}�������m�[�h�ɕύX
            node->next = newNode;
            //�����œn���ꂽ�m�[�h���X�V
            node = newNode;
            size++;
        }
        inline void PushFront(T value)//�擪�ɑ}��
        {
            Cell<T>* cur = dummy;
            Add(value, cur);
        }
        inline void PushBack(T value)//�����ɑ}��
        {
            Cell<T>* cur = dummy->prev;
            Add(value, cur);
        }
        inline bool Empty()//�v�f��������
        {
            return dummy->next == dummy;
        }

        inline Cell<T>* GetNodeAddress(int itr)
        {
            if (Empty()) return nullptr;
            Cell<T>* address = dummy->next;//�擪�ւ̃A�h���X
            if (itr >= size) return dummy->prev;
            for (int i = 0; i < itr; i++)
            {
                if (address == dummy->prev)//�����ɓ��B���Ă�����
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

        inline T Remove(Cell<T>* node)//�v�f�̎擾�ƈړ�
        {
            if (Empty())
            {
                cout << "error! List is enpty!" << endl;
                //int temp = 0 / 1;
                return dummy->value;//dummy->value�����^�[������error������
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

                cout << num << ":\"" << ptr->value << "\"" << endl;//�e���v���[�g�̃t�H�[�}�b�g�w��q���킩��Ȃ������̂ŁA�l�b�g����E���Ă������@�ŕ`��
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

