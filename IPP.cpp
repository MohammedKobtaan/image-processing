#include <iostream>
#include "Image_Class.h"
using namespace std;


//Invert filter.
void invert(string uploaded_photo, string save_photo)
{
    Image image(uploaded_photo);
    for(int i=0 ; i<image.width ; i++)
    {
        for(int j=0 ; j<image.height ; j++)
        {
            for(int k=0 ; k<3 ; k++)
            {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
    image.saveImage(save_photo);
    return;
}











//Bright_dark filter to make photo more bright or more dark.
void bright_dark(string uploaded_photo, string save_photo, int i)
{
    Image image(uploaded_photo);
    if(i == 1) // brightness
    {
        for(int i = 0; i <image.width ; i++)
        {
            for(int j=0 ; j<image.height ; j++)
            {
                for(int k=0 ; k<3 ; k++)
                {
                    unsigned int num = image(i, j, k);
                    num *= 1.5;
                    if(num > 255) num = 255;
                    image(i, j, k) = num;
                }
            }
        }
    }




    else if (i == 2)// darkness
    {
        for(int i = 0; i <image.width ; i++)
        {
            for(int j=0 ; j<image.height ; j++)
            {
                for(int k=0 ; k<3 ; k++)
                {
                    image(i, j, k) = image(i, j, k) / 2;
                }
            }
        }
    }
    image.saveImage(save_photo);
    return;
}





int main()
{
    string uploaded_photo;
    string save_photo;
    int temp;
    cout << "Which photo you wan edit? with formats.\nWhere you want to save it. with formats.\n";
    cout << "which filter you want to apply:\n1. brightness_darkness\n2. invert\n\n";
    getline(cin, uploaded_photo);
    getline(cin, save_photo);
    cin >> temp;




    if(temp == 1) // brightness_darkness
    {
        cout << "1. brightness\n2. darkness\n\n";
        cin >> temp;
        bright_dark(uploaded_photo, save_photo, temp);
    }





    else if(temp == 2) // invert
    {
        invert(uploaded_photo, save_photo);
    }






    return 0;
}