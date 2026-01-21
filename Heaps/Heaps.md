# Heap Data Structure
1. A heap is a special tree-based data structure in which the tree is a complete binary tree.
2. If my node is at i then left child is at 2i and right child is at 2i+1.
3. If child index is i then parent index = i/2(integer devision).
4. If n is the number of nodes, non-leaf nodes = 1 to n/2 and leaf-nodes=(n/2)+1 to n.
5. The height of heap is H=[log2n] (log n with base 2).
6. the number of nodes n=(2^(h+1))-1

## Types of Heaps
### Min heap
- parent <= both children
- Minimum will be on the top of the tree
### Max heap
- Parent >= both children
- Maximum will be on top of the tree

