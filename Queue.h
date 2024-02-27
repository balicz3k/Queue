//
// Created by Jakub Balicki on 23/02/2024.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <iostream>

namespace que {
    template<typename Type>
    class Queue {
        struct Node {
            Type value;
            Node *next;
        };
        Node *p_front;
        Node *p_back;
        unsigned int q_size;
    public:
        Queue();

        explicit Queue(const Type &val);

        Queue(const Queue<Type> &Q);

        void push(const Type &val);

        void pop();

        Type front();

        bool empty(){return q_size==0;};

        unsigned int size(){return q_size;};

        Queue & operator=(const Queue &Q);

        friend std::ostream& Queue<Type>::operator<<(std::ostream &os, const Queue<Type> &Q);

        ~Queue();
    };

    template<typename Type>
    std::ostream& Queue<Type>::operator<<(std::ostream &os, const Queue<Type> &Q) {
        auto tmp = Q.p_front;
        os << '[';
        while (tmp) {
            if (!tmp->next) {
                os << tmp->value;
            } else os << tmp->value << ", ";
            tmp = tmp->next;
        }
        os << ']';
        return os;
    }

    template<typename Type>
    Queue<Type> &Queue<Type>::operator=(const Queue &Q) {
        while(this->q_size)
            this->pop();
        auto tmp = Q.p_front;
        while(tmp){
            this->push(tmp->value);
            tmp = tmp->next;
        }
        return *this;
    }

    template<typename Type>
    Queue<Type>::Queue() {
        q_size=0;
        p_front = nullptr;
        p_back = nullptr;
    }

    template<typename Type>
    Queue<Type>::Queue(const Type &val) {
        p_front = new Node{val, nullptr};
        p_back = p_front;
        q_size=1;
    }

    template<typename Type>
    Queue<Type>::Queue(const Queue<Type> &Q) {
        q_size=0;
        *this=Q;
    }

    template<typename Type>
    void Queue<Type>::push(const Type &val) {
        if(!q_size){
            p_front = new Node{val,nullptr};
            p_back=p_front;
        }
        else {
            Node *tmp = new Node{val, nullptr};
            p_back->next = tmp;
            p_back = tmp;
        }
        q_size++;
    }

    template<typename Type>
    void Queue<Type>::pop() {
        Node *tmp=p_front->next;
        delete p_front;
        p_front = tmp;
        --q_size;
        if(!q_size)
            p_front = p_back = nullptr;
    }

    template<typename Type>
    Type Queue<Type>::front() {
        if(!this->empty())
            return p_front->value;
        exit(-1);
    }

    template<typename Type>
    Queue<Type>::~Queue() {
        while(q_size){
            Node *tmp=p_front->next;
            delete p_front;
            p_front = tmp;
            --q_size;
        }
    }
}

#endif //QUEUE_QUEUE_H
