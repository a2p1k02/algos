#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include <iostream>
#include <memory>

namespace structures
{
    template<typename T>
    class node {
    public:
        explicit node() = default;
        explicit node(T value) : data_(value), next_(nullptr) {}
        T& data() { return this->data_; }
        std::shared_ptr<node>& next() { return this->next_; }
    private:
        T data_;
        std::shared_ptr<node> next_;
    };

    template<typename T>
    class linked_list {
    public:
        explicit linked_list() : root(nullptr), tail(nullptr) {}

        bool is_empty()
        {
            return root == nullptr;
        }

        [[noreturn]] void push_back(T _val)
        {
            std::shared_ptr<node<T>> p = std::make_shared<node<T>>(_val);
            if (is_empty()) {
                root = p;
                tail = p;
                return;
            }
            tail->next() = p;
            tail = p;
        }

        [[noreturn]] void print()
        {
            if (is_empty()) return;
            auto p = this->root;
            while (p) {
                std::cout << p->data() << " ";
                p = p->next();
            }
            std::cout << std::endl;
        }

        std::shared_ptr<node<T>> find(T _val)
        {
            std::shared_ptr<node<T>> p = this->root;
            while (p && p->data() != _val) p = p->next();
            return p && p->data() == _val ? p : nullptr;
        }

        [[noreturn]] void remove_first()
        {
            if (is_empty()) return;
            std::shared_ptr<node<T>> p = this->root;
            this->root = p->next();
            p.reset();
        }

        [[noreturn]] void remove_last()
        {
            if (is_empty()) return;
            if (this->root == this->tail) {
                remove_first();
                return;
            }

            std::shared_ptr<node<T>> p = this->root;
            while (p->next() != this->tail) p = p->next();
            p->next() = nullptr;
            this->tail.reset();
            this->tail = p;
        }

        [[noreturn]] void remove(T _val)
        {
            if (is_empty()) return;
            if (this->root->data() == _val) {
                remove_first();
                return;
            } else if (this->tail->data() == _val) {
                remove_last();
                return;
            }

            std::shared_ptr<node<T>> pr = this->root;
            std::shared_ptr<node<T>> prn = this->root->next();

            while (prn && prn->data() != _val) {
                prn = prn->next();
                pr = pr->next();
            }
            if (!prn) {
                throw std::exception("element does not exist");
            }
            pr->next() = prn->next();
            prn.reset();
        }
    private:
        std::shared_ptr<node<T>> root;
        std::shared_ptr<node<T>> tail;
    };
}

#endif //STRUCTURES_HPP
