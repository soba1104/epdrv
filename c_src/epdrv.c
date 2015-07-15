#include <string.h>
#include "erl_driver.h"

typedef struct {
  ErlDrvPort port;
} epdrv_state_t;

static ErlDrvData epdrv_drv_start(ErlDrvPort port, char *buf) {
  epdrv_state_t *state = (epdrv_state_t*)driver_alloc(sizeof(epdrv_state_t));
  state->port = port;
  return (ErlDrvData)state;
}

static void epdrv_drv_stop(ErlDrvData handle) {
  driver_free((char*)handle);
}

static void epdrv_drv_output(ErlDrvData handle, char *buf, ErlDrvSizeT bufsize) {
  epdrv_state_t *state = (epdrv_state_t*)handle;
  char *msg = "hello epdrv\n";
  driver_output(state->port, msg, strlen(msg));
}

ErlDrvEntry epdrv_driver_entry = {
  NULL, // init
  epdrv_drv_start, // start
  epdrv_drv_stop, // stop
  epdrv_drv_output, // output
  NULL, // ready_input
  NULL, // ready_output
  "epdrv", // driver name
  NULL, // finish
  NULL, // void *handle, reserved by vm
  NULL, // control
  NULL, // timeout, reserved
  NULL, // outputv, reserved
  NULL, // ready_async
  NULL, // flush
  NULL, // call
  NULL, // event
  ERL_DRV_EXTENDED_MARKER,
  ERL_DRV_EXTENDED_MAJOR_VERSION,
  ERL_DRV_EXTENDED_MINOR_VERSION,
  0, // driver_flags
  NULL, // handle2, reserved by vm
  NULL, // process_exit
  NULL, // stop_select
};

DRIVER_INIT(epdrv) {
  return &epdrv_driver_entry;
}
