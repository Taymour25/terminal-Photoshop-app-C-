#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char pic[SIZE][SIZE][RGB];

void getpic ();
void returnpic ();
void hlmirror ();
void hrmirror();
void vlmirror();
void vrmirror();

int main()
{
  int choise;
  cout<<" 1-horizontal left mirror \n 2-horizontal right mirror \n 3-vertical left mirror \n 4-vertical right mirror \n Enter your choice here : ";
  cin>>choise;
  getpic();
  if(choise==1){
        hlmirror();
  }else if (choise==2)
  {
      hrmirror();
  }else if (choise==3)
  {
      vlmirror();
  }else if (choise==4)
  {
      vrmirror();
  }
  
  
  
  returnpic();
  return 0;
}

void getpic () {
   char userpic[100];

   cout << "Enter the source image file name: ";
   cin >> userpic;

   strcat (userpic, ".bmp");
   readRGBBMP(userpic, pic);
}

void returnpic () {
   char userpic[100];

   cout << "Enter the target image file name: ";
   cin >> userpic;

   strcat (userpic, ".bmp");
   writeRGBBMP(userpic, pic);
}

void hlmirror() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< (SIZE+1)/2; j++) {
       for (int k = 0; k < RGB; k++)
        {
          pic[i][j][k]=pic[i][-j][k];
        }
    }
  }
}

void hrmirror() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< (SIZE+1)/2; j++) {
        for (int k = 0; k < RGB; k++)
        {
          pic[i][-j][k]=pic[i][j][k];
        }
        
    }
  }
}

void vlmirror() {
  for (int i = 0; i < (SIZE+1)/2; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k = 0; k < RGB; k++)
        {
          pic[255-i][-j][k]=pic[i][j][k];
        }
    }
  }
}

void vrmirror() {
  for (int i = 0; i < (SIZE+1)/2; i++) {
    for (int j = 0; j< SIZE; j++) {
       for (int k = 0; k < RGB; k++)
        {
          pic[i][-j][k]=pic[255-i][j][k];
        }
    }
  }
}

