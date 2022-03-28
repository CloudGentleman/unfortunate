#include "core.h"

void _fall_error(IOBJECT* obj) {
    obj->type = ITYPE_ERR;
    obj->location = NULL;
}

IOBJECT __add__(IOBJECT* L, IOBJECT* R) {
    IOBJECT RET;
    if (L->type == ITYPE_FLOAT) {
        if (R->type == ITYPE_FLOAT) {
            // float + float
            IRFLOAT swp = *(IRFLOAT*)(L->location) + *(IRFLOAT*)(R->location);
            RET.type = ITYPE_FLOAT;
            RET.location = (void*)(&swp);
        } else if (R->type == ITYPE_INT) {
            // float + int
            IRFLOAT swp = *(IRFLOAT*)(L->location) + *(IRINT*)(R->location);
            RET.type = ITYPE_FLOAT;
            RET.location = (void*)(&swp);
        } else {
            _fall_error(&RET);
        }
    } else if (L->type == ITYPE_INT) {
        if (R->type == ITYPE_FLOAT) {
            // int + float
            IRFLOAT swp = *(IRFLOAT*)(R->location) + *(IRINT*)(L->location);
            RET.type = ITYPE_FLOAT;
            RET.location = (void*)(&swp);
        } else if (R->type == ITYPE_INT) {
            // int + int
            IRINT swp = *(IRINT*)(L->location) + *(IRINT*)(R->location);
            RET.type = ITYPE_INT;
            RET.location = (void*)(&swp);
        } else {
            _fall_error(&RET);
        }
    } else {
        fprintf(stderr, "Error: Unable to add two values.\n");
        _fall_error(&RET);
    }
    return RET;
}
