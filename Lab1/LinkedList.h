#pragma once

typedef int value_type;
class LinkedList {
/*********Node of linked list**********/

    //Main struct of linked list
    class Node {
    public:
        Node();
        Node(value_type);
        Node(Node* inputPrev, Node* inputNext, value_type inputValue);
        value_type value;
        Node* next;
        Node* prev;
    };

/*********Fields of linked list**********/

    //Node before head and after tail
    Node head;
    int len;

/*********Iterator**********/

    //Iterators allow handle with elements of linked list
    class iterator {
        Node* currentNode;
    public:
        iterator();

        //Copy assigment
        iterator& operator=(const iterator& other);
        //Logical negation of ==
        bool operator!=(const iterator& other) const;
        //Return true if index on one node
        bool operator==(const iterator& other) const;
        
        //Operator returns reference to element of linked list
        value_type& operator*();
        //Operator returns pointer to element of linked list
        value_type* operator->();

        //Operator moves iterator to next position in linked list and after gives access to element
        iterator& operator++();
        //Operator gives access to element and after moves iterator to next position in linked list
        iterator operator++(int);
        //Operator moves iterator to previous position in linked list and after gives access to element
        iterator& operator--();
        //Operator gives access to element and after moves iterator to next position in linked list
        iterator operator--(int);

        friend LinkedList;
    };

/*********Const iterator**********/

    //Const iterators have all functoins of iterators but don't allow data modification
    class const_iterator {
        Node* currentNode;
    public:
        const_iterator();

        //Copy assigment
        const_iterator& operator=(const const_iterator& other);
        //Logical negation of ==
        bool operator!=(const const_iterator& other) const;
        //Return true if index on one node
        bool operator==(const const_iterator& other) const;

        //Operator returns reference to element of linked list
        const value_type& operator*() const;
        //Operator returns pointer to element of linked list
        const value_type* operator->() const;

        //Operator moves iterator to next position in linked list and after gives access to element
        const_iterator& operator++();
        //Operator gives access to element and after moves iterator to next position in linked list
        const_iterator operator++(int);
        //Operator moves iterator to previous position in linked list and after gives access to element
        const_iterator& operator--();
        //Operator gives access to element and after moves iterator to next position in linked list
        const_iterator operator--(int);

        friend LinkedList;
    };
public:

/*********Constructors**********/

    //Default constructor
    LinkedList();
    //Copy constructor
    LinkedList(const LinkedList& other);
    //Move constructor
    LinkedList(LinkedList&& other) noexcept;

/*********Destructors**********/

    //Copy assigment
    LinkedList& operator=(const LinkedList& other);
    //Move assigment
    LinkedList& operator=(LinkedList&& other) noexcept;


/*********Destructors**********/

    //Destructor
    ~LinkedList();

/*********Accsess to iterators**********/

    //Returns iterator to first node of linked list
    iterator begin();
    //Returns const_iterator to first node of linked list if list is const
    const_iterator begin() const;
    //Returns const_iterator
    const_iterator cbegin() const;

    //Returns iterator to node after last node of linked list
    iterator end();
    //Returns const_iterator to node after last node of linked list if list is const
    const_iterator end() const;
    //Returns const_iterator to node after last node of linked list
    const_iterator cend() const;

/*********Size methods**********/

    //Returns size of linked list
    int size() const;
    //Returns true if list is empty
    bool empty() const;

/*********Accsess to elements**********/

    //returns reference to first element
    value_type& front();
    //returns const reference to first element
    const value_type& front() const;
    //returns reference to last element
    value_type& back();
    //returns const reference to last element
    const value_type& back() const;

/*********Modificators**********/

    //Deletes iterator's node
    iterator erase(iterator position);
    //Deletes nodes in [begin, end)
    iterator erase(iterator begin, iterator end);
    //Deletes all enters of value in linked list
    int remove(const value_type& value);
    //Delete all list
    void clear();

    //Delete back element
    void pop_back();
    //Delete front element
    void pop_front();
    //Add value to back of linked list
    void push_back(const value_type& value);
    //Add value to front of linked list
    void push_front(const value_type& value);
    //Insert value before iterator
    iterator insert(iterator before, const value_type& value);

/*********Inside operators**********/

    //Concat lists
    LinkedList& operator+=(const LinkedList& other);

/*********Outside operators**********/

    friend bool operator!=(const LinkedList& left, const LinkedList& right);
    friend bool operator==(const LinkedList& left, const LinkedList& right);

};

//Logical negation of ==
bool operator!=(const LinkedList& left, const LinkedList& right);
//Returns true if value and order are same in linked lists
bool operator==(const LinkedList& left, const LinkedList& right);
