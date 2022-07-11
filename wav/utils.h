#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Read data from a csv file "name" to a 2D vector
void readData(string name,vector<vector<double>> &Data,int rows,int cols);
//Save data from a 2D vector to a csv file "name"
void saveData1(string name,vector<vector<double>> &result);
#endif
