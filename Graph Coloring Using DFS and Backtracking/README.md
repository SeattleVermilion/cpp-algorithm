# Graph Coloring Using DFS and Backtracking

基于深度优先搜索（DFS）与回溯算法实现的图染色方案计数程序。

## 1. Problem Description | 问题描述

Given an undirected graph with `n` vertices and `m` edges, color each vertex using one of four available colors.

The goal is to calculate the total number of valid coloring schemes, subject to the following constraint:

**Any two adjacent vertices must have different colors.**

给定一个包含 `n` 个顶点和 `m` 条边的无向图，使用四种不同的颜色为所有顶点染色。

要求：

- 每个顶点必须染上一种颜色。
- 任意两个相邻顶点不能使用相同颜色。
- 不同颜色分配方式视为不同方案。
- 计算所有合法染色方案的数量。

**Constraints:**

- \(1 \leq n \leq 10\)
- 顶点编号为 `1` 到 `n`

## 2. Algorithm | 算法思路

The solution uses **Depth-First Search (DFS) with Backtracking** to enumerate all valid vertex colorings.

本程序采用 DFS + 回溯算法，逐个顶点尝试四种颜色。

主要步骤：

1. 使用邻接矩阵存储无向图。
2. 从第一个顶点开始，依次尝试四种颜色。
3. 使用 `judge()` 检查当前颜色是否与相邻顶点冲突。
4. 如果合法，则记录颜色并递归处理下一个顶点。
5. 当所有顶点完成染色时，返回 `1`，代表找到一种合法方案。
6. 回溯并尝试其他颜色，最终累加所有合法方案数。

### Recursive Counting | 递归计数

与使用全局计数器的常见写法不同，本实现通过**递归函数的返回值**累计合法方案数量。

每一层递归返回其搜索分支下的合法方案数，再由上一层进行累加。

## 3. Implementation | 实现细节

**Adjacency Matrix | 邻接矩阵**

```cpp
vector<vector<int>> arr1(n, vector<int>(n, 0));
```

**Color Array | 颜色数组**

```cpp
vector<int> color(n, 0);
```

其中：

- `0`：未染色
- `1`、`2`、`3`、`4`：四种不同颜色

**Core Functions | 核心函数**

| Function | Description |
|---|---|
| `judge()` | 判断当前顶点使用指定颜色是否合法 |
| `count()` | 递归搜索并返回合法染色方案数 |
| `main()` | 读取图的数据并输出最终结果 |

## 4. Complexity Analysis | 复杂度分析

**Time Complexity:**

\[
O(n \cdot 4^n)
\]

每个顶点最多尝试四种颜色，每次合法性检查最多遍历 `n` 个顶点。

**Space Complexity:**

\[
O(n^2)
\]

邻接矩阵需要 \(O(n^2)\) 空间，颜色数组和递归栈需要 \(O(n)\) 空间。

## 5. Example | 运行示例

**Input**

```text
3 3
1 2
2 3
1 3
```

**Output**

```text
24
```

**Explanation**

三个顶点两两相邻，因此必须使用三种不同颜色。

- 第一个顶点：4 种选择
- 第二个顶点：3 种选择
- 第三个顶点：2 种选择

合法染色方案总数：

\[
4 \times 3 \times 2 = 24
\]

## 6. Features | 代码特点

- 使用 DFS + Backtracking 解决组合计数问题。
- 使用 `vector` 动态管理邻接矩阵及颜色数组。
- 使用引用传参，避免复制二维数组。
- 将合法性判断与递归搜索分离。
- 利用递归返回值累计方案数，减少对全局变量的依赖。

## 7. Environment | 运行环境

- Language: C++
- Standard: C++11 or later
- IDE: Visual Studio / VS Code
- Compiler: MSVC / GCC / Clang

## 8. Notes | 说明

This project is a personal implementation created while learning graph algorithms, recursion, and backtracking.

本项目是我在学习图论、递归和回溯算法过程中独立思考并实现的练习代码。

欢迎交流算法思路、讨论优化方法并提出建议。

---

**Topics:** `C++` · `Graph Coloring` · `DFS` · `Backtracking` · `Recursion` · `Algorithms`