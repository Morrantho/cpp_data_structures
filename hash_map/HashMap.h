#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include "Node.cpp"

template<typename V>
class HashMap
{
private:
	unsigned int size;
	Node<std::string>* keys[11] = {nullptr};
	Node<V>* values[11]  = {nullptr};
public:
	HashMap();
	HashMap( unsigned int _size ): size( _size ) {};
	~HashMap();

	unsigned int Hash( std::string key );
	unsigned int Mod( unsigned int hash, unsigned int size );
	Node<V>* Add( std::string key, V value );
	Node<V>* ResolveCollision( std::string key, V value, unsigned int index );
	Node<V>* Remove( std::string key );
	Node<V>* Get( std::string );
	bool IsEmpty();
};
#endif