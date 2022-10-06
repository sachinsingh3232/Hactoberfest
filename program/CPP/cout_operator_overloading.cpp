#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int i = 0, int j = 0) {
		x = i; y = j;
	}
	void print() {
		cout << "x = " << x << ", y = " << y << '\n';
	}
};

int main() {
	Point t(20, 20);
	t.print();
	t = 30; // Member x of t becomes 30
	t.print();
	return 0;
}
