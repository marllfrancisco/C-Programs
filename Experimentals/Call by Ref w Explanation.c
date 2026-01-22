#include <stdio.h>

int trace (int x, int *y, int z){   //kahit hindi identical yung variable, basta aligned yung pag call 

    x = 1 , *y = 5, z = 7;
    printf(" %2d, %2d, %2d \n",     x,*y,z);    //lagi tong ipapalabas kasi 3 times na mention yung func sa main 

    // int function pero walang return?
    // Basically pag walang return yung function, nasa loob ng parenthesis yung ibabalik sa main
    // yung may asterisk (pointer) lang yung na update
}

int main (){
    int x = 3, y = 6, z = 9;
    printf(" %2d, %2d, %2d \n\n",     x,y,z);   //yung initial values ang ilalabas
                        //notice that yung may & lang ang na-update from function
    trace(y, &x, z);    //like here, 2nd ang may call so retain that initial values of y and z
    printf(" %2d, %2d, %2d \n\n",     x,y,z);

    trace(x, &y, z);    // Yung mga nasa loob lang ng parenthesis yung bumalik, specifically yung mga & lang
    printf(" %2d, %2d, %2d \n\n",     x,y,z);

    trace(x, &z, y);
    printf(" %2d, %2d, %2d \n\n",     x,y,z);

}