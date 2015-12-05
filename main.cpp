#include <iostream>
#include <armadillo>
#include <vector>
#include <math.h>

#include "basis.h"
#include "Nurbs-DS.h"
using namespace arma;
using namespace std;

const float Pi = 3.14159265358979323846;

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
	//float num = 4.0;
	float r = 1.0;
	int sub = 360;  //r = sub
	float subA = 2*Pi / sub;
	vector<point> C;
	vector<point> D;
	cout << r*sin(0* subA) << " " << r*cos(0 * subA) << " " << 0 << endl;
	for (int i = 0; i <sub/2; i++)
	{
		
		point out(r*sin(i*subA), r*cos(i*subA), 0);
		C.push_back(out);
	}
	//cout << r*sin(360*subA)<< " " << r*cos(360*subA) << " "<< 0 << endl;

	
	int numofControlPoint = 20;
	int degree = 3;
	vector<float> U;
	vector<point> P;
	BsplineApp(C, sub/2,     //Q[]存储拟合的数据点Q的个数为r+1
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
	ofstream fout;
	string filename = "fit100.nrb";
	fout.open(filename);
	fout << "degree " << degree << "\n";
	fout << "control point " << numofControlPoint << "\n";
	fout << "knots " << U.size() << "\n";

	fout << "end_header\n";
	fout << "\n";
	for (int i = 0; i < P.size(); i++){
		fout << P[i].x << " ";
		fout << P[i].y << " ";
		fout << P[i].z << "\n";;
	}
	fout << "\n";
	fout << U[0] ;
	for (int i = 1; i < U.size(); i++){
		fout << " "<< U[i] ;
	}
	fout << "\n";
	fout << flush;
	fout.close();
	cout << " success" << endl;
	system("pause");
	return 0;
}
