### 例 3.4 二叉树遍历
时间限制:1 秒
内存限制:32 兆
特殊判题:否
#### 题目描述:
二叉树的前序、中序、后序遍历的定义:
前序遍历:对任一子树,先访问跟,然后遍历其左子树,最后遍历其右子树;
中序遍历:对任一子树,先遍历其左子树,然后访问根,最后遍历其右子树;
后序遍历:对任一子树,先遍历其左子树,然后遍历其右子树,最后访问根。
给定一棵二叉树的前序遍历和中序遍历,求其后序遍历(提示:给定前序遍
历与中序遍历能够唯一确定后序遍历)。
#### 输入:
两个字符串,其长度 n 均小于等于 26。
第一行为前序遍历,第二行为中序遍历。二叉树中的结点名称以大写字母表
示:A,B,C....最多 26 个结点。
#### 输出:
输入样例可能有多组,对于每组测试样例,输出一行,为后序遍历的字符串。
#### 样例输入:
```
ABC
BAC
FDXEAG
XDEFAG
```
#### 样例输出:
```
BCA
XEDGAF
```