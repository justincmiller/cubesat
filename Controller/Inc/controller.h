#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Call once after osKernelInitialize and before osKernelStart. */
void Controller_Init(void);

#ifdef __cplusplus
}
#endif
