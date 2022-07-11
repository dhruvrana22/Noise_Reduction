#ifndef PCA_H
#define PCA_H
#include <iostream>
#include <vector>
#include "qbMatrix.h"
using namespace std;
namespace wisdom{
	class PCA{
		public:
		//Number of Samples in csv file
		int nrSamples=63746;
		//Number of components in csv file
		int nrComp=2;
		//Principal Component Analysis of Data
		void m1(vector<vector<double>> Data,vector<vector<double>> &result);
	};
	//Converts 2D vector to 1D vector
	void vectods(vector<vector<double>> &Data,vector<double> &testData);
	//Converts qbMatrix2 to 2D vector
	void dstovec(qbMatrix2<double> &newX,vector<vector<double>> &result);
}
#endif
