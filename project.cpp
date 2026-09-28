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
    cout << "Enter photo you want to edit. with formats\n\n";
    string uploaded_photo;
    cin >> uploaded_photo;
    string save_photo;
    cout << "Enter number which filter you want to do.\n1. brightness_darkness\n2. invert\n\n";
    int temp;
    cin >> temp;





    if(temp == 1)
    {
        cout << "1. brightness\n2. darkness\n\n";
        cin >> temp;
        cout << "Where you want to save it enter the name with formats.\n\n";
        cin >> save_photo;
        bright_dark(uploaded_photo, save_photo, temp);
    }





    else if(temp == 2)
    {
        cout << "Where you want to save it enter the name with formats.\n\n";
        cin >> save_photo;
        invert(uploaded_photo, save_photo);
    }






    return 0;
}