#include <stdio.h>
#include "nbtrees.h"
#include <ctype.h>

void showMenu() {
    printf("Menu:\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search Node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level Node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membedakan 2 Node Tree\n");
    printf("11. Exit\n");
}

void PrintNodeInfo(Isi_Tree tree) {
    printf("\n\nSeluruh Node pada Non Binary Tree:\n");
    printf("------------------------------------------------\n");
	
	int i;
    for (i = 1; i <= jml_maks; i++) {  // Batasi hingga jml_maks (10 node)
        if (tree[i].info != ' ') {  // Pastikan node tidak kosong
            printf("--> Index ke-%d\n", i);
            printf("------------------------------------------------\n");
            printf("info array ke %d \t: %d\n", i, tree[i].info - 'A' + 1);  // Menampilkan info node, dikurangi untuk mendapatkan nomor urut
            printf("first son array ke %d : %d\n", i, tree[i].ps_fs);
            printf("next brother array ke %d : %d\n", i, tree[i].ps_nb);
            printf("parent array ke %d : %d\n", i, tree[i].ps_pr);
            printf("------------------------------------------------\n");
        }
    }
}




int main() {
    Isi_Tree tree;   
    int jml_node = 10; // Jumlah node untuk pohon ini adalah 10

    // Membuat pohon dengan jumlah node yang dimasukkan
    Create_tree(tree, jml_node);

    // Input data untuk setiap node (Seperti yang sudah ada di kode sebelumnya)
    tree[1].info = 'A';
    tree[1].ps_fs = 2;  
    tree[1].ps_nb = 0;  
    tree[1].ps_pr = 0;  

    
    // Node B - Level 1 (Anak dari A)
    tree[2].info = 'B';
    tree[2].ps_fs = 4;  // Anak pertama dari B adalah D
    tree[2].ps_nb = 3;  // Saudara berikutnya dari B adalah C
    tree[2].ps_pr = 1;  // Parent dari B adalah A

    // Node C - Level 1 (Anak dari A)
    tree[3].info = 'C';
    tree[3].ps_fs = 6;  // Anak pertama dari C adalah F
    tree[3].ps_nb = 0;  // Tidak ada saudara berikutnya dari C
    tree[3].ps_pr = 1;  // Parent dari C adalah A

    // Node D - Level 2 (Anak dari B)
    tree[4].info = 'D';
    tree[4].ps_fs = 0;  // Tidak ada anak
    tree[4].ps_nb = 5;  // Saudara berikutnya dari D adalah E
    tree[4].ps_pr = 2;  // Parent dari D adalah B

    // Node E - Level 2 (Anak dari B)
    tree[5].info = 'E';
    tree[5].ps_fs = 9;  // Anak pertama dari E adalah I
    tree[5].ps_nb = 0;  // Tidak ada saudara berikutnya
    tree[5].ps_pr = 2;  // Parent dari E adalah B

    // Node F - Level 2 (Anak dari C)
    tree[6].info = 'F';
    tree[6].ps_fs = 0;  // Tidak ada anak
    tree[6].ps_nb = 7;  // Saudara berikutnya dari F adalah G
    tree[6].ps_pr = 3;  // Parent dari F adalah C

    // Node G - Level 2 (Anak dari C)
    tree[7].info = 'G';
    tree[7].ps_fs = 0;  // Tidak ada anak
    tree[7].ps_nb = 8;  // Saudara berikutnya dari G adalah H
    tree[7].ps_pr = 3;  // Parent dari G adalah C

    // Node H - Level 2 (Anak dari C)
    tree[8].info = 'H';
    tree[8].ps_fs = 0;  // Tidak ada anak
    tree[8].ps_nb = 0;  // Tidak ada saudara berikutnya
    tree[8].ps_pr = 3;  // Parent dari H adalah C

    // Node I - Level 3 (Anak dari E)
    tree[9].info = 'I';
    tree[9].ps_fs = 0;  // Tidak ada anak
    tree[9].ps_nb = 10; // Saudara berikutnya dari I adalah J
    tree[9].ps_pr = 5;  // Parent dari I adalah E

    // Node J - Level 3 (Anak dari E)
    tree[10].info = 'J';
    tree[10].ps_fs = 0; // Tidak ada anak
    tree[10].ps_nb = 0; // Tidak ada saudara berikutnya
    tree[10].ps_pr = 5; // Parent dari J adalah E


    int pilihan;
    while (1) {
        showMenu();
        printf("\nPilih menu (1-11): ");
        scanf("%d", &pilihan);
        system("cls");
        
        switch(pilihan) {
            case 1:
                printf("\nTraversal PreOrder: ");
                PreOrder(tree);
                break;
            case 2:
                printf("\nTraversal InOrder: ");
                InOrder(tree);
                break;
            case 3:
                printf("\nTraversal PostOrder: ");
                PostOrder(tree);
                break;
            case 4:
                printf("\nTraversal Level Order: ");
                Level_order(tree, jml_node);
                break;
            case 5:
                printf("\nPohon yang ditampilkan:\n");
                PrintTree(tree);  // Output sesuai gambar tengah dan kanan
                PrintNodeInfo(tree);  // Menampilkan informasi setiap node
                break;
            case 6:
                {
                    char key;
                    printf("\nMasukkan karakter yang ingin dicari: ");
                    getchar();  // Menangani masalah buffer
                    scanf("%c", &key);
                    
                    key = toupper(key);

                    if (Search(tree, key)) {
                        printf("Node dengan nilai '%c' ditemukan dalam pohon.\n", key);
                    } else {
                        printf("Node dengan nilai '%c' tidak ditemukan.\n", key);
                    }
                }
                break;
            case 7:
                printf("\nJumlah daun: %d\n", nbDaun(tree));
                break;
            case 8:
                {
                    char node;
                    printf("\nMasukkan karakter node yang ingin dicari levelnya: ");
                    getchar();  // Menangani masalah buffer
                    scanf("%c", &node);
                    node = toupper(node);

                    int levelNode = Level(tree, node);
                    if (levelNode == -1) {
                        printf("Node dengan nilai '%c' tidak ditemukan.\n", node);
                    } else {
                        printf("Node dengan nilai '%c' berada pada level %d.\n", node, levelNode);
                    }
                }
                break;
            case 9:
                printf("\nKedalaman pohon: %d\n", Depth(tree));
                break;
            case 10:
                {
                    char node1, node2;
                    printf("\nMasukkan karakter node pertama: ");
                    getchar();  // Menangani masalah buffer
                    scanf("%c", &node1);
                    getchar();  // Menangani masalah buffer
                    printf("Masukkan karakter node kedua: ");
                    scanf("%c", &node2);
                    
                    // Ubah kedua node menjadi huruf besar
        			node1 = toupper(node1);
        			node2 = toupper(node2);

                    int levelNode1 = Level(tree, node1);
                    int levelNode2 = Level(tree, node2);

                    if (levelNode1 == -1 || levelNode2 == -1) {
                        printf("Salah satu atau kedua node tidak ditemukan.\n");
                    } else {
                        if (levelNode1 == levelNode2) {
                            printf("Node '%c' dan '%c' berada pada level yang sama.\n", node1, node2);
                        } else {
                            printf("Node '%c' berada pada level %d dan node '%c' berada pada level %d.\n", node1, levelNode1, node2, levelNode2);
                        }
                    }
                }
                break;
            case 11:
                printf("Keluar program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    }
}

