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
///*�㷨9.6*/
//bool WCLeastSquaresCureve(vector<point> Q, int r,     //Q[]�洢��ϵ����ݵ�Q�ĸ���Ϊr+1
//	float Wq[],           //>0 �Ƿ�Լ����,<0��Լ���� ����С r+1
//	vector<point> D, int s, int I[],       // D[]�洢��ʸ����ʸ����Ϊs+1��s = -1��ʾû�е�ʸ,I[]�洢��Ӧ��k����ʸ��Ӧ�ĵ���Q�е��±�
//	float Wd[],           //����D[]�е�ʸ��Լ���ԡ�
//	int n,                //Ԥ����n�����Ƶ������
//	int p,                //�������Ϊp��
//	vector<float> U, vector<cpoint> P   //����Ľڵ�����U�Ϳ��Ƶ�p.
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
	BsplineApp(C, sub,     //Q[]�洢��ϵ����ݵ�Q�ĸ���Ϊr+1
		numofControlPoint - 1,                //Ԥ����n+1�����Ƶ������
		degree,                //�������Ϊp��
		U, P   //����Ľڵ�����U�Ϳ��Ƶ�p.
		);
/*
	if (WCLeastSquaresCureve(C, r,     //Q[]�洢��ϵ����ݵ�Q�ĸ���Ϊr+1
		Wq,           //>0 �Ƿ�Լ����,<0��Լ���� ����С r+1
		D, s, I,       // D[]�洢��ʸ����ʸ����Ϊs+1��s = -1��ʾû�е�ʸ,I[]�洢��Ӧ��k����ʸ��Ӧ�ĵ���Q�е��±�
		Wd,           //����D[]�е�ʸ��Լ���ԡ�
		numofControlPoint-1,                //Ԥ����n+1�����Ƶ������
		degree,                //�������Ϊp��
		U, P   //����Ľڵ�����U�Ϳ��Ƶ�p.
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
