#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Vertex
{
	T value;
public:
	Vertex() {};
	Vertex(T info)
	{
		value = info;
	}
	void set_value(T value);
	T get_value();
	Vertex& operator=(Vertex const* right)
	{
		if (this = right)
			return *this;
		value = right->value;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Vertex<T>& it)
	{
		out << "Node:" << it.value << endl;
		return out;
	}
};

template <typename T>
class Graph
{
	Vertex<T>* vertex;
	int size;
	bool** edges;
public:
	Graph(int n);
	Graph() {}
	int find_node(T value);
	bool empty()
	{
		return size == 0;
	}
	bool is_node(T inform);
	bool is_edge(T first, T second)
	{
		return edges[find_node(first)][find_node(second)] == 1;
	}
	void clear()
	{
		delete[] vertex;
		for (int i = 0; i < size; i++)
			delete[] edges[i];
		delete[] edges;

		size = 0;
		edges = nullptr;
		vertex = nullptr;
	}
	int degree_node(T info);
	void add_node(T info);
	int get_number_nodes()
	{
		return size;
	}
	int get_number_edges();
	void add_edge(T f_node, T s_node);
	void delete_node(T inform);
	void delete_edge(T f_node, T s_node);
	void show();
	class iterator;
	class const_iterator;
	iterator begin()
	{
		return vertex;
	}
	const const_iterator cbegin()
	{
		return vertex;
	}
	const const_iterator cend()
	{
		return vertex + size;
	}
	iterator end()
	{
		return vertex + size;
	}
	class iterator
	{
		Vertex<T>* value;
	public:
		iterator(Vertex<T>* value)
		{
			this->value = value;
		}
		iterator& operator++()
		{
			*value++;
			return *this;
		}
		iterator& operator--()
		{
			*value--;
			return *this;
		}
		iterator& operator=(Vertex<T>* right)
		{
			if (this == &right)
				return *this;
			*value = *right.value;
			return *this;
		}
		bool operator==(const iterator& right)
		{
			return value == right.value;
		}
		bool operator!=(const iterator& right)
		{
			return value != right.value;
		}
		iterator operator*()
		{
			return *this;
		}
		friend ostream& operator<<(ostream& out, const iterator& it)
		{
			out << "Vertex:" << it.value->get_value() << endl;
			return out;
		}

	};
	class const_iterator
	{
		Vertex<T>* value;
	public:
		const_iterator(Vertex<T>* value)
		{
			this->value = value;
		}
		const const_iterator& operator++()
		{
			*value++;
			return *this;
		}
		const const_iterator& operator--()
		{
			*value--;
			return *this;
		}
		bool operator==(const const_iterator& right)
		{
			return  value == right.value;
		}
		bool operator!=(const const_iterator& right)
		{
			return value != right.value;
		}
		const Vertex<T> operator*()
		{
			return *value;
		}
		friend ostream& operator<<(ostream& out, const const_iterator& it)
		{
			out << "Vertex:" << it.value->get_value() << endl;
			return out;
		}
	};
};
