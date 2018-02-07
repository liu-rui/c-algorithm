### 例 2.11 FatMouse' Trade
时间限制:1 秒
内存限制:128 兆
特殊判题:否
#### 题目描述:
FatMouse prepared M pounds of cat food, ready to trade with the cats guarding
the warehouse containing his favorite food, JavaBean.
The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans
and requires F[i] pounds of cat food. FatMouse does not have to trade for all the
JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays
F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this
homework to you: tell him the maximum amount of JavaBeans he can obtain.
#### 输入:
The input consists of multiple test cases. Each test case begins with a line
containing two non-negative integers M and N. Then N lines follow, each contains
two non-negative integers J[i] and F[i] respectively. The last test case is followed by
two -1's. All integers are not greater than 1000.
#### 输出:
For each test case, print in a single line a real number accurate up to 3 decimal
places, which is the maximum amount of JavaBeans that FatMouse can obtain.
#### 样例输入:
```
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
```
#### 样例输出:
```
13.333
31.500
```

#### 题目大意如下:
有 m 元钱,n 种物品;每种物品有 j 磅,总价值 f 元,可以
使用 0 到 f 的任意价格购买相应磅的物品,例如使用 0.3f 元,可以购买 0.3j 磅物
品。要求输出用 m 元钱最多能买到多少磅物品。