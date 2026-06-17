
#include <stdio.h>
#include <stdlib.h>
int main(){
	int a;
	scanf("%d ",&a);
	for(int i=0;i<a;i++){
	int no;
	scanf("%d",&no);
	int* list=(int*)malloc(no*sizeof(int));
	for(int i=0;i<no;i++){
		scanf("%d ",&list[i]);
	}
	int* countFreq=(int*)malloc(no*sizeof(int));
	for(int i=0;i<no;i++){
		int count=0;
		for(int j=0;j<no;j++){
			if(list[i]==list[j]){
				count++;
			}
		}
		countFreq[i]=count;
	}
	int maxCount=0;
	int result=list[0];
	for(int i=0;i<no;i++){
		if(countFreq[i]>maxCount){
			maxCount=countFreq[i];
			result=list[i];
		}else if(countFreq[i]==maxCount && list[i]<result){
			result=list[i];
		}
	}
	printf("%d\n", result);
	free(list);
    free(countFreq);
    }
	return 0;
}

