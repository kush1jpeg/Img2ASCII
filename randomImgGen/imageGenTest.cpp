#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream image; // image named object
    image.open("image.ppm");
    if (image.is_open())
    {
        image << "P3" << "\n"; // Writing to the image.ppm
        image << "290 290" << "\n";
        image << "255"<< "\n"; // creating a header for the ppm format

        for (int x = 0; x < 100; x++)
        {
            for (int y = 0; y < 100; y++)
           
            { 
                image << ((3+x) + y) % 256 << " " << (x + 3*y) % 256 << " " << (y * x) % 256 << "\n"; // to assign rgb values to each pixel
            }
        }
    }
    image.close();
}