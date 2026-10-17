// ConsoleApplication50.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex a) {
        return Complex(real + a.real, imag + a.imag);
    }

    Complex operator-(Complex a) {
        return Complex(real - a.real, imag - a.imag);
    }

    Complex operator*(Complex a) {
        return Complex(real * a.real - imag * a.imag,
            real * a.imag + imag * a.real);
    }

    Complex operator/(Complex a) {
        double d = a.real * a.real + a.imag * a.imag;

        if (d == 0) {
            cout << "Error!" << endl;
            return Complex();
        }

        return Complex((real * a.real + imag * a.imag) / d,
            (imag * a.real - real * a.imag) / d);
    }

    void input() {
        cout << "Real: ";
        cin >> real;
        cout << "Imag: ";
        cin >> imag;
    }

    void output() {
        cout << real;

        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";

        cout << endl;
    }
};

int main() {
    Complex a, b, c;

    cout << "First:" << endl;
    a.input();

    cout << "Second:" << endl;
    b.input();

    cout << "+ : ";
    c = a + b;
    c.output();

    cout << "- : ";
    c = a - b;
    c.output();

    cout << "* : ";
    c = a * b;
    c.output();

    cout << "/ : ";
    c = a / b;
    c.output();

    return 0;
}
