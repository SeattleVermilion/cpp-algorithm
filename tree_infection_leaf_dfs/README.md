# Binary Tree Infection Time — DFS on Tree Endpoints

## Problem

Given a binary tree and a starting node `start`, the starting node is infected at minute 0. Every minute, infection spreads from each infected node to all adjacent nodes: its left child, right child, and parent.

Return the minimum number of minutes needed to infect every node.

## Approach: Find the Farthest Leaf

Treat the binary tree as an **undirected tree**:

- A parent-child relationship becomes a bidirectional connection.
- Infection can spread from a parent to a child and from a child to its parent.

The infection time of a node is its distance from `start`. Therefore, the time needed to infect the whole tree is:

\\[
\\max_{v \\in V} \\operatorname{dist}(start, v)
\\]

In a tree, a node farthest from a given starting node must be an endpoint of the undirected tree. An endpoint has degree 1. For a tree containing only one node, its degree is 0.

The algorithm performs a DFS from `start`, checks every visited node's degree, and updates the answer when it reaches an endpoint.

### Why is the farthest node an endpoint?

Suppose a farthest node were not an endpoint. Besides the neighbor on the path back to `start`, it would have another neighbor leading farther away. Moving to that neighbor would increase the distance from `start`, contradicting the assumption that the original node was farthest.

## Implementation

Each node stores three pointers:

- `lchild`: left child
- `rchild`: right child
- `parent`: parent

The tree is traversed as an undirected tree. The DFS stack stores three values:

- `cur`: current node
- `pre`: previous node, used to avoid immediately moving backward
- `dis`: distance from the starting node

For each node, its undirected degree is the number of non-null pointers among `lchild`, `rchild`, and `parent`.

If the degree is at most 1, the node is an endpoint, so its distance is considered when updating the maximum.

The implementation uses an iterative DFS to avoid recursion-depth problems on a highly unbalanced tree.

## Complexity

Let `n` be the number of nodes.

- **Time complexity:** `O(n)`. Every node is visited once, and each node has at most three neighbors.
- **Auxiliary space complexity:** `O(n)` in the worst case for the explicit DFS stack.
- **Tree storage:** `O(n)`.

## Input Format

The input contains:

1. `n start`: the number of nodes and the starting node index.
2. The next `n` lines each contain two integers `l r`, representing the left-child and right-child indices of node `i`.
3. `-1` means that the corresponding child does not exist.

Node indices are zero-based.

## Example

### Input

```text
9 4
-1 1
2 6
3 4
-1 -1
-1 5
-1 -1
-1 7
-1 8
-1 -1
```

### Output

```text
5
```

Starting from node `4`, the farthest endpoint is node `8`. The path is:

```text
4 -> 2 -> 1 -> 6 -> 7 -> 8
```

There are 5 edges on this path, so all nodes are infected after 5 minutes.

## Notes

- The endpoint check must use the degree in the undirected tree, not only `lchild == nullptr && rchild == nullptr`.
- The root can also be an endpoint when it has exactly one child.
- If the tree has only one node, the answer is `0`.
- This method relies on the input being a valid tree. It is not a general replacement for BFS on arbitrary graphs.

##Advantages
1. No infection simulation: Directly calculates the maximum distance from the starting node without simulating infection minute by minute.
2. No visited array required: Uses the previous node pointer to avoid traversing backward, eliminating the need for an additional visited array.
3. Efficient traversal: Each node is visited exactly once, achieving \(O(n)\) time complexity.
4. Iterative DFS: Uses an explicit stack instead of recursion, avoiding potential recursion stack overflow on highly unbalanced trees.
5. Simple implementation: Only needs to maintain the current node, previous node, and distance.

Balanced Tree Compatibility: When the input tree is already balanced, the DFS auxiliary space complexity can be reduced to \(O(\log n)\), taking advantage of the tree's logarithmic height without changing its original structure.So you can banlance the tree in advance.