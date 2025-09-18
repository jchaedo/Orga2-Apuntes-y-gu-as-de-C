#include <stdio.h>
#include <stdlib.h>
#include "type.h"

fat32_t* new_fat32(){
    return malloc(sizeof(fat32_t));
}

ext4_t* new_ext4(){
    return malloc(sizeof(ext4_t));
}

ntfs_t* new_ntfs(){
    return malloc(sizeof(ntfs_t));
}

fat32_t* copy_fat32(fat32_t* file){
    fat32_t *res = malloc(sizeof(fat32_t));
    *res = *file;
    return res;
}

ext4_t* copy_ext4(ext4_t* file){
    ext4_t *res = malloc(sizeof(ext4_t));
    *res = *file;
    return res;
}

ntfs_t* copy_ntfs(ntfs_t* file){
    ntfs_t *res = malloc(sizeof(ntfs_t));
    *res = *file;
    return res;
}

void rm_fat32(fat32_t* file){
    free(file);
}

void rm_ext4(ext4_t* file){
    free(file);
}

void rm_ntfs(ntfs_t* file){
    free(file);
}
