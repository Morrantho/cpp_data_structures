#include "HashMap.h"
#include <iostream>

template<typename V>
HashMap<V>::HashMap()
{
	size = 11;
}

template<typename V>
HashMap<V>::~HashMap()
{
	for(int i=0; i < size; i++)
	{
		if(keys[i] != 0) delete keys[i];
		if(values[i] != 0) delete values[i];
	}
}

// n
template<typename V>
unsigned int HashMap<V>::Hash(std::string key)
{
	unsigned int hash = 0;
	for(int i=0; i < key.size(); i++)
		hash = ((hash << 5) + hash) + (int)key[i]; 
	return hash;
}

template<typename V>
unsigned int HashMap<V>::Mod(unsigned int hash, unsigned int size)
{
	return hash % size;
}

// worst: n | linear
template<typename V>
Node<V>* HashMap<V>::ResolveCollision( std::string key, V value, unsigned int index )
{
	Node<std::string>* keyNode = keys[index];
	Node<V>* valueNode = values[index];

	for( ; keyNode->next != 0; keyNode = keyNode->next, valueNode = valueNode->next){}
	keyNode->next = new Node<std::string>(key);
	valueNode->next = new Node<V>(value);
	return valueNode;
}

// worst: n | linear, best: O(1) | constant
template<typename V>
Node<V>* HashMap<V>::Add(std::string key, V value)
{
	unsigned int hash  = Hash( key );
	unsigned int index = Mod( hash, size );
	if( keys[index] != 0 || values[index] != 0 ) return ResolveCollision( key, value, index );
	keys[index]   = new Node<std::string>(key);
	values[index] = new Node<V>(value);
	return values[index];
}

// worst: n | linear, best: O(1) | constant
template<typename V>
Node<V>* HashMap<V>::Get(std::string key)
{
	unsigned int hash  = Hash( key );
	unsigned int index = Mod( hash, size );
	Node<std::string>* keyNode = keys[index];
	Node<V>* valueNode = values[index];
	if(keyNode->value == key)
		return valueNode;
	else
		// This key collided previously. Try to find it.
		for( ; keyNode->next != 0; keyNode = keyNode->next, valueNode = valueNode->next)
			if( keyNode->value == key ) return valueNode;
		return 0;
}

// worst: n | linear, best: O(1) | constant
template<typename V>
Node<V>* HashMap<V>::Remove(std::string key)
{
	unsigned int hash = Hash( key );
	unsigned int index = Mod( hash, size );
	Node<std::string>* keyNode = keys[index];
	Node<V>* valueNode = values[index];
	if( valueNode == 0 || keyNode == 0 ) return 0;
	
	if( key == keyNode->value )
	{
		if(keyNode->next == 0)  // No collisions, null it and return.
		{
			keys[index] = 0;
			values[index] = 0;
			return valueNode;
		}else // Collisions exist, move pointers forward one.
		{
			Node<V>* old = valueNode;
			keyNode = keyNode->next;
			valueNode = valueNode->next;
			return old;
		}
	}else // Collisions exist since the key at this index doesn't match the supplied key. Try to find it.
	{
		for( ; keyNode->next != 0; keyNode = keyNode->next, valueNode = valueNode->next)
		{
			if( keyNode->next->value == key )
			{
				// Hold onto to be removed node + move pointers forward one.
				Node<V>* old = valueNode->next;
				keyNode->next = keyNode->next->next;
				valueNode->next = valueNode->next->next;
				// Null removed node's pointers.
				keyNode->next->next = 0;
				valueNode->next->next = 0;
				return old;
			}
		}
		// Should never get here.
		return 0;
	}
}