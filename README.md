# C-projcet

## 已完成：

### 基本属性
`vector<vector<complex<double>>> matrix` 每个元素为std::complex<double>的二维vector

`int row, column;` 矩阵的行，列。

`x.show();` 打印x矩阵，结果类似于python中np

`x.showSize()` 打印x矩阵的行列，用于异常提醒
### 初始化（默认每个元素为std::complex<double>，使用二维vector存储）

`matrix x;` x为row=0，column=0的空矩阵。

`Matrix x = Matrix(3, 4);` x为row=3，column=4的所有项为0的矩阵

`Matrix x= Matrix(10);` x为row=1，column=10的向量。

### 设置行，列

`x.setRow(10);` 将x的row设定为10，若x原先的row小于10则扩充元素为0的矩阵，若x的row大于10，则删除掉多余的row

`x.setColumn(10);`将x的column设定为10，若x原先的column小于10则扩充元素为0的矩阵，若x的column大于10，则删除掉多余的column

### 重载[]访问矩阵元素
`x[i][j]` 访问矩阵x的第i行第j列元素。

### 重载+-，实现矩阵和矩阵之间相加减
`y=a+b;` y为矩阵a和b的和，若a和b的size不相等，则会抛出异常。

### 基本算术操作
`x.findMax()` 返回矩阵x中实数部分最大的实数部分（由于复数无法比较大小，方法只对矩阵中所有元素的实部进行比较），如果矩阵为空矩阵则返回0

`x.findMaxAtRow(int row)` 返回矩阵x中第row行的最大的实数部分

`x.findMaxAtColumn(int column)` 返回矩阵x中第column行的最大的实数部分

`x.findMin()` 返回矩阵x中最小的实数部分

`x.findMinAtRow(int row)` 返回矩阵x第row行中最小的实数部分

`x.findMinAtColumn(int column)` 返回矩阵x中第column行中最小的实数部分

`x.findSum()`返回矩阵x中所有元素的和，返回值为复数，若x为空矩阵返回实部虚部都为0的复数。

`x.findSumAtRow(int row)` 返回矩阵x中第row行的元素和。

`x.findSumAtColumn(int column)` 返回矩阵x中第colum行的元素和。 

`x.findAverage()` 返回矩阵x中的平均值，返回值为复数，若为空矩阵则返回实部虚部都为0的复数。

`x.findAverageAtRow(int row)` 返回矩阵x中第row行的平均值。

`x.findAverageAtColumn(int column);` 返回矩阵x中第column列的平均值。

## 短期目标：

3)支持矩阵和向量运算，包括加法、减法、标量乘法、标量除法、移位法、共轭法、元素乘法、矩阵矩阵乘法、矩阵向量乘法、点积和叉积。

4)支持基本的算术约简操作，包括查找最大值、查找最小值、对所有项求和、计算平均值(所有支持特定于轴的项和所有项)。**此项暂时完成**

5)支持计算特征值和特征向量，计算迹，计算逆和计算行列式。

代码很好写，但是问题是不知道怎么算。。

## 暂时放弃的目标

### 稀疏矩阵的存储

模仿np

### 2)支持所有标准的数字类型，包括std::complex, integers，并且易于扩展到定制的数字类型。

这一点不是很明确，应该基本的数字类型都可以直接转换为`complex<double>`


