#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Pizza
{
    public:

    string topping;
    int orderNumber = 1;

    void choose_toppings()
    {
        //string input;
        
        string fileName;

        //new file name
        fileName = "order";
        fileName += to_string(this->orderNumber);
        fileName += ".txt";

        cout << "put in toppings of your choise:" << endl;
        //ofstream orderFile("order.txt");
        ofstream orderFile(fileName);
        do
      
        {
            cin >> topping;
            orderFile << topping << endl;
            
        }while (topping != "END");
        orderFile.close();
        orderNumber++;
    }

};

int main(){

Pizza p1;
p1.choose_toppings();

    return 0;

}