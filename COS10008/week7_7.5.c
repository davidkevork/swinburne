#include <stdio.h>

enum genreList {Pop, Jazz, Classic, Rock};
struct album {
  char name[20];
  enum genreList genre;
  int tracks;
  int year;  
};

void readAlbum(struct album* OldAlbum) {
  enum genreList selection;
  printf("\n\nOld Album name: %s\nGenre:\n0 -> Pop\n1 -> Jazz\n2 -> Classic\n3 -> Rock\n %i\ntracks: %i\nyear released: %i", (*OldAlbum).name, (*OldAlbum).genre, (*OldAlbum).tracks, (*OldAlbum).year);
}

void inputAlbum(struct album* NewAlbum) {
  printf("Enter album name: ");
  scanf("%s", (*NewAlbum).name);
  printf("Enter genre:\n0 -> Pop\n1 -> Jazz\n2 -> Classic\n3 -> Rock\n");
  scanf("%i", &(*NewAlbum).genre);
  printf("Enter number of tracks: ");
  scanf("%i", &(*NewAlbum).tracks);
  printf("Enter year released: ");
  scanf("%i", &(*NewAlbum).year);
}
 
int main(int argc, char const *argv[]) {
  struct album *NewAlbumPtr, NewAlbum;
  NewAlbumPtr = &NewAlbum;
  inputAlbum(NewAlbumPtr);
  readAlbum(NewAlbumPtr);
  return 0;
}
