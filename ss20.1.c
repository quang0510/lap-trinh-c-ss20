#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct Book
{
    char id[100];
    char name[100];
    char author[100];
    float price;
};

void createBook(struct Book book[],int *size);
void displayBook(struct Book book[],int *size);
void addBook(struct Book book[],int *size,struct Book newBook,int index);
void deleteBook(struct Book book[],int *size,char item[100]);
void updateBook(struct Book book[],int *size,struct Book newBook,char item[100]);
void sortPriceBook(struct Book book[],int *size,int choice);
void findBook(struct Book book[],int *size,struct Book newBook);

int main(){
    int choice,size = 0,index;
    char item[100];
    struct Book book[100];
    struct Book newBook;
    do
    {
        printf("______________________________________________\n");
        printf("        Menu\n");
        printf("1, Nhap so luong va thong tin sach\n");
        printf("2, Hien thi thong tin sach\n");
        printf("3, Them sach vao vi tri\n");
        printf("4, Xoa sach theo ma sach\n");
        printf("5, Cap nhap thong tin sach theo ma sach\n");
        printf("6, Sap xep sach theo gia(Tang/Giam)\n");
        printf("7, Tim kiem sach theo ten sach\n");
        printf("8, Thoat\n");
        printf("Nhap lua chon cua ban : ");
        scanf("%d",&choice);
        printf("______________________________________________\n");
        switch (choice)
        {
        case 1:
            printf("Nhap so luong sach : ");
            scanf("%d",&size);
            fflush(stdin);
            createBook(book,&size);
            displayBook(book,&size);
            break;
        case 2:
            if (size == 0)
            {
                printf("Chua co sach nao trong thu vien!");
            }
            else{
                displayBook(book,&size); 
            }
            break;
        case 3:
            if (size == 0)
            {
                printf("Chua co sach nao trong thu vien!");
            }
            else{
                printf("Nhap vi tri muon them : ");
                scanf("%d",&index);
                fflush(stdin);
                if (index <= 0 || index > size+1)
                {
                    printf("Vi tri khong hop le!!\n");
                }
                else
                {
                    addBook(book,&size,newBook,index);
                    displayBook(book,&size);
                } 
            }
            break;
        case 4:
            if (size == 0)
            {
                printf("Chua co sach nao trong thu vien!");
            }
            else{
                printf("Nhap ma sach : ");
                fflush(stdin);
                fgets(item,sizeof(item),stdin);
                item[strcspn(item, "\n")] = '\0';
                deleteBook(book,&size,item);
            }
            break;
        case 5:
            if (size == 0)
            {
                printf("Chua co sach nao trong thu vien!");
            }
            else{
                printf("Nhap ma sach : ");
                fflush(stdin);
                fgets(item,sizeof(item),stdin);
                item[strcspn(item, "\n")] = '\0';
                updateBook(book,&size,newBook,item);
                displayBook(book,&size); 
            }
            break;
        case 6:
            if (size == 0)
            {
                printf("Chua co sach nao trong thu vien!");
            }
            else{
                printf("1, Tang dan\n");
                printf("2, Giam dan\n");
                printf("Nhap lua chon cua ban : ");
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    sortPriceBook(book,&size,choice);
                    displayBook(book,&size);
                    break;
                case 2:
                    sortPriceBook(book,&size,choice);
                    displayBook(book,&size);
                    break;
                } 
            }
            
            break;
        case 7:
            if (size == 0)
            {
                printf("Chua co sach nao trong thu vien!");
            }
            else{
                printf("Nhap ten sach muon tim : ");
                fflush(stdin);
                fgets(newBook.name,sizeof(newBook.name),stdin);
                newBook.name[strcspn(newBook.name, "\n")] = '\0';
                findBook(book,&size,newBook);
            }
            break;
        case 8:
            printf("Tam biet!!\n");
            break;
        default:
            printf("Khong hop le, Nhap lai!!\n");
            break;
        }
    } while (choice != 8);    
}

void createBook(struct Book book[],int *size){
    for (int i = 0; i < *size; i++)
    {
        printf("_________________________________\n");
        printf("Nhap thong tin cua sach thu %d : \n",i+1);
        printf("Ma sach : ");
        fflush(stdin);
        fgets(book[i].id,sizeof(book[i].id),stdin);
        book[i].id[strcspn(book[i].id, "\n")] = '\0';
        printf("Ten sach : ");
        fgets(book[i].name,sizeof(book[i].name),stdin);
        book[i].name[strcspn(book[i].name, "\n")] = '\0';
        printf("Ten tac gia : ");
        fgets(book[i].author,sizeof(book[i].author),stdin);
        book[i].author[strcspn(book[i].author, "\n")] = '\0';
        printf("Gia tien : ");
        scanf("%f",&book[i].price);
        fflush(stdin);
    }
}

void displayBook(struct Book book[],int *size){
    for (int i = 0; i < *size; i++)
    {
        printf("_________________________________\n");
        printf("Thong tin sach thu %d : \n",i+1);
        printf("Ma sach : %s\n",book[i].id);
        printf("Ten sach : %s\n",book[i].name);
        printf("Ten tac gia : %s\n",book[i].author);
        printf("Gia tien : %.2f\n\n",book[i].price);
    }
    
}

void addBook(struct Book book[],int *size,struct Book newBook,int index){
    printf("Nhap thong tin cua sach : \n");
    printf("Ma sach : ");
    fflush(stdin);
    fgets(newBook.id,sizeof(newBook.id),stdin);
    newBook.id[strcspn(newBook.id, "\n")] = '\0';
    printf("Ten sach : ");
    fgets(newBook.name,sizeof(newBook.name),stdin);
    newBook.name[strcspn(newBook.name, "\n")] = '\0';
    printf("Ten tac gia : ");
    fgets(newBook.author,sizeof(newBook.author),stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';
    printf("Gia tien : ");
    scanf("%f",&newBook.price);
    fflush(stdin);
    for (int i = *size; i > index-1; i--)
    {
        book[i] = book[i-1];
    }
    book[index-1] = newBook;
    (*size)++;
}

void deleteBook(struct Book book[],int *size,char item[100]){
    char temp[100];
    int found = 0;
    int lenght = strlen(item);
    for (int i = 0; i < lenght; i++)
    {
        item[i] = toupper(item[i]);
    }
    for (int i = 0; i < *size; i++)
    {
        strcpy(temp,book[i].id);
        int lenghtTemp = strlen(temp);
        for (int j = 0; j < lenghtTemp; j++)
        {
            temp[j] = toupper(temp[j]);
        }
        if (strcmp(temp,item)==0)
        {
            found = 1;
            for (int k = i; k < *size; k++)
            {
                book[k] = book[k+1];
            }
            (*size)--;
            i--;
        }   
    }
    if (found == 0)
    {
        printf("Khong tim thay thong tin sach!\n");
    }
    else{
        printf("Da xoa!\n");
    }
}

void updateBook(struct Book book[],int *size,struct Book newBook,char item[100]){
    int found = 0;
    char temp[100];
    for (int i = 0; i < strlen(item); i++)
    {
        item[i] = toupper(item[i]);
    }
    for (int i = 0; i < *size; i++)
    {
        strcpy(temp,book[i].id);
        for (int i = 0; i < strlen(temp); i++)
        {
            temp[i] = toupper(temp[i]);
        }
        if (strcmp(item,temp)==0)
        {
            printf("Ma sach : ");
            fflush(stdin);
            fgets(book[i].id,sizeof(book[i].id),stdin);
            book[i].id[strcspn(book[i].id, "\n")] = '\0';
            printf("Ten sach : ");
            fgets(book[i].name,sizeof(book[i].name),stdin);
            book[i].name[strcspn(book[i].name, "\n")] = '\0';
            printf("Ten tac gia : ");
            fgets(book[i].author,sizeof(book[i].author),stdin);
            book[i].author[strcspn(book[i].author, "\n")] = '\0';
            printf("Gia tien : ");
            scanf("%f",&book[i].price);
            fflush(stdin);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Khong tim thay sach!\n");
    }
    
}

void sortPriceBook(struct Book book[],int *size,int choice){
    struct Book temp;
    switch (choice)
    {
    case 1:
        for (int i = 0; i < *size; i++)
            {
            for (int j = 0; j < *size-i-1; j++)
                {
                    if (book[j].price > book[j+1].price)
                        {
                            temp = book[j];
                            book[j] = book[j+1];
                            book[j+1] = temp;
                        }
                }
            }
        break;
    case 2:
        for (int i = 0; i < *size; i++)
            {
            for (int j = 0; j < *size-i-1; j++)
                {
                    if (book[j].price < book[j+1].price)
                        {
                            temp = book[j];
                            book[j] = book[j+1];
                            book[j+1] = temp;
                        }
                }
            }
        break;
    }   
}

void findBook(struct Book book[],int *size,struct Book newBook){
    char temp[100];
    for (int i = 0; i < strlen(newBook.name); i++)
    {
        newBook.name[i] = toupper(newBook.name[i]);
    }
    for (int i = 0; i < *size; i++)
    {
        strcpy(temp,book[i].name);
        for (int i = 0; i < strlen(temp); i++)
        {
            temp[i] = toupper(temp[i]);
        }
        if (strcmp(temp,newBook.name) == 0)
        {
            printf("Thong tin sach thu %d : \n",i+1);
            printf("Ma sach : %s\n",book[i].id);
            printf("Ten sach : %s\n",book[i].name);
            printf("Ten tac gia : %s\n",book[i].author);
            printf("Gia tien : %.2f\n\n",book[i].price);
        }
    }
}
