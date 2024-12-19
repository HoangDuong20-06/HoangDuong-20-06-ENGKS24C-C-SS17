#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void reverse(char *str);
void countAlpha(char *str);
void compare(char *str, char *str2);
void floralPrintCase(char *str);
void concatStr(char *str, char *str2);
int main(){
	char *str;
	char *str2;
	int choice,total;
	do{
		printf("MENU\n");
		printf("1. Nhap vao chuoi\n");
		printf("2. In ra chuoi dao nguoc\n");
		printf("3. Dem so luong tu trong chuoi\n");
		printf("4. Nhap vao chuoi khac. So sanh chuoi do voi chuoi ban dau(Ket qua in ra ngan hon hoac dai hon chuoi ban ban dau)\n");
	    printf("5. In hoa tat ca chu cai trong chuoi\n");
	    printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
	    printf("7. Thoat\n");
	    printf("Lua chon cua ban: ");
	    scanf("%d", &choice);
	    getchar();
	    switch(choice){
	    	case 1:
	    		str=(char*)malloc(100*sizeof(char));
				printf("nhap chuoi: ");
            	fgets(str,100,stdin);
            	str[strcspn(str, "\n")] = '\0';
	    		break;
	    	case 2:
	    		reverse(str);
	    		break;
	    	case 3:
	    		countAlpha(str);
	    		break;
	    	case 4:
	    		str2=(char*)malloc(100*sizeof(char));
				printf("nhap chuoi moi: ");
            	fgets(str2,100,stdin);
            	str[strcspn(str, "\n")] = '\0';
	    		compare(str,str2);
	    		break;
	    	case 5:
	    		floralPrintCase(str);
	    		break;
	    	case 6:
	    		str2=(char*)malloc(100*sizeof(char));
				printf("nhap chuoi moi: ");
            	fgets(str2,100,stdin);
            	str[strcspn(str, "\n")] = '\0';
            	concatStr(str,str2);
            	break;
	    	case 7:
	    		printf("Chuong trinh ket thuc");
	    		break;
	    		default:
	    		printf("Lua chon khong hop le\n");
		}
	}while(choice!=7);
	free(str);
	return 0;
}
void reverse(char *str){
	int length=strlen(str);
	printf("Chuoi dao nguoc: ");
	for(int i=length-1; i>=0; i--){
		printf("%c",str[i]);
	}
	printf("\n");
}
void countAlpha(char *str){
	int count =0;
    for (int i=0; i<strlen(str);i++){
    	if(*(str+i)==' '){
    		count ++;
	    }
	count +=1;
	printf("So luong tu trong chuoi: %d\n", count);
    }
}
void compare(char *str, char *str2){
	if(strlen(str) > strlen(str2)){
		printf("Chuoi moi ngan hon chuoi ban dau\n");
	}else if(strlen(str2) > strlen(str)){
		printf("Chuoi moi dai hon chuoi ban dau\n");
	}else {
		printf("hai chuoi bang nhau\n");
	}
}
void floralPrintCase(char *str){
	for (int i = 0; str[i] != '\0'; i++) {
	    str[i] = toupper(str[i]);
	}
	printf("Chuoi sau khi in hoa: %s\n", str);
}
void concatStr(char *str, char *str2){
	strcat(str,str2);
	printf("Chuoi sau khi noi: %s\n",str);
}
