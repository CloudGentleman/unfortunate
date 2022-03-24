
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>


/*! \enum ITYPE
 *
 *  Iaevix Types
 */
typedef enum {
    ITYPE_ERR,
    ITYPE_OBJ,
    ITYPE_INT,
    ITYPE_FLOAT,
    ITYPE_STR,
    ITYPE_BOOL
} ITYPE;

/*! \struct IOBJECT
 *  \brief Iaevix Generic Object
 */
typedef struct {
    ITYPE type;
    void* location;
} IOBJECT;

typedef struct {
    void* attr;
    long long size;
} IROBJECT;

typedef long long            IRINT;

typedef long double          IRFLOAT;

IOBJECT __add__(IOBJECT* L, IOBJECT* R);

#ifdef __cplusplus
}
#endif
