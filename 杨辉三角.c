#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//在屏幕上打印杨辉三角。

//由于此题要打印整个杨辉三角的数据而非取出某一项，所以不可避免的一定是要填出每一项，没有偷懒的余地，那就老老实实的根据规律填空即可。按照题设的场景，能发现数字规律为：d[i][j] = d[i - 1][j] + d[i - 1][j - 1]。所以我们只要按照这个方法填表即可。



void yangHuiTriangle(int n)
{
	int data[30][30] = { 1 }; //第一行直接填好，播下种子

	int i, j;

	for (i = 1; i < n; i++) //从第二行开始填
	{
		data[i][0] = 1; //每行的第一列都没有区别，直接给1，保证不会越界。
		for (j = 1; j <= i; j++) //从第二列开始填
		{
			data[i][j] = data[i - 1][j] + data[i - 1][j - 1]; //递推方程
		}
	}

	for (i = 0; i < n; i++) //填完打印
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", data[i][j]);
		}
		putchar('\n');
	}
}


//改进
//由于我在填第n行的杨辉三角时，只跟第n - 1行的杨辉三角产生联系，不会跟之前的有联系，所以没必要保存每一行的杨辉三角，填一行打一行就行了，这样能让空间复杂度从n ^ 2降低到n。但是在填数据的时候不能对之前的数据覆盖，所以需要从后向前填。而填杨辉三角顺序对结果是没有影响的，所以可以实现。



void yangHuiTriangle(int n)
{
	int data[30] = { 1 };

	int i, j;
	printf("1\n"); //第一行就直接打印了
	for (i = 1; i < n; i++) //从第二行开始
	{
		for (j = i; j > 0; j--) //从后向前填，避免上一行的数据在使用前就被覆盖
		{
			data[j] += data[j - 1]; //公式同上，由于变成了一维，公式也变简单了。
		}

		for (j = 0; j <= i; j++) //这一行填完就直接打印了。
		{
			printf("%d ", data[j]);
		}
		putchar('\n');
	}
}
