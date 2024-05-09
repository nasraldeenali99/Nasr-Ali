

#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "Image_Class.h"
#include <string>
using namespace std;



Image gary_image(string image1_name)
{
    Image image1(image1_name);
    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            int avg = 0;
            for (int k = 0; k < 3; k++)
            {
                avg += image1(i,j,k);
                avg /= 3;
            }
            

            for (int k = 0; k < image1.channels; k++)
            {
                image1(i,j,k) = avg;
            }
        }
    }
    return image1;
}



Image black_white(string image1_name)
{
    Image image1(image1_name);
    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            int avg = 0;
            for (int k = 0; k < 3; k++)
            {
                avg += image1(i,j,k);
            }
            avg /= 3;
            if (avg < 127.5)
            {
                avg = 0;
            }
            else{avg = 255;}
            

            for (int k = 0; k < image1.channels; k++)
            {
                image1(i,j,k) = avg;
            }
        }
    }
    return image1;
}



Image light_image(string image1_name)
{
    Image image1(image1_name);
    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {

                int avg = static_cast<int> (image1(i,j,k) * 1.5);
                image1(i,j,k) = avg > 255 ? 255 : avg;
            }
        }
    }
    return image1;
}



Image dark_image(string image1_name)
{
    Image image1(image1_name);
    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image1(i,j,k) = image1(i,j,k)/2;
            }
        }
    }
    return image1;
}





Image flip_image(string image1_name)
{
    Image image1(image1_name);
    int width = image1.width;
    int height = image1.height;
    
    for (int i = 0; i < width / 2; i++)
    {
        for (int j = 0; j < height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                swap(image1.imageData[j * width * 3 + i * 3 + k], image1.imageData[j * width * 3 + k + (width - i - 1) * 3]);
            }
        }
    }


    for (int j = 0; j < height / 2; j++)
    {
        for (int i = 0; i < width; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                swap(image1.imageData[j * width * 3 + i * 3 + k], image1.imageData[(height - j - 1) * width * 3 + i * 3 + k]);
            }
        }
    }

    return image1;
}




Image invert_image(string image1_name)
{
    Image image1(image1_name);
    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            for (int k = 0; k < image1.channels; k++)
            {
                image1(i,j,k) = 255 - image1(i,j,k);
            }
        }
    }
    return image1;
}




Image blur_image(string image1_name)
{
        Image image(image1_name);
        Image blurred(image.width, image.height);

    for (int i = 10; i < image.width - 10; i++)
    {
        for (int j = 10; j < image.height - 10; j++) 
        {
            for (int k = 0; k < image.channels; k++) 
                    {
                            
                 blurred(i,j,k) = (
                    image(i-10,j-10,k) + image(i-9,j-10,k) + image(i-8,j-10,k) + image(i-7,j-10,k) + image(i-6,j-10,k) +
                    image(i-10,j-9,k) + image(i-9,j-9,k) + image(i-8,j-9,k) + image(i-7,j-9,k) + image(i-6,j-9,k) +
                    image(i-10,j-8,k) + image(i-9,j-8,k) + image(i-8,j-8,k) + image(i-7,j-8,k) + image(i-6,j-8,k) +
                    image(i-10,j-7,k) + image(i-9,j-7,k) + image(i-8,j-7,k) + image(i-7,j-7,k) + image(i-6,j-7,k) +
                    image(i-10,j-6,k) + image(i-9,j-6,k) + image(i-8,j-6,k) + image(i-7,j-6,k) + image(i-6,j-6,k) +
                    
                    image(i-5,j-5,k) + image(i-4,j-5,k) + image(i-3,j-5,k) + image(i-2,j-5,k) + image(i-1,j-5,k) +
                    image(i-5,j-4,k) + image(i-4,j-4,k) + image(i-3,j-4,k) + image(i-2,j-4,k) + image(i-1,j-4,k) +
                    image(i-5,j-3,k) + image(i-4,j-3,k) + image(i-3,j-3,k) + image(i-2,j-3,k) + image(i-1,j-3,k) +
                    image(i-5,j-2,k) + image(i-4,j-2,k) + image(i-3,j-2,k) + image(i-2,j-2,k) + image(i-1,j-2,k) +
                    image(i-5,j-1,k) + image(i-4,j-1,k) + image(i-3,j-1,k) + image(i-2,j-1,k) + image(i-1,j-1,k) +

                    image(i,j-10,k) + image(i+1,j-10,k) + image(i+2,j-10,k) + image(i+3,j-10,k) + image(i+4,j-10,k) +
                    image(i,j-9,k) + image(i+1,j-9,k) + image(i+2,j-9,k) + image(i+3,j-9,k) + image(i+4,j-9,k) +
                    image(i,j-8,k) + image(i+1,j-8,k) + image(i+2,j-8,k) + image(i+3,j-8,k) + image(i+4,j-8,k) +
                    image(i,j-7,k) + image(i+1,j-7,k) + image(i+2,j-7,k) + image(i+3,j-7,k) + image(i+4,j-7,k) +
                    image(i,j-6,k) + image(i+1,j-6,k) + image(i+2,j-6,k) + image(i+3,j-6,k) + image(i+4,j-6,k) +
                
                    image(i-5,j+5,k) + image(i-4,j+5,k) + image(i-3,j+5,k) + image(i-2,j+5,k) + image(i-1,j+5,k) +
                    image(i-5,j+4,k) + image(i-4,j+4,k) + image(i-3,j+4,k) + image(i-2,j+4,k) + image(i-1,j+4,k) +
                    image(i-5,j+3,k) + image(i-4,j+3,k) + image(i-3,j+3,k) + image(i-2,j+3,k) + image(i-1,j+3,k) +
                    image(i-5,j+2,k) + image(i-4,j+2,k) + image(i-3,j+2,k) + image(i-2,j+2,k) + image(i-1,j+2,k) +
                    image(i-5,j+1,k) + image(i-4,j+1,k) + image(i-3,j+1,k) + image(i-2,j+1,k) + image(i-1,j+1,k) +

                    image(i,j+5,k) + image(i+1,j+5,k) + image(i+2,j+5,k) + image(i+3,j+5,k) + image(i+4,j+5,k) +
                    image(i,j+4,k) + image(i+1,j+4,k) + image(i+2,j+4,k) + image(i+3,j+4,k) + image(i+4,j+4,k) +
                    image(i,j+3,k) + image(i+1,j+3,k) + image(i+2,j+3,k) + image(i+3,j+3,k) + image(i+4,j+3,k) +
                    image(i,j+2,k) + image(i+1,j+2,k) + image(i+2,j+2,k) + image(i+3,j+2,k) + image(i+4,j+2,k) +
                    image(i,j+1,k) + image(i+1,j+1,k) + image(i+2,j+1,k) + image(i+3,j+1,k) + image(i+4,j+1,k)
                ) / 225;  


                    }
                }
            }
    return blurred;
}




Image fancy_frame (string image_name)
{
    Image image1(image_name);

    int frameSize = 20;

    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            for (int k = 0; k < image1.channels; k++)
            {
                if (i < frameSize || i >= image1.width - frameSize || j < frameSize || j >= image1.height - frameSize)
                {
                    image1(i, j, k) = 255;
                }

                if ((i >= frameSize && i < frameSize + 2) || (i < image1.width - frameSize && i >= image1.width - frameSize - 2) ||
                    (j >= frameSize && j < frameSize + 2) || (j < image1.height - frameSize && j >= image1.height - frameSize - 2))
                {
                    image1(i, j, k) = 0; 
                }
            }
        }
    }
    return image1;
}





Image simple_frame (string image_name)
{
    Image image1(image_name);

    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            for (int k = 0; k < image1.channels; k++)
            {

                //frist
                if ((i > 5 && i < 10)||(image1.width - i > 5 && image1.width - i < 10))
                {
                    image1(i,j,k) = 255;
                }
                //second
                if ((j > 5 && j < 10) || (image1.height - j > 5 && image1.height - j < 10))
                {
                    image1(i,j,k) = 255;
                }
                
            }
            
        }
    }

    return image1;
}





Image degree_90(string image_name)
{
    Image image1(image_name);
    Image image2(image1.height, image1.width);

    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            for (int k = 0; k < image1.channels; k++)
            {
                int i2 = j;
                int j2 = image1.width - i - 1;
                image2.setPixel(i2, j2, k, image1.getPixel(i, j, k));
            }
        }
    }


    return image2;
}



Image degree_180(string image_name)
{
    Image image1(image_name);
    Image image2(image1.width, image1.height);

    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            for (int k = 0; k < image1.channels; k++)
            {                
                int i2 = image1.width - 1 - i;
                int j2 = image1.height - 1 - j;
                image2.setPixel(i2, j2, k, image1.getPixel(i, j, k));
            }
        }
    }
    return image2;
}



Image detecting_image(string image_name)
{
    Image image(image_name);
    Image blurred(image.width, image.height);

    for (int i = 2; i < image.width - 2; i++) 
    {
        for (int j = 2; j < image.height - 2; j++)
        {
            for (int k = 0; k < image.channels; k++) 
            {
                blurred(i,j,k) = (  image(i-2,j-2,k)*0 + image(i-1,j-2,k)*0 + image(i,j-2,k)*0 +
                                    image(i+1,j-2,k)*0 + image(i+2,j-2,k)*0 +
                                    image(i-2,j-1,k)*0 + image(i-1,j-1,k)*0 + image(i,j-1,k)*0 +
                                    image(i+1,j-1,k)*0 + image(i+2,j-1,k)*0 +
                                    image(i-2,j,k)*0 + image(i-1,j,k)*0 + image(i,j,k) * -5 +
                                    image(i+1,j,k)*0 + image(i+2,j,k)*0 +
                                    image(i-2,j+1,k)*0 + image(i-1,j+1,k)*0 + image(i,j+1,k)*0 +
                                    image(i+1,j+1,k)*0 + image(i+2,j+1,k)*0 +
                                    image(i-2,j+2,k)*0 + image(i-1,j+2,k)*0 + image(i,j+2,k)*0 +
                                    image(i+1,j+2,k)*0 + image(i+2,j+2,k)*0
                                    )  ;
            }
        }
    }




    for (int i = 0; i < blurred.width ; i++) 
    {
        for (int j = 0; j < blurred.height ; j++)
        {
            for (int k = 0; k < blurred.channels; k++)
            {
                if (blurred(i,j,k) > 128)
                {
                    blurred(i,j,k) = 0;
                }
                else
                {
                    blurred(i,j,k)= 255;
                }
            }
        }
    }


    return blurred;
}



Image resize_iamge(string file_name){
Image im(file_name); 
    float newHeight, newWidth;

    cout << "Enter the new height: ";
    cin >> newHeight;
    cout << "Enter the new width: ";
    cin >> newWidth;

    float scaleX = newWidth / static_cast<float>(im.width);
    float scaleY = newHeight / static_cast<float>(im.height);

    Image image2(newWidth, newHeight);
    for (int y = 0; y < newHeight; y++)
    {
        for (int x = 0; x < newWidth; x++) 
        {
            int originalX = static_cast<int>(x / scaleX);
            int originalY = static_cast<int>(y / scaleY);
for (int k = 0; k < 3; k++)
{

            image2.setPixel(x, y,k, im.getPixel(originalX, originalY,k));
           }
        }
    }
    return image2;

}




Image crop_image(string file_name)
{
    Image im(file_name);
    int h ;
    int w ;
    cout << "enter height : ";
    cin >> h;
    cout << "enter width : ";
    cin >> w;
    Image croppedImage(w, h);

    int cw = w;
    int ch = h;
    for (int x = 0; x < cw; ++x)
    {
        for (int y = 0; y < ch; ++y)
        {
            for (int channel = 0; channel < im.channels; ++channel) 
            {
                croppedImage(x, y, channel) = im(x,y, channel);
            }
        }
    }
    return croppedImage;

}





Image merge_image(string file_name,string file_name2)
{

    Image image1(file_name), image2(file_name2);

    int min_width =min(image1.width, image2.width);
    int min_Height = min(image1.height,image2.height);

    Image MergeImage(min_width, min_Height);

    unsigned char pixel1, pixel2, MergePixel;

    for (int i = 0; i < image1.width; i++)
    {
        for (int j = 0; j < image1.height; j++)
        {
            for (int k = 0; k < image1.channels; k++)
            {
                pixel1 = image1(i, j, k);

                pixel2 = image2(i, j, k);

                MergePixel = (pixel1 + pixel2) / 2;

                MergeImage(i, j, k) = MergePixel;               
            }
         }

    }
    return MergeImage;

}



int main()
{
    
    
    
      

    //  cout  << "   * welcome to filters *  " << ;

    string image_file,image2_file;
    cout << "Enter IMAGE NAME  : ";cin >> image_file;
    int order;

    while(true){
    
       

        cout << endl<< "=================================" << endl << "  * welcome to filters *   " << endl<< "=================================\n";
        cout << "1- Grayscale Conversion\n" << "2- Black and White\n" << "3- Invert Image" << endl;
        cout << "4- Flip Image\n" << "5- Darking Image\n6- Lighting Image\n"<< "7- bluring Image\n" << "8- adding simple frame\n"
        <<"9- adding fancy frame\n" << "10- Rotate 90 degrees\n"<< "11- Rotate 180 degrees\n"<< "12- Rotate 270 degrees\n"  << \
        "13- detecting image\n" << "14- resize image\n"<<"15- crop image\n" <<"16- merge image\n" << "17- enter new image\n" << "18- exet\n" <<"enter here : " ; cin >> order;


        

        string image_file_resulte;

        if (order == 1)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = gary_image(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 2)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = black_white(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 3)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = invert_image(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 4)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = flip_image(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 5)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = dark_image(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 6)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = light_image(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 7)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = blur_image(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 8)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = simple_frame(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 9)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = fancy_frame(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 10)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image11 = degree_90(image_file);
            image11.saveImage(image_file_resulte);
            Image image1 = degree_180(image_file_resulte);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order ==11)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = degree_180(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 12)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = degree_90(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 13)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image11 = black_white(image_file);
            image11.saveImage(image_file_resulte); 
            Image image1 = detecting_image(image_file_resulte);
            image1.saveImage(image_file_resulte);
        }

        if (order == 14)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = resize_iamge(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 15)
        {
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = crop_image(image_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 16)
        {
            cout << "enter the name of the second image : ";
            cin >> image2_file;
            
            cout << "enter name for the result image : "; cin >> image_file_resulte;
            Image image1 = merge_image(image_file,image2_file);
            image1.saveImage(image_file_resulte);
            cout << "\nDone.\n\n";
        }

        if (order == 17)
        {
            cout << "enter name of the new image : "; cin >> image_file;
            cout << "\nDone.\n\n";
        }

        if (order == 18)
        {
            cout << "\nDone.\n\n";
            break;
        }
    }
    return 0 ;
}
