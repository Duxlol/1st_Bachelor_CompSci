//
// Created by kali on 12/19/24.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H



class ArrayList {
public:
    ArrayList(int capacity);
    ArrayList();
    ~ArrayList();

    void clearList();
    bool isEmpty() const;
    int getSize() const;
    bool set(int index, int value);
    bool get(int index,int& item) const;
    bool del(int index);
    void doubleCapacity();
    void add(int newItem);
    void insert(int index, int newItem);
    void print() const;

private:
    int* items;
    int size;
    int capacity;
};



#endif //ARRAYLIST_H
