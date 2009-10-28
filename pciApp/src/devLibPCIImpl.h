
#ifndef DEVLIBPCIIMPL_H_INC
#define DEVLIBPCIIMPL_H_INC

#include <ellLib.h>
#include <shareLib.h>
#include <epicsTypes.h>

#include "devLibPCI.h"

#ifdef __cplusplus
extern "C" {
#endif

struct osdPCIDevice {
  epicsPCIDevice dev; /* "public" data */
  ELLNODE node;
  void *drvpvt; /* for out of tree drivers */
};
typedef struct osdPCIDevice osdPCIDevice;

#define osd2epicsDev(osd) CONTAINER(osd,const osdPCIDevice,dev)

typedef struct {

  /*
   * Find all by Device and Vender only.  Append to the list 'store'.
   */
  int (*pDevPCIFind)(epicsUInt16 dev,epicsUInt16 vend,ELLLIST* store);

  int (*pDevPCIToLocalAddr)(struct osdPCIDevice* dev,unsigned int bar,volatile void **a);

} devLibPCIVirtualOS;

epicsShareExtern devLibPCIVirtualOS *pdevLibPCIVirtualOS;

/* Functions for OS support implementors */

epicsShareFunc
int
devPCIToLocalAddr_General(
  struct osdPCIDevice* dev,
  unsigned int bar,
  volatile void **ppLocalAddr
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* DEVLIBPCIIMPL_H_INC */
