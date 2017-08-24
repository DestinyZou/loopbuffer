#ifndef _PACKAGES__
#define _PACKAGES__

#include "loopbuffer.h"

enum package_type {en_dp1, en_dp2, en_dp3};

struct PackageHead {
    enum package_type type;
    unsigned size;
};

struct DataPackage1 {
    struct PackageHead package_head;
    char something[10];
};

struct DataPackage2 {
    struct PackageHead package_head;
    char something[100];
};

struct DataPackage3 {
    struct PackageHead package_head;
    char something[50];
};

int read_package(void* package, LoopBuffer* L_buf);
int write_package(void* package, LoopBuffer* L_buf, unsigned len);
void DataPackage1_init(struct DataPackage1* dp);
void DataPackage2_init(struct DataPackage1* dp);
void DataPackage3_init(struct DataPackage1* dp);

#endif /* end of include guard: _PACKAGES__ */
