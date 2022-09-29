#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> FiniteDiff(){
    std::vector<double> T0, T;

    int m = 100;
    double t = 0.001;
    int n = 10;
    // double h = 1/9.0;

    // T.resize(n);
    T0.resize(n);
    // for (size_t i = 0; i < m + 1; i++)
    // {
    //     T[i].resize(n);
    // }
    for (size_t i = 0; i < n - 1; i++)
    {
        T0[i] = 0;
    }
    T0[n - 1] = 1;
    T = T0;
    // for (size_t i = 0; i < m + 1; i++)
    // {
    //     T[i][n - 1] = 1;
    // }
    
    for (size_t j = 0; j < m; j++)
    {    
        //T[j][n - 1] = 1;
        for (size_t i = 1; i < n - 1; i++)
        {
            T[i] = t*(T0[i - 1] - 2*T0[i] + T0[i + 1])*(n - 1)*(n - 1) + T0[i];
            // T[j + 1][i] = t*a*b + c;
        }
        T0 = T;

    }
    
    return T;
}


int main(){
    std::vector<double> T = FiniteDiff();
    // T.erase(T.begin());

	// for (auto i: T){
	// 	for(double j: i){
	// 		std::cout << j << "\t";
	// 	}
	// 	std::cout << std::endl;
	// }
    for(double i: T) std::cout << i << "\t";
}