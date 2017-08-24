#include "packages.h"

int main(int argc, char const *argv[])
{
    LoopBuffer L_buf;
    init_buffer(&L_buf, 200);

    int i = 0;
    for (i = 0; i < 10; ++i) {
        struct DataPackage1 dp1;
        DataPackage1_init(&dp1);
        if (write_package(&dp1, &L_buf, sizeof(dp1))) {
            printf("write dp1 package to L_buf: success\n");
        } else {
            printf("write dp1 package to L_buf: fail\n");
        }
    }
    return 0;
}
