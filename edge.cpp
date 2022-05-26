#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char pic[SIZE][SIZE];

void getpic ();
void returnpic ();
void changepic ();

int main()
{
  getpic();
  changepic();
  returnpic();
  return 0;
}

void getpic () {
   char userpic[100];

   cout << "Enter the source image file name: ";
   cin >> userpic;

   strcat (userpic, ".bmp");
   readGSBMP(userpic, pic);
}

void returnpic () {
   char userpic[100];

   cout << "Enter the target image file name: ";
   cin >> userpic;

   strcat (userpic, ".bmp");
   writeGSBMP(userpic, pic);
}

void changepic() {
  for (int i = 0; i < (SIZE-1); i++) {
    for (int j = 0; j< (SIZE-1); j++) {
        if (pic[i][j] - pic[i+1][j+1]>7 or pic[i][j] - pic[i+1][j+1]>-7 )
            pic[i][j] = 255;
        else
            pic[i][j] = 0;


    }
  }
}
