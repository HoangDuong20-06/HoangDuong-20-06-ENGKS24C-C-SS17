# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
void printstr(char *str);
int countalpha(char *str);
int countdigit(char *str);
int countspecial(char *str);
int main(){
	int choice;
	char *str;
	do{
		printf("MENU\n");
		printf("1. Nhap vao chuoi\n");
		printf("2. In ra chuoi\n");
		printf("3. Dem so luong chu cai trong chuoi in ra\n");
		printf("4. Dem so luong chu so trong chuoi in ra\n");
	    printf("5. Dem so luong ki tu dac biet trong chuoi in ra\n");
	    printf("6. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:	
				str=(char*)malloc(100*sizeof(char));
				printf("nhap chuoi: ");
            	fgets(str,100,stdin);
            	str[strcspn(str, "\n")] = '\0';
		        break;
		    case 2:
				printstr(str);
				break;
			case 3:
				printf("So luong chu cai trong chuoi la: %d\n",countalpha(str));
				break;
			case 4:
				printf("So luong chu so trong chuoi la : %d\n",countdigit(str));
				break;
			case 5:
				printf("So luong ky tu dac biet trong chuoi la: %d\n",countspecial(str));
				break;
			case 6:
				printf("Chuong trinh ket thuc");
				break;
			    default:
				printf("Lua chon khong hop le\n");
		}
	}while(choice!=6);
	free(str);
	return 0;
}
void printstr(char *str){
	printf("Chuoi vua nhap la: %s",str);
}
int countalpha(char *str){
    int count = 0;
    while (*str != '\0'){
        if (isalpha(*str)){
            count++;
		}
        str++;
    }
    return count;
}
int countdigit(char *str){
    int count = 0;
    while (*str != '\0'){
        if (isdigit(*str)){
            count++;
        }
        str++;
    }
    return count;
}
int countspecial(char *str){
int count = 0;
    while (*str != '\0'){
        if (!isalnum(*str)){
            count++;
        }
        str++;
    }
    return count;
}
