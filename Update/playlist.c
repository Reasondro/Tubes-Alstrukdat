// playlist.c

typedef struct tNode *address;

typedef struct tNode {
    char nama[100];
    address Next;
} Node;

typedef struct {
    Node *First;
} Playlist;

typedef struct {
    int Capacity;
    Playlist *pl;
} DaftarPlaylist;

// Inisialisasi DaftarPlaylist
int InitialSize = 10;
DaftarPlaylist DP;

void InitializeDaftarPlaylist() {
    DP.pl = (Playlist *)malloc(InitialSize * sizeof(Playlist));
    DP.Capacity = InitialSize;

    // Inisialisasi setiap Playlist
    for (int i = 0; i < InitialSize; i++) {
        DP.pl[i].First = NULL; // Playlist kosong saat inisialisasi
    }
}
