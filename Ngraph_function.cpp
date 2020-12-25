#include "Ngraph.h"

template <typename T>
void Vertex<T>::set_value(T value)
{
	this->value = value;
}

template <typename T>
T Vertex<T>::get_value()
{
	return value;
}

template<typename T>
Graph<T>::Graph(int n)
{
	vertex = new T[n];
	size = n;
	edges = new bool* [size];
	for (int i = 0; i < size; i++)
	{
		edges[i] = new bool[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int g = 0; g < size; g++)
			edges[i][g] == false;
	}
}

template<typename T>
void Graph<T>::show() {
	if (!empty())
	{
		bool* checked_node = new bool[size];


		for (int i = 0; i < size; i++)
		{
			checked_node[i] = true;
			cout << vertex[i] << endl;
			for (int g = 1; g < size; g++) {
				if (checked_node[g] != 1 && edges[i][g] == 1)
				{
					checked_node[g] = true;
					cout << vertex[g] << "\t";
				}
			}
			cout << endl;
		}
	}
	else { cout << "Graph is empty\n"; }
}

template<typename T>
void Graph<T>::delete_edge(T f_node, T s_node)
{
	if (is_node(f_node) && is_node(s_node))
	{
		int n_f = find_node(f_node);
		int n_s = find_node(s_node);
		edges[n_f][n_s] = 0;
		edges[n_s][n_f] = 0;

	}
}

template<typename T>
void Graph<T>::delete_node(T inform)
{
	if (is_node(inform))
	{
		int n = find_node(inform);
		Vertex<T>* new_nodes = new Vertex<T>[size - 1];
		bool** new_edges = new bool* [size - 1];
		for (int i = 0; i < size - 1; i++)
			new_edges[i] = new bool[size - 1];
		int g = 0;
		for (int i = 0; i < size; i++)
		{
			if (i == n)
				continue;
			new_nodes[g] = vertex[i];
			g++;
		}
		int z = 0;
		for (int i = 0; i < size; i++)
		{
			g = 0;
			if (i == n)
				continue;
			for (int y = 0; y < size; y++)
			{
				if (y == n)
					continue;
				new_edges[z][g] = edges[i][y];
				g++;
			}
			z++;
		}
		if (size > 0)
		{
			delete[] vertex;
			for (int i = 0; i < size; i++)
				delete[] edges[i];
			delete[] edges;
		}
		vertex = new_nodes;
		edges = new_edges;
		size = size - 1;

	}
}

template<typename T>
void Graph<T>::add_edge(T f_node, T s_node)
{
	if (is_node(f_node) && is_node(s_node))
	{
		int n_f = find_node(f_node);
		int n_s = find_node(s_node);
		edges[n_f][n_s] = 1;
		edges[n_s][n_f] = 1;

	}


}

template<typename T>
int Graph<T>::get_number_edges()
{
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		for (int g = i; g < size; g++)
		{
			res += edges[i][g];
		}
	}
	return res;
}

template<typename T>
int Graph<T>::degree_node(T info)
{
	int res = 0;
	int number = find_node(info);
	for (int i = 0; i < size; i++)
		res += edges[number][i];
	return res;
}

template<typename T>
void Graph<T>::add_node(T info)
{
	if (!is_node(info))
	{
		Vertex<T>* new_nodes = new Vertex<T>[size + 1];
		for (int i = 0; i < size; i++)
		{
			new_nodes[i] = vertex[i];
		}
		new_nodes[size] = info;
		bool** new_edges = new bool* [size + 1];
		for (int i = 0; i < size + 1; i++)
			new_edges[i] = new bool[size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			for (int g = 0; g < size + 1; g++)
			{
				if (g == size || i == size)
				{
					new_edges[i][g] = 0;

				}
				else {
					new_edges[i][g] = edges[i][g];
				}
			}
		}
		if (size > 0)
		{
			delete[] vertex;
			for (int i = 0; i < size; i++)
				delete[] edges[i];
			delete[] edges;
		}
		size = size + 1;
		vertex = new_nodes;
		edges = new_edges;

	}
}

template<typename T>
int Graph<T>::find_node(T value)
{
	for (int i = 0; i < this->size; i++)
	{
		if (vertex[i].get_value() == value)
			return i;
	}
	return -1;
}

template<typename T>
bool Graph<T>::is_node(T inform)
{
	for (int i = 0; i < size; i++)
	{
		if (inform == vertex[i].get_value())
			return true;
	}
	return false;
}