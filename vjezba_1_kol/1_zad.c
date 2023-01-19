#include <stdio.h>
#include <math.h>

int main ()
{
    float radius;
    float povrsina;

    printf("\n Unesi radius kruga:  ");
    scanf("%f", &radius);

    povrsina=pow(radius, 2)*3.14;

    printf("\n povrsina kruga je je: %.2f \n", povrsina);

    if(povrsina<12.3){
        printf("\n Mali krug\n");
    }
    else if(povrsina>=50.64){
        printf("\n Veeeeeliki krug\n");
    }
    else {
        printf("\n o-O krug O-o\n");
    }


    return 0;
}