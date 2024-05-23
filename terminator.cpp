#include <iostream>
using namespace std;

int main()
{
    char data[5];

    data[0] = 'h';
    data[1] = 'e';
    data[2] = 'l';
    data[3] = 'l';
    data[4] = 'o';
    
    int i = 0;
    while(i < 5){
        int ascii_counter = data[i];
        cout << data[i] << " :: " << ascii_counter << endl;
        i++;
    }
    return 0;
}