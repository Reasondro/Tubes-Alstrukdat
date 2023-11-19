typedef struct tPlaylist *address;
typedef struct {
    char nama[100];
    address First;
} Playlist; //ini playlist

typedef struct {
    int Capacity;
    Playlist *pl;
} DaftarPlaylist;

int InitialSize=10;
DaftarPlaylist DP;
DP.pl = (Playlist*) malloc (InitialSize*sizeof(Playlist));
DP.Capacity = InitialSize;
