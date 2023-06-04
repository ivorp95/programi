
//funkcija za meni
#include <stdio.h>
char get_intials(void){
    char initails;
    printf("Please Enter Initials: ");
    scanf("\n%c",&initails) ;
    return initails;
}

int main (void)
{
    char menu_option,initials;
    int difficulty;

    printf("        EDUCATIONAL MATH PROGRAM!!!\n");
    printf("------------------------------------------\n\n");


    do{
    printf("Main Menu\n");
    printf("a. Learn about how to use program.\n");
    printf("b. Enter your initials (3 individual letters).\n");
    printf("c. Difficulty Selection.\n");
    printf("d. Start a new sequence of problems.\n");
    printf("e. Save and quit.\n");
    printf(" Please enter an option from the main menu: ");
    scanf("%c",&menu_option);

    switch(menu_option){

    case 'a':
        //Learn_to_use();

        break;
    case 'b':
        initials=get_intials();
        printf( "input initials:%c\n", initials) ;
        break;
    case'c':
        printf("case c");
        //difficulty = get_difficulty();
        break;
    case'd':
        break;
    case'e':
        break;
    default:
        printf("invalid input");
            break;
    }

    }while(menu_option !='e');
}


int main2 (){
    char menu_opcija;

    printf("\nProgram za unos filmova preko celija u strukturu reda, unose se podatci o:\nNazivu filma na engleskom, Prezimenu Redatelja, Imenu redatelja, Godini izdavanja filma, Trajanju filma u minutama.\n");

    do{
    printf("\nGLAVNI IZBORNIK:\n");
    printf("a. Unos podataka o novom filmu za unos u red.\n");
    printf("b. Enter your initials (3 individual letters).\n");
    printf("c. Difficulty Selection.\n");
    printf("d. Start a new sequence of problems.\n");
    printf("e. Save and quit.\n");
    printf(" Please enter an option from the main menu: ");
    scanf("%c",&menu_opcija);

        switch(menu_opcija){

        case 'a':
            break;
        case 'b':
            break;
        case'c':
            printf("case c");
            break;
        case'd':
            break;
        case'e':
            break;
        default:
            printf("invalid input");
            break;
    }

    }while(menu_opcija !='e');



    return 0;
}

