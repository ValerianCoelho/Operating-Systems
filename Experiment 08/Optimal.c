#include <stdio.h>

#define MAX 100

int main() {
    int page_found;
    int page_faults = 0;
    int ram_size;
    int no_of_pages;
    int replacement_index = 0;
    int max;
    int index;

    int ram[MAX];
    int page_reference[MAX];

    printf("Enter the no of frames allocated to the process : ");
    scanf("%d", &ram_size);

    printf("Enter the no of pages in the page reference string : ");
    scanf("%d", &no_of_pages);

    printf("Enter the page reference string : ");
    for(int i=0; i<no_of_pages; i++) {
        scanf("%d", &page_reference[i]);
    }

    for(int j=0; j<ram_size; j++) {
        ram[j] = -1;
    }

    for(int i=0; i<no_of_pages; i++) {
        page_found = 0;
        for(int j=0; j<ram_size; j++) {
            if(page_reference[i] == ram[j]) {
                page_found = 1;
            }
        }
        if(!page_found) {
            page_faults++;
            replacement_index = 0;
            max = -1;
            for(int j=0; j<ram_size; j++) {
                index = -1;
                if(ram[j] == -1) {
                    replacement_index = j;
                    break;
                    }
                for(int k=i; k<no_of_pages; k++) {
                    if(ram[j] == page_reference[k]) {
                        index = k;
                        break;
                    }
                }
                if(index == -1) {
                    replacement_index = j;
                    break;
                }
                if(max < index) {
                    max = index;
                    replacement_index = j;
                }
            }
            ram[replacement_index] = page_reference[i];
        }
    }
    printf("Page Faults : %d", page_faults);
    return 0;
}

// 21
// 3 4 3 2 1 2 6 4 5 7 4 1 3 7 7 5 4 1 3 8 5