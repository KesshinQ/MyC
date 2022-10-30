#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char Name[32];
    char Surname[32];
    char PNumber[11];
    char EMail[24];
    struct node *adress;
};

typedef struct node plist;

plist *add_data(char Name[], char Surname[], char PNumber[],char EMail[]);
void printrecord();
void findrecord(char[]);
void deleterecord(char[]);
plist *record1 = NULL;

int main(){
    while(1) {
        printf("\t(===Telefon rehberi===)\n");
        printf("\tYapmak istediğiniz işlemi seçin: \n 1.Rehberi görüntüle.\t 2. Rehberde kişi ara. \n 3.Rehbere kişi ekle.\t 4. Rehberden kişi sil.\n \tÇıkmak için 5'e basın.\n\n(Türkçe karakter kullanmayın!)\nYapmak istediğiniz işlemin numarasını girin:  ");
        int islemsecim;
        scanf("%d", &islemsecim);


        switch (islemsecim) {

            case 1:
                printrecord();
                printf("\n\n");
                break;

            case 2:
                printf("Aramak istediginiz kişinin (ilk) ismini girin: \n");
                char searchname[16];
                scanf("%s", searchname);
                findrecord(searchname);
                break;


            case 3:
                puts("Rehbere eklemek istediğiniz kişinin (ilk) ismini girin: ");
                char Name[16];
                scanf("%s", Name);
                puts("Rehbere eklemek istediğiniz kişinin soyismini girin: ");
                char Surname[16];
                scanf("%s", Surname);
                puts("Rehbere eklemek istediğiniz kişinin telefon numarasını (başında 0 olmadan) girin: ");
                char PNumber[11];
                scanf("%s", PNumber);
                puts("Rehbere eklemek istediğiniz kişinin E-Posta adresini girin: ");
                char EMail[32];
                scanf("%s", EMail);
                add_data(Name, Surname, PNumber, EMail);
                break;


            case 4:
                printf("Silmek istediğiniz kişinin (ilk) adını girin: \n");
                char delname[16];
                scanf("%s", delname);
                deleterecord(delname);
                break;

            case 5:
                printf("Çıkış yapılıyor...");
                return 0;

            default:
                printf("Lütfen yapmak istediğiniz işlemin sayısını girin. Yoksa program çalışmayacak.\n\n");
                break;
        }

    }
}


plist *add_data(char Name[], char Surname[], char PNumber[], char EMail[]){
    plist *newnode = (plist*)malloc(sizeof(plist));
    strcpy(newnode -> Name, Name);
    strcpy(newnode -> Surname, Surname);
    strcpy(newnode -> PNumber, PNumber);
    strcpy(newnode -> EMail, EMail);

    newnode -> adress = NULL;

    if(record1 == NULL){
        record1 = newnode;
        return newnode;
    }

    plist *iter = record1;

    while(iter -> adress != NULL)
        iter = iter -> adress;

    iter -> adress = newnode;
    return newnode;
}

void printrecord(){
    plist *iter = record1;
    int sayac = 1;

    if(record1 == NULL){
        printf("---Telefon rehberi boş.---\n");
    }

    while(iter != NULL){
        printf("%d)\n" ,sayac);
        printf("İsim: %s\n" , iter -> Name);
        printf("Soyisim: %s\n" , iter ->Surname);
        printf("Telefon Numarası: %s\n" , iter -> PNumber);
        printf("E-Posta adresi: %s\n" , iter ->EMail);

        sayac += 1;
        iter = iter -> adress;
    }
}

void findrecord(char findname[]){
    plist *iter = record1;

    if(record1 == NULL){
        printf("---Bulunamadı. Çünkü telefon rehberi boş.---\n\n");
    }

    while(iter != NULL){
        if (strcmp(iter -> Name, findname) == 0){
            printf("--- Aranan kişi listede bulundu. ---\n");
            printf("==> %s \n==> %s \n==> %s \n==> %s \n" , iter ->Name , iter -> Surname , iter -> PNumber , iter -> EMail);
            return;
        }
        else{
            printf("---Aranan kişi listede bulunamadı.---\n\n\n");
        }
        iter = iter -> adress;
    }
}

void deleterecord(char Nametodel[]){
    plist *iter = record1;
    plist *iterprev;

    if(record1 == NULL){
        printf("---Telefon rehberi boş.---\n\n");
    }
    else{
        if(strcmp(iter -> Name , Nametodel) == 0){
            record1 = iter -> adress;
        }
        else{
            while(iter != NULL){
                if(strcmp(iter -> Name , Nametodel) == 0) {
                    iterprev -> adress = iter -> adress;
                    break;
                }
                else{
                    iterprev = iter;
                    iter = iter -> adress;
                }
            }
            printf("---Kayıt silindi.---\n");
        }
    }


}