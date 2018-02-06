### 例 2.4 Day of week
时间限制:1 秒
内存限制:32 兆
特殊判题:否
#### 题目描述:
We now use the Gregorian style of dating in Russia. The leap years are years
with number divisible by 4 but not divisible by 100, or divisible by 400.
For example, years 2004, 2180 and 2400 are leap. Years 2004, 2181 and 2300 are not
leap.
Your task is to write a program which will compute the day of week
corresponding to a given date in the nearest past or in the future using today’sagreement about dating.
#### 输入:
There is one single line contains the day number d, month name M and year
number y(1000≤y≤3000). The month name is the corresponding English name
starting from the capital letter.
#### 输出:
Output a single line with the English name of the day of week corresponding to
the date, starting from the capital letter. All other letters must be in lower case.
#### 样例输入:
```
9 October 2001
14 October 2001
```
#### 样例输出:
```
Tuesday
Sunday
```