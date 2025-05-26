#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <memory>
#include <stdexcept>
#include <vector>
#include <functional>

namespace algos
{
    template<typename K, typename V>
    class h_node {
    public:
        explicit h_node(const K& k, const V& v) : key_(k), value_(v), next_(nullptr) {}
        std::unique_ptr<h_node>& next() { return next_; }
        K& key() { return key_; }
        V& value() { return value_; }
    private:
        K key_;
        V value_;
        std::unique_ptr<h_node> next_;
    };

    template<typename K, typename V>
    class hash_table {
    public:
        explicit hash_table(size_t bucket_count = 100) : buckets(bucket_count), size(0) {}

        void insert(const K& key, const V& value)
        {
            size_t index = get_index(key);
            auto current = buckets[index].get();
            while (current) {
                if (current->key() == key) {
                    current->value() = value;
                    return;
                }
                current = current->next().get();
            }
            auto new_node = std::make_unique<h_node<K, V>>(key, value);
            new_node->next() = std::move(buckets[index]);
            buckets[index] = std::move(new_node);
            ++size;
        }

        bool find(const K& key, V& value) const 
        {
            size_t index = get_index(key);
            auto current =  buckets[index].get();

            while (current) {
                if (current->key() == key) {
                    value = current->value();
                    return true;
                }
                current = current->next().get();
            }
            return false;
        }

        V& get(const K& key) const 
        {
            size_t index = get_index(key);
            auto current =  buckets[index].get();

            while (current) {
                if (current->key() == key) {
                    return current->value();
                }
                current = current->next().get();
            }
            throw std::out_of_range("key not found");
        }

        bool remove(const K& key)
        {
            size_t index = get_index(key);
            auto current =  buckets[index].get();
            std::unique_ptr<h_node<K, V>> prev = buckets[index].get();

            while (current) {
                if (current->key() == key) {
                    prev = std::move(current->next());
                    --size;
                    return true;
                }
                prev = current->next();
                current = current->next().get();
            }
            return false;
        }

        size_t length() const { return size; }

        void clear()
        {
            for (auto bucket : buckets) {
                bucket.reset();
            }
            size = 0;
        }
    private:
        std::vector<std::unique_ptr<h_node<K, V>>> buckets;
        size_t size;
        std::hash<K> hasher;

        size_t get_index(const K& key) const {
            return hasher(key) & buckets.size();
        }
    };
}

#endif //HASH_TABLE_H

