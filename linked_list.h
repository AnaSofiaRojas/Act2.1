#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stddef.h>
#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
    T val;
    Node<T> *next;

public:
    ~Node<T>() {};
    Node<T>(T pVal, Node<T> *pNext)
    {
        val = pVal;
        next = pNext;
    };

    T get_val() {return val;};
    void set_val(T pVal) {val = pVal;};
    Node<T> *get_next() {return next;};
    void set_next(Node<T> *pNext) {next = pNext;};
};

template <class T>
class LinkedList
{
protected:
    Node<T> *head;

public:
    ~LinkedList(){};
    LinkedList()
    {
        head = NULL;
    };

    int length()
    {
        int length = 0;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->get_next();
        }
        return length;
    };


    void print()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            std::cout << ptr->get_val() << ", ";
            ptr = ptr->get_next();
        }
        std::cout << std::endl;        
    }


    void push(T pVal)
    {
        Node<T> *node = new Node<T>(pVal, head);
        head = node;
    };


    void append(T pVal)
    {
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL)
        {
            ptr = ptr->get_next();
        }
        Node<T> *node = new Node<T>(pVal, NULL);
        ptr->set_next(node);
    };


    int insert_item(T pVal, int index)
    {
        if (index > length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            push(pVal);
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        Node<T> *node = new Node<T>(pVal, ptr);
        pre->set_next(node);
        return 1;
    };


    bool is_empty()
    {        
        return head == NULL;
    };


    int delete_item(int index)
    {
        if (is_empty())
            return -1;
        if (index >= length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            Node<T> *temp = head;
            head = head->get_next();
            delete temp;
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr->get_next() != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        pre->set_next(ptr->get_next());
        delete ptr;
        return 1;
    };


    int get_nth(int index, T &item)
    {
        if (index < 0)
            return -1;
        if (index >= length())
            return -2;
            
        int i = 0;
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL && index > i)
        {
            ptr = ptr->get_next();
            i++;
        }
        item = ptr->get_val();
        return 1;
    };

    //COUNT


    int Count(T searchFor)
    {
        int counter=0;
        int length=0;
        Node<T> *ptr = head;
        while(ptr != NULL)
        {
            if (ptr->get_val()==searchFor)
            {
                counter ++;
            }
            length++;
            ptr=ptr->get_next();
        }


        cout <<"Numero dado:"<<endl;
        cout<<searchFor << endl;
        cout<<"Las veces que aparece son: "<<endl;
        cout<< counter<< endl;
        return counter;
    };

    //delete list

    void DeleteList()
    {
        Node<T> *ptr = head;
        Node<T> *_ptr=NULL;
        
        while(ptr->get_next()!=NULL)
        {
            _ptr=ptr;
            ptr=ptr->get_next();
            delete _ptr;
            
        }

        if (ptr!=NULL)
        {
            delete ptr;
        }

        head=NULL;
             
    };

    //sorted

    void SortedInsert(Node<T> *newNode)
    {
        Node<T> *ptr = head;
        if(ptr->get_val() > newNode->get_val())
        {
            newNode->set_next(ptr);
            head = newNode;
        }
        else
        {
            while(ptr->get_next() != NULL)
            {
                if(newNode->get_val()<ptr->get_next()->get_val())
                {
                    newNode->set_next(ptr->get_next());
                    ptr->set_next(newNode);
                    break;
                }
                ptr = ptr->get_next();
            } 
            if(ptr->get_next() == NULL)
                ptr->set_next(newNode);
        }
    };


    //remove duplicates
    void RemoveDuplicates()
    {
        int i = 0;
        Node<T> *ptr = head;
        Node<T> *sig;
        while (ptr != NULL)
        {
            sig = ptr->get_next();
            if(sig->get_val() == ptr->get_val())
            {
                ptr = sig;
                delete_item(i);
            }
            ptr = ptr->get_next();
            i++;
        }
    };

    //reverse

    void Reverse()
    {
        if(head == NULL)
        return;
        Node<T> *ptr = head->get_next();
        Node<T> *_ptr = head;
        while (ptr != NULL) 
        {
            _ptr->set_next(ptr->get_next());
            ptr->set_next(head);
            head = ptr;
            ptr = _ptr->get_next();
        }
    };
 

};

#endif