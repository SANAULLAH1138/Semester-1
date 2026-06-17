
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int noStudents;
	printf("Enter the Number of Students : ");
	scanf("%d",&noStudents);
	int** students=(int**)malloc(noStudents*sizeof(int*));
	int* noGradesArray=(int*)malloc(noStudents*sizeof(int));
	if(students==NULL || noGradesArray==NULL){
		printf("Memory Allocation Failed.\n");
		return 1;
	}
	for(int i=0;i<noStudents;i++){
		printf("Enter the Number of Grades for Student %d : ",i+1);
	    scanf("%d",&noGradesArray[i]);
	    students[i]=(int*)malloc(noGradesArray[i]*sizeof(int));
	    if(students[i]==NULL){
	    	printf("Memory Allocation for Student %d Failed. \n",i+1);
	    	return 1;
		}
		printf("Enter Grades for Student %d : \n",i+1);
		for(int j=0;j<noGradesArray[i];j++){
			printf("Grade %d : ",j+1);
			scanf("%d",&students[i][j]);
			}
	}
	printf("Entered Grades : \n");
	for(int i=0;i<noStudents;i++){
		printf("Student %d Grades : ",i+1);
		for(int j=0;j < noGradesArray[i];j++){
			printf("%d ",students[i][j]);
		}
		printf("\n");
	}
	for(int i=0; i<noStudents; i++){
        free(students[i]);
    }
    free(students);
    free(noGradesArray);
		return 0;
	}	

