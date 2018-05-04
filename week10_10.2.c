#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* genre[] = {"Pop", "Jazz", "Classic", "Rock"};

struct album  {
    char album_name[50];
    int kind;
    int number_of_tracks;
    int year_released;
    char track_name[50];
    char track_location[50];
};

void read_all_albums(struct album albums[], int size);
void print_all_albums(struct album albums[], int size);
void read_album(struct album* albums);
void print_album(struct album* albums);

int main(int argc, char const *argv[]) {
    struct album *albumsPtr, albums[1];
    int size = 0;
    printf("How many album data you want to enter: ");
    do {
        scanf("%d", &size);
    } while(size <= 0);
    albumsPtr = (struct album *) malloc( sizeof(albums[1]) * size);

    read_all_albums(albumsPtr, size);
    printf("\nAlbum details:\n");
    print_all_albums(albumsPtr, size);

    return 0;
}

void read_all_albums(struct album albums[], int size) {
    for (int i = 0; i < size; ++i) {
        read_album(&albums[i]);
    }
}

void print_all_albums(struct album albums[], int size) {
    for (int i = 0; i < size; ++i) {
        print_album(&albums[i]);
    }
}

void read_album(struct album* albums) {
    printf("Enter album name: ");
    scanf("%s", albums->album_name);
    printf("Enter lbum genre: 0 -> Pop, 1 -> Jazz, 2 -> Classic, 3 -> Rock: ");
    scanf("%i", &albums->kind);
    printf("Enter album number of tracks: ");
    scanf("%i", &albums->number_of_tracks);
    printf("Enter album release year: ");
    scanf("%i", &albums->year_released);
    printf("Enter album track name: ");
    scanf("%i", albums->track_name);
    printf("Enter album track location: ");
    scanf("%i", albums->track_location);
}

void print_album(struct album* albums) {

    printf("Album Name: %s\n", albums->album_name);
    printf("Album kind: %s\n", genre[albums->kind]);
    printf("Album number of tracks: %d\n", albums->number_of_tracks);
    printf("Album release year: %d\n", albums->year_released);
    printf("Album track name: %d\n", albums->track_name);
    printf("Album track location: %d\n", albums->track_location);
}
