#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std; 


/*Write a program that does a simple linear regression on the gpa_sat.csv data.

Open and read in the CSV data. Since you know that there are only 100 data points you can read the x data (the GPA values) and y values (the SAT score) into two vectors of size 100. Or you can create a DataPoint struct that can hold both values per line.
Calculate the mean of the x values and the mean of the y values
Use the x-mean, y-mean and the data points to calulate β (beta)
Use the x-mean, y-mean and β to calculate ⍺ (alpha)
Now we need to calcuate the R-squared value

First we need to calculate the 𝑓i data points. These points represent the values predicted by the model for the xi's in the input data.
Create a vector to store the 𝑓i values. Iterate through the xi values and use the model (linear equation with ⍺ and β) to generate the 𝑓i's
Use the yi's and the 𝑓i's to calculate SSres
Use the yi's and the y-mean to calculate SStot
Calculate R-squared = 1 - SSres/SStot
Now print out the results of your linear regression

Print out a message with the model the equation predicts: "SAT score = {alpha} + {beta}*GPA" replacing {alpha} and {beta} with the values you calculated.
Print out the R-squared value*/


struct DataPoint{
    double gpa;
    double sat;
};

double calculateMean(const vector<double>& values){
    double sum = 0.0;
    for (double value : values){
        sum += value;
    }
    return sum / values.size();
}

int main() {
    ifstream ifile("gpa_sat.csv");
    if (!ifile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    vector<DataPoint> data;
    string line;

    getline(ifile, line);

    while (getline(ifile, line)){
        stringstream ss(line);
        string gpa_pt, sat_pt;
        getline(ss, gpa_pt, ',');
        getline(ss, sat_pt, ',');
        DataPoint point;
        point.gpa = stod(gpa_pt);
        point.sat = stod(sat_pt);
        data.push_back(point);
    }
    vector<double> x_values;
    vector<double> y_values;
    for (const DataPoint& point : data){
        x_values.push_back(point.gpa);
        y_values.push_back(point.sat);
    }
    
    double x_mean = calculateMean(x_values);
    double y_mean = calculateMean(y_values);
    
    //beta
    double numerator = 0.0;
    double denominator = 0.0;
    for (size_t i = 0; i < data.size(); i++){
        numerator += (x_values[i] - x_mean) * (y_values[i] - y_mean);
        denominator += pow(x_values[i] - x_mean, 2);
    }
    double beta = numerator / denominator;
    
    //alpha
    double alpha = y_mean - (beta * x_mean);
    
    //fi
    vector<double> f_values;
    for (double x : x_values){
        double f_i = alpha + (beta *x);
        f_values.push_back(f_i);
    }

    double SStot = 0.0;
    for (double y : y_values){
        SStot += pow(y - y_mean, 2);
    }
    double SSres = 0.0;
    for (size_t i = 0; i < data.size(); i++){
        SSres += pow(y_values[i] - f_values[i], 2);
    }

    


    double r_squared = 1 - (SSres / SStot);
    cout << fixed << setprecision(4);
    cout << "SAT score = " << alpha << " + " << beta << "*GPA" << endl;
    cout << "R-squared = " << r_squared << endl;
    
    return 0;
}

