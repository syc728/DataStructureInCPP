template <class T> class LinkedList;
template <class T>
class Node
{
private:
    T data;
    Node* next;
    Node():next(nullptr){}
    Node(const T data, Node<T>* next = nullptr):data(data), next(next){}
    ~Node(){ next = nullptr; }
    friend class LinkedList<T>;
public:
    T getData();
};

template <class T>
T Node<T>::getData()
{
    return data;
}