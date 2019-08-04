from sys import stdin

dp = [[0 for x in range(200)] for _ in range(200)]


class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value
        self.childs = 1


def insert(node, value):
    if node is None:
        return Node(value)
    if value < node.value:
        node.left = insert(node.left, value)
        node.childs += 1
    else:
        node.right = insert(node.right, value)
        node.childs += 1
    return node


def C(n, m):
    if n == m: return 1
    if m == 1: return n

    if dp[n][m]: return dp[n][m]

    dp[n][m] = C(n - 1, m) + C(n - 1, m - 1)
    return dp[n][m]


def f(left, right):
    if left is None or right is None:
        return 1
    return C(left.childs + right.childs, left.childs)


def solve(node):
    if node is None:
        return 1

    left = node.left
    right = node.right
    return solve(right) * solve(left) * f(left, right) 

    
def main():
    lines = stdin.read().splitlines()
    lines.pop()

    for i in range(0, len(lines), 2):
        elements = [int(x) for x in lines[i + 1].split()]
        tree = None

        for element in elements:
            tree = insert(tree, element)

        print(solve(tree))


if __name__ == '__main__':
    main()
