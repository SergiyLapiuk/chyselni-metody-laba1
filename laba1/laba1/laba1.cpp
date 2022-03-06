#include <iostream> //Lapiuk Sergiy. Variant 4. K-25
#include <cmath>
#include <iomanip>

double tusk1();
double signum(double v);
double method1(double a, double b);
double max3(double a, double b, double c);
double method2(double a, double b, double x_0);
double tusk2();
double min3(double a, double b, double c);
double method3_1(double a, double b);
double f1(double x);
double f1_(double x);
double method3_2(double a, double b);
double f2(double x);
double f2_(double x);
double tusk3();

using namespace std;

int a1 = 1;
int b1 = 0;
int c1 = -7;
int d1 = -6;
int index1 = 1;

int a2 = 1;
int b2 = -6;
int c2 = 5;
int d2 = 12;
int index2 = 1;

int index3 = 1;

double epsilon = pow(10, -3);


int main()
{
    int ans = 0;
    cout << "Change accuracy?" << endl;
    cout << "Yes - 1 No - 2" << endl;
    cin >> ans;
    if (ans == 1) {
        cout << "Enter the degree of accuracy" << endl;
        int k = 0;
        cin >> k;
        epsilon = pow(10, k);
    }
    cout << "1 - Method of division in half" << endl;
    cout << "2 - Newton`s method" << endl;
    cout << "3 - Simple iteration method" << endl;
    cout << "4 - To finish work" << endl;
    while (ans == 1 || ans == 2 || ans == 3) {
        cin >> ans;
        switch (ans) {
        case 1:
        {
            cout << "1. Method of division in half" << endl << "   x^3 - 7x - 6 = 0" << endl << endl;
            cout << "Maximum solution: " << tusk1() << endl;
            break;
        }
        case 2:
        {
            cout << "2. Newton`s method" << endl << "   x^3 - 6x^2 + 5x + 12 = 0" << endl << endl;
            cout << "Minimum solution: " << tusk2() << endl;
            break;
        }
        case 3:
        {
            cout << "3. Simple iteration method" << endl << "   x^3 + 3x^2 - x - 3 = 0" << endl << endl;
            cout << "Maximum solution: " << tusk3() << endl;
            break;
        }
        }
    }
    return 0;
}

double tusk1() {
    int a1_ = 3 * a1;
    int b1_ = 2 * b1;
    int c1_ = c1;
    
    double d = b1_ * b1_ - 4 * a1_ * c1_;
    double x1 = ((-1) * b1_ - sqrt(d)) / (2 * a1_);
    double x2 = ((-1) * b1_ + sqrt(d)) / (2 * a1_);
    
    cout << "First solution:" << endl;
    cout << "Number of inerations " << (int)(log((x1 - (-3)) / epsilon) / log(2)) - 1 << endl << endl;
    cout << "   " << "x_n" << "                 " << "f(x_n)" << endl;
    double res1 = method1(-3, x1); 
    cout << "x = " << res1 << endl;
    cout << endl;
    index1 = 1;

    cout << "Second solution: " << endl;
    cout << "Number of inerations " << (int)(log((x2 - x1) / epsilon) / log(2)) - 1 << endl << endl;
    cout << "   " << "x_n" << "                 " << "f(x_n)" << endl;
    double res2 = method1(x1, x2);
    cout << "x = " << res2 << endl;
    cout << endl;
    index1 = 1;

    cout << "Third solution: " << endl;
    cout << "Number of inerations " << (int)(log((4 - x2) / epsilon) / log(2)) - 1 << endl << endl;
    cout << "   " << "x_n" << "                 " << "f(x_n)" << endl;
    double res3 = method1(x2, 4);
    cout << "x = " << res3 << endl;
    cout << endl;
    index1 = 1;

    return max3(res1, res2, res3);
}

double method1(double a, double b) {
    double x = (a + b) / 2;

    double f_x = pow(x, 3) - 7*x - 6;
    cout << setw(3) << left << index1 << setw(20) << left << x << setw(25) << left << f_x << endl;
    index1++;
    double f_a = pow(a, 3) - 7 * a - 6;
    double f_b = pow(b, 3) - 7 * b - 6;
    

    double a_new = 0;
    double b_new = 0;

    if (signum(f_a) == signum(f_x)) {
        a_new = x;
    }
    else {
        a_new = a;
    }

    if (signum(f_b) == signum(f_x)) {
        b_new = x;
    }
    else {
        b_new = b;
    }

    double x_new = (a_new + b_new) / 2;

    if (abs(x_new - x) <= 2 * epsilon) return (x_new + x) / 2;
    else method1(a_new, b_new);
}

double tusk2() {
    cout << "First solution:" << endl;
    double res1 = method2(-1.5, -0.5, -1.5);
    cout << "x = " << res1 << endl;
    cout << endl;
    index2 = 1;

    cout << "Second solution: " << endl;
    double res2 = method2(2.5, 3.2, 2.5);
    cout << "x = " << res2 << endl;
    cout << endl;
    index2 = 1;

    cout << "Third solution: " << endl;
    double res3 = method2(3.8, 4.1, 4.1);
    cout << "x = " << res3 << endl;
    cout << endl;
    index2 = 1;

    return min3(res1, res2, res3);
}

double method2(double a, double b, double x_0) {
    int a2_ = 3; // 3x^2 - 12x + 5 - перша похідна
    int b2_ = b2 * 2;
    int c2_ = c2;

    int a2__ = a2_ * 2; // 6x - 12 - друга похідна
    int b2__ = b2_;

    double m1a = abs(a2_ * a * a + b2_ * a + c2_);
    double m1b = abs(a2_ * b * b + b2_ * b + c2_);
    double M2a = abs(a2__ * a + b2__);
    double M2b = abs(a2__ * b + b2__);

    double m1 = 0;
    double M2 = 0;

    if (m1a < m1b)
        m1 = m1a;
    else
        m1 = m1b;

    if (M2a > M2b)
        M2 = M2a;
    else
        M2 = M2b;
    
    double q = (M2 * abs(b - a)) / (2 * m1); 
    int count_i = (int)(log((log(abs(b - a) / epsilon)) / log(1 / q) + 1) / log(2) + 1) + 1;
    cout << "Number of inerations " << count_i + 1 << endl;
    cout << "   " << "x_n" << "                 " << "f(x_n)" << endl;
    double x = x_0;
    double x_new = 0;

    double f_x = a2 * pow(x, 3) + b2 * pow(x, 2) + c2 * x + d2;
    cout << setw(3) << left << index2 << setw(20) << left << x << setw(25) << left << f_x << endl;
    index2++;

    for (int i = 0; i < count_i; i++) {
        x_new = x - (a2 * pow(x, 3) + b2 * pow(x, 2) + c2 * x + d2) / (a2_ * pow(x, 2) + b2_ * x + c2_);
        x = x_new;
        f_x = a2 * pow(x, 3) + b2 * pow(x, 2) + c2 * x + d2;
        cout << setw(3) << left << index2 << setw(20) << left << x << setw(25) << left << f_x << endl;
        index2++;
    }
    return x_new;
}

double tusk3() {
    cout << "First solution:" << endl;
    double res1 = method3_1(-5, -2);
    cout << "x = " << res1 << endl;
    cout << endl;
    index3 = 1;

    cout << "Second solution: " << endl;
    double res2 = method3_2(-2, -0.5);
    cout << "x = " << res2 << endl;
    cout << endl;
    index3 = 1;

    cout << "Third solution: " << endl;
    double res3 = method3_2(0.5, 3);
    cout << "x = " << res3 << endl;
    cout << endl;
    index3 = 1;

    return max3(res1, res2, res3);
}

double method3_1(double a, double b) {
    double q = 0;
    if (abs(f1_(a)) > abs(f1_(b)))
        q = abs(f1_(a));
    else
        q = abs(f1_(b));

    double x = (a + b) / 2;
    int n = (int)(log(abs(f1(x) - x) / ((1 - q) * epsilon)) / log(1 / q)) + 1;
    double x_new = 0;
    double f_x = (pow(x, 3) + 3 * pow(x, 2) - x - 3);

    cout << "Number of inerations " << n + 1 << endl;
    cout << "   " << "x_n" << "                 " << "f(x_n)" << endl;

    cout << setw(3) << left << index2 << setw(20) << left << x << setw(25) << left << f_x << endl;
    index3++;
    
    for (int i = 0; i < n; i++) {
        x_new = f1(x);
        x = x_new;
        f_x = (pow(x, 3) + 3 * pow(x, 2) - x - 3);
        cout << setw(3) << left << index3 << setw(20) << left << x << setw(25) << left << f_x << endl;
        index3++;
    }
    /*while (1) {
        x_new = f1(x);
        if (abs(x - x_new) < ((1 - q) / q) * epsilon) break;
        x = x_new;
        f_x = (pow(x, 3) + 3 * pow(x, 2) - x - 3);
        cout << x << "     " << f_x << endl;
    }*/
    return x;
}


double method3_2(double a, double b) {
    double q = 0;
    if (abs(f2_(a)) > abs(f2_(b)))
        q = abs(f2_(a));
    else
        q = abs(f2_(b));

    double x = (a + b) / 2;
    int n = (int)(log(abs(f2(x) - x) / ((1 - q) * epsilon)) / log(1 / q)) + 1;
    double x_new = 0;
    double f_x = (pow(x, 3) + 3 * pow(x, 2) - x - 3);

    cout << "Number of inerations " << n + 1 << endl;
    cout << "   " << "x_n" << "                 " << "f(x_n)" << endl;

    cout << setw(3) << left << index3 << setw(20) << left << x << setw(25) << left << f_x << endl;
    index3++;

    for (int i = 0; i < n; i++) {
        x_new = f2(x);
        x = x_new;
        f_x = (pow(x, 3) + 3 * pow(x, 2) - x - 3);
        cout << setw(3) << left << index3 << setw(20) << left << x << setw(25) << left << f_x << endl;
        index3++;
    }

    return x;
}

double signum(double v)
{
    if (v > 0)
        v = 1;
    if (v < 0)
        v = -1;
    if (v == 0)
        v = 0;
    return v;
}

double max3(double a, double b, double c) {
    double max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

double min3(double a, double b, double c) {
    double min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

double f1(double x) {      //Функція фі для пошуку першого кореня
    double s = pow(abs(x + 3 - 3 * x * x), 1.0 / 3.0);
    if (x + 3 - 3 * x * x < 0)
        return s * (-1);
    else return s;
}

double f1_(double x) {    //ПОхідна функції фі
    double p = 2.0 / 3.0;
    double o = x + 3 - 3 * x * x;
    double s = pow(abs(o), p);
    double res = (1 - 6 * x) / (3 * s);
    return res;
}

double f2(double x) {     //Функція фі для пошуку другого та третього коренів
    double s = pow(abs((3 * x * x) / (x * x + 3 * x - 1)), 1.0 / 3.0);
    if ((3 * x * x) / (x * x + 3 * x - 1) < 0)
        return s * (-1);
    else
        return s;
}

double f2_(double x) {    //Похідна функції фі
    double ch = (9 * x * x - 6 * x) / (pow((x * x + 3 * x - 1), 2));
    double z = 3 * pow(abs((3 * x * x) / (x * x + 3 * x - 1)), 2.0 / 3.0);
    return ch / z;
}

