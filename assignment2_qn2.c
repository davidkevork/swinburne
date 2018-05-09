#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
typedef enum genre { Pop, Jazz, Classic, Rock, Metal } genre;
const char* genre_s[] = { "Pop", "Jazz", "Classic", "Rock", "Metal" };

typedef struct album {
    char album_name[20];
    genre kind;
    int number_of_tracks;
    char tracks[10][256];
    char track_location[256];
} album;

typedef struct album_array {
    int size;
    album *ptr;
} album_array;

void add_album(album* alb);
void select_track_to_play(album albums[], int size);
void print_all_albums(album albums[], int size);
void print_album(album* albums);
void show_options();

int main(int argc, char const *argv[]) {
    album_array album_new_array;
    int options = 0;
    album_new_array.size = 0;
    album_new_array.ptr = (album *) malloc( sizeof(album[0]) );
    do {
        show_options();
        scanf("%d", &options);

        switch (options) {
            case 1:
                // add an album
                album_new_array.size += 1;
                album_new_array.ptr = (album *) realloc(album_new_array.ptr,  sizeof(album[1]) * album_new_array.size);
                add_album(&album_new_array.ptr[album_new_array.size-1]);
                break;
            case 2:
                print_all_albums(album_new_array.ptr, album_new_array.size);
                break;
            case 3:
                select_track_to_play(album_new_array.ptr, album_new_array.size);
                break;
            case 4:
                // exit the app
                free(album_new_array.ptr);
                return 0;
            default:
                options = 0;
        }
    } while (options != 4);

    return 0;
}
#pragma clang diagnostic pop

void show_options() {
    printf("Enter the options:\n");
    printf("1: Add an album\n");
    printf("2: Print the album details\n");
    printf("3: Play a track from an album\n");
    printf("4: Exit\n");
}

/**
 * option 1
 * add an album
 * @param alb
 */
void add_album(album* alb) {
    printf("Enter album name: ");
    scanf("%s", alb->album_name);
    printf("Enter album genre: 0 -> Pop, 1 -> Jazz, 2 -> Classic, 3 -> Rock, 4 -> Metal: ");
    scanf("%u", &alb->kind);
    do {
        printf("Enter album number of tracks [0-10]: ");
        scanf("%i", &alb->number_of_tracks);
    } while (alb->number_of_tracks < 0 && alb->number_of_tracks > 10);

    for (int i = 0; i < alb->number_of_tracks; ++i) {
        printf("Enter album track name: ");
        scanf("%s", alb->tracks[i]);
    }

    printf("Enter album track location: ");
    scanf("%s", alb->track_location);
}

/**
 * option 2
 * print the album details
 * @param alb
 */
void print_album(album* alb) {
    printf("Album Name: %s\n", alb->album_name);
    printf("Album genre: %s\n", genre_s[alb->kind]);
    printf("Album number of tracks: %d\n", alb->number_of_tracks);
    for (int i = 0; i < alb->number_of_tracks; ++i) {
        printf("Album track name: %s\n", alb->tracks[i]);
    }
    printf("Album track location: %s\n\n", alb->track_location);
}

/**
 * option 2
 * displays all the albums
 * @param albums
 * @param size
 */
void print_all_albums(album albums[], int size) {
    for (int i = 0; i < size; ++i) {
        print_album(&albums[i]);
    }
}

/**
 * option 3
 * play a track from an album
 * @param albums
 * @param size
 */
void select_track_to_play(album albums[], int size) {
    char album_name[256];
    int index = -1;
    printf("Enter album name you want to play: ");
    scanf("%s", album_name);
    for (int i = 0; i < size; ++i) {
        if (strcmp(albums[i].album_name, album_name) == 0) {
            index = i;
        }
    }
    if (index == -1) {
        printf("Could not find album with name: %s", album_name);
    } else {
        int track_number = -1, number_of_tracks = albums[index].number_of_tracks;
        printf("The album contains %i tracks. Choose one of them:\n", number_of_tracks);
        for (int i = 0; i < number_of_tracks; ++i) {
            printf("%i. %s\n", i, albums[index].tracks[i]);
        }
        do {
            scanf("%i", &track_number);
        } while (track_number < 0 || track_number > number_of_tracks);
        printf("The track you selected %s, from Album: %s is now playing ... from file location: %s\n",
               albums[index].tracks[track_number], albums[index].album_name, albums[index].track_location);
        char cmd[256] = "start ./";
        strcat(cmd, albums[index].track_location);
        strcat(cmd, "/");
        strcat(cmd, albums[index].tracks[track_number]);
        strcat(cmd, ".mp3");
        system(cmd);
    }
}
#pragma clang diagnostic pop
