#include "linked_list.h"

using namespace std;

int main()
{    
    try
    {
        LinkedList<int> list;
     
        list.push(20);
        list.push(17);
        list.push(13);
        list.push(11);
        list.push(11);
        list.push(10);
     
        cout<<"La lista es: "<<endl;
        list.print();


        cout<<"Dado un numero, devuelve las veces que aparece en la lista"<<endl;
        list.Count(11);
        

        Node<int> *newNode = new Node<int>(12, NULL);
        cout<<"Sorted, dado un numero lo acomoda en el orden que va"<<endl;
        list.SortedInsert(newNode);
        list.print();

        //cout<<"Remueve duplicados"<<endl;
        //list.RemoveDuplicates();

        cout<<"Invierte la lista"<<endl;
        list.Reverse();



    
        for (size_t i = 0; i < list.length(); i++)
        {
            int item;
            list.get_nth(i, item);
            cout << item << ", ";
        }
        cout << endl;        
    }


    catch(const char* e)
    {
        std::cerr << "ERROR caught: " << e << std::endl;
    }


    return 0;
}