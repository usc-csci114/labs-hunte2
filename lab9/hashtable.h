#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <utility>
#include <vector>
#include <map>
#include <stdexcept>
#include <utility>
#include <iostream>

template <typename K, typename V>
class HashTable {
public:
	HashTable();
	~HashTable();
	void insert(K key, V value);
	V find(K key);
	void remove(K key);
	size_t size();
	bool empty();
	
private:
	std::vector< std::map<K,V> > table;
	void resize();
	size_t size_;
	size_t alpha;
	uint64_t hash(K key);
};

template <typename K, typename V>
HashTable<K,V>::HashTable() { table.resize(1); alpha = 1; size_ = 0;};

template <typename K, typename V>
HashTable<K,V>::~HashTable() {};

template <typename K, typename V>
uint64_t HashTable<K,V>::hash(K key)
{
	std::hash<K> hasher;
	return hasher(key);
}

template <typename K, typename V>
void HashTable<K,V>::insert(K key, V value)
{
	if((size_ + 1) > alpha * table.size()){
		resize();
	}
	size_t idx = hash(key) % table.size();
	table[idx][key] = value;
	size_++;

}

template <typename K, typename V>
V HashTable<K,V>::find(K key)
{
	size_t idx = hash(key) % table.size();
	if(table[idx].count(key) > 0){
		return table[idx][key];
	}
	throw std::range_error("Key is not found.");

}

template <typename K, typename V>
void HashTable<K,V>::remove(K key)
{
	size_t idx = hash(key) % table.size();
	if(table[idx].count(key) > 0 )
	{
		table[idx].erase(key);
		size_--;
	}
	else {
		throw std::range_error("Key is not found.");
	}	
}

template <typename K, typename V>
size_t HashTable<K,V>::size()
{
	return table.size();

}

template <typename K, typename V>
bool HashTable<K,V>::empty()
{
	if(table.size() == 0){
		return true;
	}

}

template <typename K, typename V>
void HashTable<K,V>::resize()
{
	std::vector< std::map<K,V> > old_table = table;
	table.clear(); 
	table.resize(2*old_table.size());
	size_ = 0;
	for(size_t i = 0; i < old_table.size(); i++){
		for(const auto& pair : old_table[i]) {
            size_t new_idx = hash(pair.first) % table.size();
            table[new_idx].insert(pair);
            size_++;
        }
	}
	std::cout << "resizing " << table.size() << " -> " << table.size()*2 << std::endl;
}
#endif

