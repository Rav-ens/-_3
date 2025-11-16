#include <cstdint>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <stdio.h>
#include <iomanip>
#include <random>

using namespace std;

int n;
mt19937 mt(time(nullptr)); 


class Circle {
public:
    double x, y, r;
};

bool is_in_c(double x, double y, const Circle& circle) {
    double dx = x - circle.x;
    double dy = y - circle.y;
    return dx * dx + dy * dy <= circle.r * circle.r;
}

bool is_in(double px, double py, const Circle& c1, const Circle& c2, const Circle& c3) {
    return is_in_c(px, py, c1) && 
           is_in_c(px, py, c2) && 
           is_in_c(px, py, c3);
}

double operation(Circle circles[],int mnx,int mxx, int mny, int mxy, int pnt) {

    const int num_samples = pnt;
    int points_inside = 0;
    std::uniform_real_distribution<double> dx(mnx, mxx);
   	std::uniform_real_distribution<double> dy(mny, mxy); 
    for (int i = 0; i < num_samples; i++) {
        double x = dx(mt);
        double y = dy(mt);
        
        if (is_in(x, y, circles[0], circles[1], circles[2])) {
            points_inside++;
        }
    }
    
    double ans = double(points_inside) / num_samples * (mxx - mnx) * (mxy - mny);
    
    return ans;
}
int main(){
	double mnx=0.8;
	double mxx = 2.2;
	double mny = 0.8;
	double mxy = 2.2;
	double ans = 0.944517186;
	Circle circles[3];
	for (int i = 0; i < 3; i++) {
        std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }
	for(int i = 100; i <= 100000;i+=500) {
		std::cout<<i<<" " << operation(circles,mnx,mxx,mny,mxy,i)<<"\n";
	}
}
