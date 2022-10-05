//Write a menu driven program to read, display, add and subtract two complex numbers
#include <iostream>
using namespace std;

class Complex
{
    private:
        int real;
        int imag;
    
    public:
        void getDetails();
        void displayDetails();
        void add(Complex a, Complex b);
        void subtract(Complex a, Complex b);
};

void Complex::getDetails()
{
    cout << "Enter real part of number: ";
    cin >> real;
    cout << "Enter imaginary part of number: ";
    cin >> imag;
}

void Complex::displayDetails()
{
    cout << real << "+" << imag << "i" << endl;
}

void Complex::add(Complex a, Complex b)
{
    real = a.real + b.real;
    imag = a.imag + b.imag;
}

void Complex::subtract(Complex a, Complex b)
{
    real = a.real - b.real;
    imag = a.imag - b.imag;
}

void menu()
{
    cout <<"Menu: " << endl;
    cout << "1.\tRead Numbers" << endl;
    cout << "2.\tDisplay Numbers" << endl;
    cout << "3.\tAdd Numbers" << endl ;
    cout << "4.\tSubtract Numbers" << endl;
    cout << "5\tExit" << endl;
}

int main()
{
    Complex com;
    int n;
    int a,b,c;

    do
    {
        menu();
        cin >> n;
        switch(n)
        {
            case 1:
                a.getDetails();
                b.getDetails();
                break;
            case 2:
                a.displayDetails();
                b.displayDetails();
                break;
            case 3:
                a.getDetails();
                b.getDetails();
                c.add(a,b);
                c.displayDetails();
                break;
            case 4:
                a.getDetails();
                b.getDetails();
                c.subtract(a,b);
                c.displayDetails();
                break;
            case 5:
                break;
            default:
                cout << "Invalid input." << endl;
        }
    }
    while(n!=5);

    return 0;
}