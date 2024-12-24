#include <stdio.h>
#include <string.h>
#include <math.h>

void displayMenu();
struct Dish {
	int id;
	char name[50];
	int price;
};
struct Dish menu[100] ={
		{1,"Ramen",5000},
		{2,"Gyudon",7000},
		{3,"Tempura",1000 },
		{4,"Sup Miso",6000 }	
};
void choice1();
void choice2();
void choice3();
void choice4();
void choice5();
void choice6();
void choice7();
char *arr = NULL;
int choice, n;
int main() {
    do {
        displayMenu();
        switch(choice) {
            case 1 :
                choice1();
                break;
            case 2 :
                choice2();
                break;
            case 3 :
                choice3();
                break;
            case 4 :
                choice4();
                break;
            case 5 :
                choice5();                
                break;
            case 6 :
                choice6();
                break;
            case 7 :
                choice7();
                break;        
        }
    } while(choice != 7);
    return 0;
}
void displayMenu() {
    printf("\n---MENU--\n");
    printf("1. In ra gia tri cac phan tu co trong menu mon an theo dang 1. member: value.\n");
    printf("2. Them mot phan tu vao vi tri chi dinh.\n");
    printf("3. Sua mot phan tu o vi tri chi dinh.\n");
    printf("4. Xoa mot phan tu o vi tri chi dinh.\n");
    printf("5. Sap xep cac phan tu.\n");
    printf("6. Tim kiem phan tu theo name duoc nhap vao.\n");
    printf("7. Thoat.\n");
    printf("Hay nhap lua chon cua ban: ");
    scanf("%d", &choice);
    getchar();
}
void choice1(){
	printf("Sau day la cac mon an trong Menu: \n");
	printf("\n---MENU--\n");
	for( int i=0; i<4; i++){
		printf("Mon an %d:%d\n",i+1,menu[i].id);
		printf("Ten mon an:%s\n",menu[i].name);
		printf("Gia tien:%dYEN\n",menu[i].price);
	}
}
void choice2(){
	menu[4].id = 6;
	printf("Hay them mon an moi vao menu: \n");
	fflush(stdin);
	printf("Nhap ten mon an moi: \n");
	fgets(menu[4].name, sizeof(menu[4].name), stdin);
	printf("Gia tien mon an moi:\n");
	scanf("%s", &menu[4].price);
}
void choice3(){
	int count;
	if (count > 0) {
		printf("Sua ten mon an: ");
		fflush(stdin);
		fgets(menu[count - 1].name, sizeof(menu[count - 1].name), stdin);
		menu[count - 1].name[strcspn(menu[count - 1].name, "\n")] = 0;
		printf("Sua gia tien mon an: ");
		scanf("%d", &menu[count - 1].price);
		printf("Mon an da duoc sua thanh cong.\n");
	} else {
		printf("Khong co mon an nao de sua.\n");
	}
	for(int i=0; i<count; i++){
		printf("Mon an %d:%d\n",i+1,menu[i].id);
		printf("Ten mon an:%s\n",menu[i].name);
		printf("Gia tien:%dYEN\n",menu[i].price); 
				}
}	
void choice4(){
	int xoa, pos;
	printf("Nhap vi tri mon an muon xoa: \n");
	scanf("%d", &xoa);
	pos--;
	for (int i = pos; i < n - 1; i++) {
    	menu[i] = menu[i + 1];
	}
	n--;
	printf("Da xoa mon an!");
	
	printf("Sau khi xoa, phan tu moi duoc them vao: \n");
	for(int i=0;i<4;i++){
		printf("%d, %s: %s\n", menu[i].id, menu[i].name, menu[i].price);
	}
}
void choice5(){
	printf("Sau day la menu da duoc sap xep theo thu tu giam dan gia mon an: \n");
	for(int i=0;i<5;i++){
		for(int j=0; j<n-i-1;j++){
            if (menu[j].price > menu[j + 1].price) {
                struct Dish temp = menu[j];
                menu[j] = menu[j + 1];
                menu[j + 1] = temp;
		}
}
	printf("Menu sau khi duoc sap xep: \n");
	for(i=0;i<5; i++){
		printf("%d, %s, %d\n",menu[i].id, menu[i].name, menu[i].price);
	}
}
}
void choice6(){
	int food, found;
	printf("Nhap id mon an can tim: ");
		getchar();
		scanf("%d",&food);	
		    for(int i = 0; i < n; i++){
			    if(menu[i].id == food){
			        printf("Ten mon an:%s\n",menu[i].name);
					printf("Gia tien:%dYEN\n",menu[i].price); 
			        found = 1; 
			        break;
			    }
		    }
			if(found == 0){
			    printf("Khong co mon an ma ban nhap!!\n", food);
			}
}
void choice7(){
	printf("Thoat chuong trinh!\n");
}
