#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include <iostream>
#include <memory>

namespace structures
{
    namespace once_linked
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

        template <typename T>
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
                }
                tail->next() = p;
                tail = p;
            }

            [[noreturn]] void print()
            {
                if (is_empty()) throw std::runtime_error("list is empty");
                auto p = this->root;
                while (p) {
                    std::cout << p->data() << " ";
                    p = p->next();
                }
                std::cout << std::endl;
            }

            std::shared_ptr<node<T>> at(T _val)
            {
                std::shared_ptr<node<T>> p = this->root;
                while (p && p->data() != _val) p = p->next();
                return p && p->data() == _val ? p : nullptr;
            }

            [[noreturn]] void pop_front()
            {
                if (is_empty()) throw std::runtime_error("list is empty");
                std::shared_ptr<node<T>> p = this->root;
                this->root = p->next();
                p.reset();
            }

            [[noreturn]] void pop_back()
            {
                if (is_empty()) throw std::runtime_error("list is empty");
                if (this->root == this->tail) {
                    pop_front();
                }

                std::shared_ptr<node<T>> p = this->root;
                while (p->next() != this->tail) p = p->next();
                p->next() = nullptr;
                this->tail.reset();
                this->tail = p;
            }

            [[noreturn]] void erase(T _val)
            {
                if (is_empty()) throw std::runtime_error("list is empty");
                if (this->root->data() == _val) {
                    pop_front();
                } else if (this->tail->data() == _val) {
                    pop_back();
                }

                std::shared_ptr<node<T>> pr = this->root;
                std::shared_ptr<node<T>> prn = this->root->next();

                while (prn && prn->data() != _val) {
                    prn = prn->next();
                    pr = pr->next();
                }
                if (!prn) {
                    throw std::runtime_error("element does not exist");
                }
                pr->next() = prn->next();
                prn.reset();
            }

        private:
            std::shared_ptr<node<T>> root;
            std::shared_ptr<node<T>> tail;
        };
    }
    namespace double_linked
    {
        template<typename T>
        class node {
        public:
            explicit node() = default;
            explicit node(T value) : data_(value), next_(nullptr) {}
            T& data() { return this->data_; }
            std::shared_ptr<node>& next() { return this->next_; }
            std::shared_ptr<node>& prev() { return this->prev_; }
        private:
            T data_;
            std::shared_ptr<node> next_, prev_;
        };

        template<typename T>
        class linked_list {
        public:
            explicit linked_list() : root(nullptr), tail(nullptr) {}

            [[noreturn]] void push_front(T _val)
            {
                std::shared_ptr<node<T>> p = std::make_shared<node<T>>(_val);
                p->next() = this->root;
                if (this->root != nullptr) this->root->prev() = p;
                if (this->tail == nullptr) this->tail = p;
                this->root = p;
            }

            [[noreturn]] void push_back(T _val)
            {
                std::shared_ptr<node<T>> p = std::make_shared<node<T>>(_val);
                p->prev() = this->tail;
                if (this->tail != nullptr) this->tail->next() = p;
                if (this->root == nullptr) this->root = p;
                this->tail = p;
            }

            std::shared_ptr<node<T>> pop_front()
            {
                if (this->root == nullptr) return nullptr;

                std::shared_ptr<node<T>> p = this->root->next();
                if (p != nullptr) p->prev() = nullptr;
                else this->tail = nullptr;
                this->root = p;
                return p;
            }

            std::shared_ptr<node<T>> pop_back()
            {
                if (this->tail == nullptr) return nullptr;

                std::shared_ptr<node<T>> p = this->tail->prev();
                if (p != nullptr) p->next() = nullptr;
                else this->root = nullptr;
                this->tail = p;
                return p;
            }

            std::shared_ptr<node<T>> at(const int index)
            {
                std::shared_ptr<node<T>> p = this->root;
                for (int i = 0; i != index; i++) {
                    if (p == nullptr) return p;
                    p = p->next();
                }
                return p;
            }

            std::shared_ptr<node<T>> operator[](const int index)
            {
                return this->at(index);
            }

            [[noreturn]] void erase(const int index)
            {
                auto p = this->at(index);

                if (p == nullptr) throw std::runtime_error("element does not exist");
                if (p->prev() == nullptr) {
                    pop_front();
                }

                if (p->next() == nullptr) {
                    pop_back();
                }

                auto left = p->prev();
                auto right = p->next();
                left->next() = right;
                right->prev() = left;

                p.reset();
            }

            [[noreturn]] void insert(const T _val, const int index)
            {
                auto right = at(index);
                if (right == nullptr) {
                    push_back(_val);
                }

                auto left = right->prev();
                if (left == nullptr) {
                    push_front(_val);
                }

                auto p = std::make_shared<node<T>>(_val);
                p->prev() = left;
                p->next() = right;
                left->next() = p;
                right->prev() = p;
            }

            [[noreturn]] void print()
            {
                if (this->root == nullptr) throw std::runtime_error("list is empty")
                auto p = this->root;
                while (p) {
                    std::cout << p->data() << " ";
                    p = p->next();
                }
                std::cout << std::endl;
            }
        private:
            std::shared_ptr<node<T>> root;
            std::shared_ptr<node<T>> tail;
        };
    }
}

#endif //STRUCTURES_HPP
