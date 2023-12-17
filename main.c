//
//  main.c
//  Grade_Calculator_Midterm
//
//  
//

#include <stdio.h>

float gradecheck();
FILE *fp;
int main(int argc, const char * argv[]) {
    char last [20];
    char * plast = last;
    char first [20];
    char * pfirst = first;
    char cont_progress;
    float test1 = 0, test2 = 0, test3 =0, sum = 0, average =0;
 
    fp = fopen("csis.txt", "w");
    
    do {
        printf("Enter the last name\n");
        fprintf(fp,"Enter the last name\n");
        scanf("%s", last);
        
        printf("Enter the first name\n");
        fprintf(fp,"Enter the first name\n");
        scanf("%s", first);
        
        printf("Enter Three scores\n");
        fprintf(fp,"Enter Three scores\n");
        
        test1 = gradecheck();
        test2 = gradecheck();
        test3 = gradecheck();
        sum = test1 + test2 + test3;
        average = sum / 3;
        
        printf("%s,%s \n", pfirst, plast);
        fprintf(fp,"%s,%s \n", pfirst, plast);
        
        printf("Average: %.2f\n", average);
        fprintf(fp,"Average: %.2f\n", average);
        
        if (average > 90) {
            printf("Letter Grade: A\n");
            fprintf(fp,"Letter Grade: A\n");
        }
        else if (average > 80 && average < 89.99){
            printf("Letter Grade: B\n");
            fprintf(fp,"Letter Grade: B\n");
        }
        else if (average > 70 && average < 79.99){
            printf("Letter Grade: C\n");
            fprintf(fp,"Letter Grade: C\n");
        }
        else if (average > 60 && average < 69.99){
            printf("Letter Grade: D\n");
            fprintf(fp,"Letter Grade: D\n");
        }
        else if (average < 60){
            printf("Letter Grade: F\n");
            fprintf(fp,"Letter Grade: F\n");
        }

        printf("\nCalculate another student grade:(press Y for yes, press N for no)\n");
        
        scanf(" %c", &cont_progress);
        
    } while (cont_progress == 'Y' || cont_progress == 'y');
    
    fclose(fp);
    
    return 0;
}


float gradecheck(){
    float grade = 0;
    
    printf("Enter a Test Score: \n");
    fprintf(fp,"Enter a Test Score: \n");
    scanf("%f", &grade);
    
    while (grade > 100 || grade < 0) {
    
            printf("Invalid Score, the valid range is 0-100\n");
            fprintf(fp,"Invalid Score, the valid range is 0-100\n");
        
            printf("Enter a new score: \n");
            fprintf(fp,"Enter a new score: \n");
        
            scanf("%f", &grade);
    }
    return grade;
}



