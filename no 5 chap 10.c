
#include <stdio.h>
#include <string.h>
#define MAX_ADDRESSES 100
#define NICKNAME_LENGTH 11

struct address_t{
    int part1, part2, part3, part4;
    char nickname[NICKNAME_LENGTH];
};

int main(){
    struct address_t addresses[MAX_ADDRESSES];
    int address_count = 0;

    while (1){
        scanf("%d.%d.%d.%d", &addresses[address_count].part1, &addresses[address_count].part2, 
              &addresses[address_count].part3, &addresses[address_count].part4);
        scanf("%s", addresses[address_count].nickname);

        if (addresses[address_count].part1 == 0 && addresses[address_count].part2 == 0 && 
            addresses[address_count].part3 == 0 && addresses[address_count].part4 == 0 && 
            strcmp(addresses[address_count].nickname, "none") == 0){
            break;
        }

        address_count++;

        if (address_count >= MAX_ADDRESSES){
            break;
        }
    }

    for (int i = 0; i < address_count; i++){
        for (int j = i + 1; j < address_count; j++){
            if (addresses[i].part1 == addresses[j].part1 && addresses[i].part2 == addresses[j].part2) {
                printf("Machines %s and %s are on the same local network.\n", 
                       addresses[i].nickname, addresses[j].nickname);
            }
        }
    }

    printf("\nList of addresses and nicknames:\n");
    for (int i = 0; i < address_count; i++){
        printf("%d.%d.%d.%d  %s\n", addresses[i].part1, addresses[i].part2, addresses[i].part3, addresses[i].part4,
               addresses[i].nickname);
    }
    return 0;
}