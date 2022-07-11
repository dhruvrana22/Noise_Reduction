#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "qbMatrix.h"
#include "qbVector.h"
#include "qbPCA.h"
#include "pca.h"
#include "utils.h"
using namespace std;
namespace wisdom{
	//Principal Component Analysis using qb library
	void PCA::m1(vector<vector<double>> Data,vector<vector<double>> &result){
		vector<double> testData;
		vectods(Data,testData);
		qbMatrix2<double> X (nrSamples, nrComp,testData);
		qbMatrix2<double> eigenvectors;
		int testResult2 = qbPCA::qbPCA(X, eigenvectors);
		qbMatrix2<double> V, part2;
		eigenvectors.Separate(V, part2, 2);
		qbMatrix2<double> newX = (V.Transpose() * X.Transpose()).Transpose();
		dstovec(newX,result);
	}
	//Convert 2D vector "Data" to 1D vector "testData"
	void vectods(vector<vector<double>> &Data,vector<double> &testData){
		int r=Data.size();
		int c=Data[0].size();
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				testData.push_back(Data[i][j]);
		}
	}
	//Convert qbMatrix2 to 2D vector i.e result
	void dstovec(qbMatrix2<double> &newX,vector<vector<double>> &result){
		int r=result.size();
		for(int i=0;i<r;i++){
			for(int j=0;j<2;j++)
				result[i][j]=newX.GetElement(i,j);
		}
	}
}
