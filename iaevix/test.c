#include "core.h"

int main(int argc, char *argv[])
{
    IRFLOAT A = 12.25;
    IRINT B = 17;
    IOBJECT A_, B_, S;
    A_.type = ITYPE_FLOAT;
    B_.type = ITYPE_INT;
    A_.location = (void*)(&A);
    B_.location = (void*)(&B);
    S = __add__(&A_, &B_);
    printf("%Lg", *(IRFLOAT*)(S.location));
    return 0;
}
