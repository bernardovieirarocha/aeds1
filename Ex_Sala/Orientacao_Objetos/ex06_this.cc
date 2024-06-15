#include <iostream>
using namespace std;

class test{
    private:
        int x;
        int y;
    public:
        // Constructor
        test(int x = 0, int y = 0 ){
            this->x = x;
            this->y = y;
        }
        test &setX(int a) { x=a ; return *this;}
        test &setY(int b) {y=b ; return *this;}
        void print(){
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;

        }
};

int main(void) {
    test obj(1,10);
    int x = 20;
    int y = 40;

    obj.setX(x).setY(40);
    
    obj.print();
}