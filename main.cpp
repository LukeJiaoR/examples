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
	BsplineApp(C, sub/2,     //Q[]�洢��ϵ����ݵ�Q�ĸ���Ϊr+1
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
