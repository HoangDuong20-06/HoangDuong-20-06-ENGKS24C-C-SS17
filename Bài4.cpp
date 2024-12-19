#include<stdio.h>
#include<stdlib.h>
void nhapPhanTu(int *arr, int size);
void soChan(int *arr, int size);
void soNguyenTo(int *arr, int size);
void daoNguoc(int *arr, int size);
void sapXepMangTang(int *arr, int size);
void sapXepMangGiam(int *arr, int size);
int timKiemPhanTu(int *arr, int value);
int main(){
	int choice, size,value,pos,a,b;
	int *arr;
	do{
		printf("MENU\n");
	    printf("1.Nhap vao so phan tu va tung phan tu\n");
	    printf("2.In ra cac phan tu la so chan\n");
	    printf("3.In ra cac phan tu la so nguyen to\n");
	    printf("4.Dao nguoc mang\n");
	    printf("5.Sap xep mang(khi chon thi menu con hien thi)\n");
	    printf(" a: Tang dan\n");
	    printf(" b: Giam dan\n");
	    printf("6.Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
	    printf("7.Thoat\n");
	    printf("Lua chon cua ban: ");
	    scanf("%d", &choice);
		switch (choice){
			case 1:
				printf("Nhap so phan tu cua mang: ");
				scanf("%d",&size);
				arr=(int *)malloc(size*sizeof(int));
				nhapPhanTu(arr,size);
				break;
			case 2:
				soChan(arr, size);
				break;
			case 3:
				soNguyenTo(arr, size);
				break;
			case 4:
				daoNguoc(arr, size);
				break;
			case 5:{
				char choose;
				printf("Chon kieu sap xep\n");
				printf("a. Tang dan\n");
				printf("b. Giam dan\n");
				printf("Lua chon cua ban: ");
				scanf("%c", &choose);
				if(choose== a){
					sapXepMangTang(arr,size);
					printf("Mang sau khi sap xep tang dan: ");
				}else if(choose== b){
					sapXepMangGiam(arr,size);
					printf("Mang sau khi sap xep giam dan: ");
			    }else {
			    	printf("Lua chon khong hop le\n");
				}
				for (int i=0; i<size; i++){
					printf("%d", arr[i]);
				}
				break;
			}
			case 6:
				printf("Nhap gia tri can tim: ");
				scanf("%d",&value);
				pos= timKiemPhanTu(arr,value);
				if(pos!=-1){
					printf("Phan tu %d nam o vi tri %d", value,pos);
				}else{
					printf("Khong co phan tu %d trong mang", value);
				}
				printf("\n");
				break;
			case 7:
				printf("Chuong trinh ket thuc");
				break;
				default:
				printf("Lua chon khong hop le\n");
		}
	}while(choice!=7);
	free(arr);
	return 0;
}
void nhapPhanTu(int *arr, int size){
	printf("Nhap cac phan tu cua mang\n");
	for (int i =0; i<size; i++){
		printf("arr[%d]=",i);
		scanf("%d",&arr[i]);
	}
}
void soChan(int *arr, int size){
	printf("Cac phan tu la so chan: ");
	for(int i =0; i<size;i++){
		if(arr[i]%2==0){
			printf("%d",arr[i]);
		}
	}
	printf("\n");
}
void soNguyenTo(int *arr, int size){
	printf("Cac phan tu la so nguyen to: ");
	for(int i =0; i<size;i++){
		if(arr[i]<10){
			switch(arr[i]){
				case 2:
			    case 3:
			    case 5:
			    case 7:
				printf("%d \n",arr[i]);
			}
		}else if(arr[i]%2!=0&&arr[i]%3!=0&&arr[i]%5!=0&&arr[i]%7!=0){
			printf("%d ", arr[i]);
		}
	}
}
void daoNguoc(int *arr, int size){
	for(int i = 0; i<size/2; i++){
		int temp= arr[i];
		arr[i]=arr[size-1-i];
		arr[size-1-i]=temp;
	}
}
void sapXepMangTang(int *arr, int size){
	for(int i =0; i<size-1; i++){
		for(int j=i +1; j<size; j++){
			if(arr[i]>arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void sapXepMangGiam(int *arr, int size){
	for(int i=0; i<size-1; i++){
		for(int j=i+1; j<size; j++){
			if(arr[i]<arr[j]){
				int temp=arr[i];
			    arr[i]=arr[j];
			    arr[j]=temp;
			}
		}
	}
}
int timKiemPhanTu(int *arr, int value){
	for(int i=0; arr[i]!= '0'; i++){
		if(arr[i]==value){
			return i;
		}
	}
	return -1;
}
