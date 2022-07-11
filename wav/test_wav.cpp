#include "WAVReader.h"
#include "pca.h"
#include "utils.h"
#include <fstream>
#include <cassert>
#include <typeinfo>
using namespace std;

int main(int argn, const char *argv[])
{
	WAVE wav;
	wav.parse( "./noisy_1.wav" );

	std::streambuf * buf;
	std::ostream* fp;

	ofstream outF;
	outF.open("Result.csv", std::ofstream::out );
	auto channelData = wav.getData( );
	int k=0;
	for( auto v : channelData )
	{
	    outF << v.first << ',';
	    k++;
	    for( auto vv : v.second ){
		outF << (double)vv;
	    }
	    outF << '\n';
	}
	outF.close();
	int nrSamples=k,nrComp=2;
	vector<vector<double>> Data(nrSamples,vector<double>(nrComp));
	readData("Result.csv",Data,nrSamples,nrComp);
	wisdom::PCA obj1;
	vector<vector<double>> result1(obj1.nrSamples,vector<double>(2));
	obj1.m1(Data,result1);
	saveData1("Result1.csv",result1);
    	return 0;
}
