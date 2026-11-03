#ifndef NEW_HORIZONS_APP_CORE_H
#define NEW_HORIZONS_APP_CORE_H

#include "new_horizons_static_recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

int new_horizons_recomp_write_diagnostic_log(
    const NewHorizonsRecomp *instance, const char *path,
    const char *screenshot_path, char *error, size_t error_capacity);
int new_horizons_recomp_append_diagnostic_log(
    const NewHorizonsRecomp *instance, const char *path,
    const char *section_title, char *error, size_t error_capacity);
/* Development terrain-stage capture, not the completed widescreen composite. */
int new_horizons_recomp_read_port_terrain(const NewHorizonsRecomp *instance,
    uint16_t *bgr555, uint32_t capacity, unsigned *origin_y);
int new_horizons_recomp_read_port_world(const NewHorizonsRecomp *instance,
    uint16_t *bgr555, uint32_t capacity, unsigned *origin_y);
int new_horizons_recomp_enable_port_ui_capture(NewHorizonsRecomp *instance);
/* Diagnostic native baseline only; rejects a requested wide display. */
int new_horizons_recomp_disable_port_ui_capture(NewHorizonsRecomp *instance);
int new_horizons_recomp_observe_sea_weather(const NewHorizonsRecomp *instance,
    uint8_t *weather, uint8_t *mosaic);
int new_horizons_recomp_read_port_frame(const NewHorizonsRecomp *instance,
    uint16_t *bgr555, uint32_t capacity, unsigned *origin_y);
/* Same scene-qualified composite used by the actual display.
 * Scene is1=Port,2=Combat,3=Sailing; unsupported/incomplete views remain native. */
int new_horizons_recomp_read_presentation_frame(const NewHorizonsRecomp *instance,
    uint16_t *bgr555, uint32_t capacity, unsigned *origin_y, unsigned *scene);

#ifdef __cplusplus
}
#endif
#endif
