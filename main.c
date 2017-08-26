#include "packages.h"

void show_bytes(unsigned char* start, size_t len) {
    size_t i;
    for (i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    LoopBuffer L_buf;
    init_buffer(&L_buf, 200);

    // printf("%d\n", sizeof(struct PackageHead));
    // printf("%d\n", sizeof(struct DataPackage1));


    int i, j;
    for (i = 0; i < 11; ++i) {
        struct DataPackage1 dp1;
        DataPackage1_init(&dp1);
        memset(dp1.something, 1, sizeof(dp1.something));
        // show_bytes((unsigned char*)dp1.something, 10);
        int k = write_package(&dp1, &L_buf, sizeof(dp1));
        if (k > 0) {
            printf("write dp1 package to L_buf: success\n");
        } else if (k == 0){
            printf("write dp1 package to L_buf: fail\n");
        } else if (k < 0) {
            printf("write dp1 package to L_buf: no more memory\n");
        }
        // if (write_package(&dp1, &L_buf, sizeof(dp1)) > 0) {
        //     printf("write dp1 package to L_buf: success\n");
        // } else {
        //     printf("write dp1 package to L_buf: fail\n");
        // }
    }

    BYTE* p = (BYTE*)malloc(20);
    for (i = 0; i < 11; ++i) {
        if (read_package(p, &L_buf)) {
            show_bytes((unsigned char*)p, 10);
        } else {
            printf("read dp1 package fail\n");
        }
    }
    return 0;
}
