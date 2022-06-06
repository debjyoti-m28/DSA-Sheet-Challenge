#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findparent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findparent(parent[node]);
    }
    void unionof(int node1, int node2)
    {
        int par1 = findparent(node1);
        int par2 = findparent(node2);
        if (par1 == par2)
            return;
        else if (size[par1] < size[par2])
        {
            parent[par1] = par2;
            size[par2] += size[par1];
        }
        else
        {
            parent[par2] = par1;
            size[par1] += size[par2];
        }
    }
};