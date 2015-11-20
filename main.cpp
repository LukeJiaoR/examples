#include <iostream>
#include <armadillo>
#include <vector>


#include "basis.h"
#include "Nurbs-DS.h"
using namespace arma;
using namespace std;


float fordouble(float x)
{
	return x*x;
}

//
///*算法9.6*/
//bool WCLeastSquaresCureve(vector<point> Q, int r,     //Q[]存储拟合的数据点Q的个数为r+1
//	float Wq[],           //>0 是非约束点,<0是约束点 ，大小 r+1
//	vector<point> D, int s, int I[],       // D[]存储导矢。导矢个数为s+1，s = -1表示没有导矢,I[]存储对应第k个导矢对应的点在Q中的下标
//	float Wd[],           //标明D[]中导矢的约束性。
//	int n,                //预备用n个控制点来拟合
//	int p,                //拟合曲线为p次
//	vector<float> U, vector<cpoint> P   //输出的节点向量U和控制点p.
//	)

int main(int argc, char *argv[])
{
	float num = 10.0;
	int sub = 20;  //r = sub
	float subA = num / sub;
	vector<point> C;
	float Wq[100];
	vector<point> D;
	int s = -1;
	float Wd[1] = {1};
	int I[1];
	for (int i = 0; i < sub; i++)
	{
		cout << i*subA << " " << fordouble(i*subA) << " "<< 0 << endl;
		point out(i*subA, fordouble(i*subA), 0);
		C.push_back(out);
		Wq[i] = 1;
	}
	point out(num, fordouble(num), 0);
	C.push_back(out);
	Wq[sub - 1] = 1;
	
	int numofControlPoint = 10;
	int degree = 3;
	vector<float> U;
	vector<point> P;
	BsplineApp(C, sub,     //Q[]存储拟合的数据点Q的个数为r+1
		numofControlPoint - 1,                //预备用n+1个控制点来拟合
		degree,                //拟合曲线为p次
		U, P   //输出的节点向量U和控制点p.
		);
/*
	if (WCLeastSquaresCureve(C, r,     //Q[]存储拟合的数据点Q的个数为r+1
		Wq,           //>0 是非约束点,<0是约束点 ，大小 r+1
		D, s, I,       // D[]存储导矢。导矢个数为s+1，s = -1表示没有导矢,I[]存储对应第k个导矢对应的点在Q中的下标
		Wd,           //标明D[]中导矢的约束性。
		numofControlPoint-1,                //预备用n+1个控制点来拟合
		degree,                //拟合曲线为p次
		U, P   //输出的节点向量U和控制点p.
		))
	{
		std::cout << "great" << endl;
	}
	else{
		std::cout << "bad" << endl;
	}*/
	
	cout << " success" << endl;
	system("pause");
	return 0;
}
