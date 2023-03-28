#include<stdio.h>
#include<string.h>
#define MAX 20



typedef struct{
    int number; 
    char rate;
} Interval;


typedef struct{
    int i_last;
    Interval elements[MAX];
} List;

    
void input(Interval new_element, int i_input, List* plist);
void output(List* plist);
void check_numbers(List* plist, int low_limit, int up_limit);


int main() {
    
    int i,range_num, lower, upper;

    List list_interval;
    list_interval.i_last = -1;

    Interval input_num;

    do{
        printf("\n\thow many numbers will be in the list:");
        scanf("%d", &range_num);
            if(range_num>MAX || range_num<=0)
            printf("must be in the range 1 - 20");
    }while(range_num>MAX || range_num<=0);


    for (i = 0; i < range_num; i++) {

        printf("\n\t enter the %d. number: ",i+1);
        scanf("%d", &input_num.number);

        //scanf("%c", &enter, 1);
        input(input_num, i, &list_interval);
    }


    do{
        printf("\n\tenter the Interval limits - lower:");
        scanf("%d", &lower);
        printf("\n\tenter the Interval limits - upper:");
        scanf("%d", &upper);

            if(lower>=upper)
            printf("\nlower limit must be less than upper");
    }while(lower>=upper);


    check_numbers(&list_interval, lower, upper);


   // output(&list_interval);
    
    return 0;
}


void input(Interval new_element, int i_input, List* plist){
    int i;

    if (plist->i_last == MAX - 1)
    printf("\n List is full. ");

    else if (i_input > (plist->i_last + 1) || i_input < 0)
    printf("\n Index is wrong ");

    else{
        for (i = plist->i_last; i >= i_input; i--){
        plist->elements[i + 1] = plist->elements[i];
        }
    plist->i_last++;
    plist->elements[i_input] = new_element;
    }
}

/*
void output(List* plist){
    int i;
    int uk_P = 0, uk_V = 0, uk_S = 0;

    for (i = 0; i <= plista->iZadnji; i++){
        printf("\n\t Datum: %s ", plista->elementi[i].datum);
        printf("\n\t vrsta: %c ", plista->elementi[i].vrsta);
        printf("\n\t Sati: %d ", plista->elementi[i].broj_sati);

        if (plista->elementi[i].vrsta == 'P')
            uk_P += plista->elementi[i].broj_sati;
        if (plista->elementi[i].vrsta == 'V')
            uk_V += plista->elementi[i].broj_sati;
        if (plista->elementi[i].vrsta == 'S')
            uk_S += plista->elementi[i].broj_sati;
    }

    printf("\t\nUkupno - Predavanja: %d; Vjezbe: %d; Semninar: %d ", uk_P,uk_V,uk_S );


}
*/

void check_numbers(List* plist, int low_limit, int up_limit){
    int i;
    for(i=0;i<=plist->i_last;i++){
        if(plist->elements->number >= low_limit && plist->elements->number<=up_limit)
            plist->elements->rate= '=';
        else if(plist->elements->number>up_limit)
            plist->elements->rate= '>';
        else
            plist->elements->rate= '<';
    
    }

}





