#include <iostream>
#include "Queue.h"

#include <queue>



int main() {
    que::Queue<int>Q1{5};
    que::Queue<int>Q2(123);
    std::cout<<"Queue1: "<<Q1<<'\n'<<"Queue2: "<<Q2<<'\n';
    Q1.push(321);
    Q2=Q1;//deep copy
    Q2=Q2;
    std::cout<<"Queue1: "<<Q1<<'\n'<<"Queue2: "<<Q2<<'\n';
}