#
# @lc app=leetcode id=1462 lang=python
#
# [1462] Course Schedule IV
#

# @lc code=start
from typing import *

class Node():
    def __init__(self, val:int = 0) -> None:
        self.val = val
        self.neighbors :List[Node]= dict()

class Solution(object):
    def __init__(self) -> None:
        super().__init__()
        courseNodes:dict[int, Node] = dict()
        visited:set[Node] = set()
        self.dp[List[List[int]]] = [[0] * 100] * 100

    def BuildGraph(self, n:int, pre:List[List[int]])->None:
        self.courseNodes = [{i : Node(i)} for i in range(100)]
        for ele in pre:
            self.courseNodes[ele[0]].neigbours.append(self.courseNodes[i[1]])


    def dfs(self, src:Node, dest:Node)->bool:
        if(self.dp[src.val][dest.val] != -1):
            return self.dp[src.val][dest.val]
        if(src == dest):
            return self.dp[src.val][dest.val] = 1
        b:bool = False;

    def checkIfPrerequisite(self, numCourses:int, prerequisites:List[List[int]], queries:List[List[int]]):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        
# @lc code=end

