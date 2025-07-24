package main

import (
	"fmt"
)

type Node struct {
	left, right, parent int
	weightLeft, weightRight int
}

const MAXN = 200010 
const LOG = 20     

var up [MAXN][LOG]int 
var depth [MAXN]int  

func solve(Q int, queries [][]int) []int {
	nodes := make(map[int]*Node)
	nodes[1] = &Node{}
	lastNode := 1
	result := []int{}

	up[1][0] = -1 
	depth[1] = 0

	for _, query := range queries {
		if query[0] == 1 {
			x, y := query[1], query[2]
			var targetNode int
			minHeight := int(^uint(0) >> 1
			for nodeID, node := range nodes {
				if node.left == 0 && node.right == 0 {
					if depth[nodeID] < minHeight {
						minHeight = depth[nodeID]
						targetNode = nodeID
					}
				}
			}
			lastNode++
			nodes[targetNode].left = lastNode
			nodes[targetNode].weightLeft = x
			nodes[lastNode] = &Node{parent: targetNode}
			depth[lastNode] = depth[targetNode] + 1
			up[lastNode][0] = targetNode
			for j := 1; j < LOG; j++ {
				if up[lastNode][j-1] != -1 {
					up[lastNode][j] = up[up[lastNode][j-1]][j-1]
				} else {
					up[lastNode][j] = -1
				}
			}

			lastNode++
			nodes[targetNode].right = lastNode
			nodes[targetNode].weightRight = y
			nodes[lastNode] = &Node{parent: targetNode}
			depth[lastNode] = depth[targetNode] + 1
			up[lastNode][0] = targetNode
			for j := 1; j < LOG; j++ {
				if up[lastNode][j-1] != -1 {
					up[lastNode][j] = up[up[lastNode][j-1]][j-1]
				} else {
					up[lastNode][j] = -1
				}
			}
		} else if query[0] == 2 {
			p, q := query[1], query[2]
			lca := findLCA(p, q)
			xor := 0
			current := p
			for current != lca {
				parent := up[current][0]
				if nodes[parent].left == current {
					xor ^= nodes[parent].weightLeft
				} else {
					xor ^= nodes[parent].weightRight
				}
				current = parent
			}
			current = q
			for current != lca {
				parent := up[current][0]
				if nodes[parent].left == current {
					xor ^= nodes[parent].weightLeft
				} else {
					xor ^= nodes[parent].weightRight
				}
				current = parent
			}
			result = append(result, xor)
		}
	}
	return result
}

func findLCA(u, v int) int {
	if depth[u] < depth[v] {
		u, v = v, u
	}
	for i := LOG - 1; i >= 0; i-- {
		if depth[u]-(1<<i) >= depth[v] {
			u = up[u][i]
		}
	}
	if u == v {
		return u
	}
	for i := LOG - 1; i >= 0; i-- {
		if up[u][i] != up[v][i] {
			u = up[u][i]
			v = up[v][i]
		}
	}
	return up[u][0]
}