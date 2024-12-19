#include<stdio.h>
#include<stdlib.h>
void nhapPhanTu(int *arr, int size);
void hienThi(int *arr, int size);
int tong(int *arr, int size);
int timMax(int *arr, int size);
int main(){
	int choice,size,sum,max;
	int *arr;
	do{
		printf("MENU\n");
		printf("1. Nhap vao so phan tu va tung phan tu\n");
		printf("2. Hien thi cac phan tu trong mang\n");
		printf("3. Tinh do dai mang\n");
		printf("4. Tinh tong cac phan tu trong mang\n");
	    printf("5. Hien thi phan tu lon nhat\n");
	    printf("6. Thoat\n");
	    printf("Lua chon cua ban: ");
	    scanf("%d", &choice);
	    switch(choice){
	    	case 1:
	    		printf("Nhap so phan tu: ");
	    		scanf("%d",&size);
	    		arr = (int *)malloc(size*sizeof(int));
	    		nhapPhanTu(arr,size);
	    		break;
	    	case 2:
	    		hienThi(arr,size);
	    		break;
	    	case 3:
	    		printf("Do dai mang la: %d\n",size);
	    		break;
	    	case 4:
	    		sum=tong(arr,size);
	    		printf("Tong  cac phan tu trong mang: %d\n",sum);
				break;
			case 5:
				max=timMax(arr,size);
				printf("Phan tu lon nhat trong mang: %d\n",max);
				break;
			case 6:
				printf("Chuong trinh ket thuc");
				break;
				default:
				printf("Lua chon khong hop le\n");
	    }
    }while (choice!=6);
    free(arr);
    return 0;
}
void nhapPhanTu(int *arr, int size){
	printf("Nhap phan tu\n");
	for(int i =0; i<size; i++){
		printf("arr[%d]=",i);
		scanf("%d",&arr[i]);
	}
}
void hienThi(int *arr, int size){
	printf("Cac phan tu trong mang\n");
	for(int i =0; i<size; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int tong(int *arr, int size){
	int sum =0;
	for(int i=0;i<size; i++){
		sum +=arr[i];
	}
	return sum;
}
int timMax(int *arr, int size){
	int max = arr[0];
	for(int i =1; i<size; i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
