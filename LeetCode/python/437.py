import sys
from collections import deque

# 定义二叉树节点
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 核心逻辑：统计路径和为targetSum的路径数
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        prefix_sum = {0: 1}  # 前缀和哈希表，初始0出现1次
        self.count = 0       # 符合条件的路径数

        def dfs(node, current_sum):
            if not node:
                return
            # 更新当前前缀和
            current_sum += node.val
            # 累加符合条件的路径数
            self.count += prefix_sum.get(current_sum - targetSum, 0)
            # 记录当前前缀和
            prefix_sum[current_sum] = prefix_sum.get(current_sum, 0) + 1
            # 递归遍历左右子树
            dfs(node.left, current_sum)
            dfs(node.right, current_sum)
            # 回溯：恢复前缀和哈希表
            prefix_sum[current_sum] -= 1
            if prefix_sum[current_sum] == 0:
                del prefix_sum[current_sum]

        dfs(root, 0)
        return self.count

# 从层序遍历列表构建二叉树（处理#/None空节点）
def build_tree(nodes):
    if not nodes:
        return None
    # 将#替换为None，字符串转整数
    nodes = [int(x) if x != '#' else None for x in nodes]
    root = TreeNode(nodes[0])
    q = deque([root])
    idx = 1  # 下一个要处理的节点索引
    while q and idx < len(nodes):
        curr = q.popleft()
        # 处理左孩子
        if nodes[idx] is not None:
            curr.left = TreeNode(nodes[idx])
            q.append(curr.left)
        idx += 1
        # 处理右孩子（需判断索引是否越界）
        if idx < len(nodes) and nodes[idx] is not None:
            curr.right = TreeNode(nodes[idx])
            q.append(curr.right)
        idx += 1
    return root

# ACM 主函数：处理输入输出
def main():
    # 读取输入（支持多组用例，按EOF结束）
    lines = sys.stdin.read().splitlines()
    # 按行解析：第一行是二叉树层序节点，第二行是targetSum
    for i in range(0, len(lines), 2):
        if i+1 >= len(lines):
            break
        # 解析二叉树节点
        tree_nodes = lines[i].strip().split()
        # 解析目标和
        target_sum = int(lines[i+1].strip())
        # 构建二叉树
        root = build_tree(tree_nodes)
        # 计算结果
        sol = Solution()
        res = sol.pathSum(root, target_sum)
        # 输出结果
        print(res)

if __name__ == "__main__":
    main()