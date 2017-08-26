#include "packages.h"

int read_package(void* package, LoopBuffer* L_buf) {
    if (!package && !L_buf)
        return 0;
    struct PackageHead* ph = (struct PackageHead*)malloc(sizeof(struct PackageHead));
    if (read_from_buffer(L_buf, (BYTE*)ph, sizeof(struct PackageHead)) > 0) {
        if (read_from_buffer(L_buf, (BYTE*)package, ph->size) > 0) {
            free(ph);
            return 1;
        }
    } else {
        return 0;
    }
}

int write_package(void* package, LoopBuffer* L_buf, unsigned len) {
    if (!package && !L_buf)
        return 0;
    return write_from_buffer(L_buf, (BYTE*)package, len);
}

void DataPackage1_init(struct DataPackage1* dp) {
    dp->package_head.type = en_dp1;
    dp->package_head.size = sizeof(struct DataPackage1) - sizeof(struct PackageHead);
}

void DataPackage2_init(struct DataPackage1* dp) {
    dp->package_head.type = en_dp2;
    dp->package_head.size = sizeof(struct DataPackage2) - sizeof(struct PackageHead);
}

void DataPackage3_init(struct DataPackage1* dp) {
    dp->package_head.type = en_dp3;
    dp->package_head.size = sizeof(struct DataPackage3) - sizeof(struct PackageHead);
}
