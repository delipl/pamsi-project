#pragma once
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>

namespace pamsi {

template <typename T>
class List;

template <typename T>
class Node {
    public:
     Node(const T &elem)
         : elem{elem} {};

    private:
     T elem;
     std::shared_ptr<Node<T>> next;
     std::shared_ptr<Node<T>> prev;
     friend class List<T>;
};


template <typename T>
class List {
   public:
    List() = default;
    // List(std::initializer_list<Node> &list){

    // };
    std::size_t size() const {
        std::shared_ptr<Node<T>> ptr = head;

        std::size_t size = 0;
        while (ptr != nullptr) {
            ++size;
            ptr = ptr->prev;
        }
        return size;
    }

    void push_back(const T &elem){
        if(tail == nullptr){
            tail = std::make_shared<Node<T>>(elem);
            head = tail;
        } else {
            tail->prev = std::make_shared<Node<T>>(elem);
            tail->prev->next = tail;
            tail = tail->prev;
        }
    }
    void push_front(const T &elem) {
        if (head == nullptr) {
            head = std::make_shared<Node<T>>(elem);
            tail = head;
        } 
        else {
            std::shared_ptr<Node<T>> ptr = 
            head->next = std::make_shared<Node<T>>(elem);
            head->next->prev = head;
            head = head->next;
        }
    }

    T &front() {
        if(head == nullptr){
            throw std::overflow_error("List is empty");
        }
        return head->elem;
    }

    T &back() {
        if (head == nullptr) {
            throw std::underflow_error("List is empty");
        }
        return tail->elem;
    }

   private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};

}  // namespace pamsi