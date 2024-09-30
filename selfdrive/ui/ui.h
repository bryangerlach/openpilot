#pragma once

<<<<<<< HEAD
#include <memory>
#include <string>

#include <QObject>
=======
#include <eigen3/Eigen/Dense>
#include <memory>
#include <string>

>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
#include <QTimer>
#include <QColor>
#include <QFuture>
#include <QPolygonF>
<<<<<<< HEAD
#include <QTransform>
=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

#include "cereal/messaging/messaging.h"
#include "common/mat.h"
#include "common/params.h"
<<<<<<< HEAD
#include "common/timing.h"
#include "system/hardware/hw.h"
=======
#include "common/util.h"
#include "system/hardware/hw.h"
#include "selfdrive/ui/qt/prime_state.h"
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

const int UI_BORDER_SIZE = 30;
const int UI_HEADER_HEIGHT = 420;

const int UI_FREQ = 20; // Hz
const int BACKLIGHT_OFFROAD = 50;

const float MIN_DRAW_DISTANCE = 10.0;
const float MAX_DRAW_DISTANCE = 100.0;
<<<<<<< HEAD
constexpr mat3 DEFAULT_CALIBRATION = {{ 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0 }};
constexpr mat3 FCAM_INTRINSIC_MATRIX = (mat3){{2648.0, 0.0, 1928.0 / 2,
                                           0.0, 2648.0, 1208.0 / 2,
                                           0.0, 0.0, 1.0}};
// tici ecam focal probably wrong? magnification is not consistent across frame
// Need to retrain model before this can be changed
constexpr mat3 ECAM_INTRINSIC_MATRIX = (mat3){{567.0, 0.0, 1928.0 / 2,
                                           0.0, 567.0, 1208.0 / 2,
                                           0.0, 0.0, 1.0}};


constexpr vec3 default_face_kpts_3d[] = {
  {-5.98, -51.20, 8.00}, {-17.64, -49.14, 8.00}, {-23.81, -46.40, 8.00}, {-29.98, -40.91, 8.00}, {-32.04, -37.49, 8.00},
  {-34.10, -32.00, 8.00}, {-36.16, -21.03, 8.00}, {-36.16, 6.40, 8.00}, {-35.47, 10.51, 8.00}, {-32.73, 19.43, 8.00},
  {-29.30, 26.29, 8.00}, {-24.50, 33.83, 8.00}, {-19.01, 41.37, 8.00}, {-14.21, 46.17, 8.00}, {-12.16, 47.54, 8.00},
  {-4.61, 49.60, 8.00}, {4.99, 49.60, 8.00}, {12.53, 47.54, 8.00}, {14.59, 46.17, 8.00}, {19.39, 41.37, 8.00},
  {24.87, 33.83, 8.00}, {29.67, 26.29, 8.00}, {33.10, 19.43, 8.00}, {35.84, 10.51, 8.00}, {36.53, 6.40, 8.00},
  {36.53, -21.03, 8.00}, {34.47, -32.00, 8.00}, {32.42, -37.49, 8.00}, {30.36, -40.91, 8.00}, {24.19, -46.40, 8.00},
  {18.02, -49.14, 8.00}, {6.36, -51.20, 8.00}, {-5.98, -51.20, 8.00},
};

//Example of a macro
#ifdef SUNNYPILOT
#define EXTRA_UI_STATES STATUS_MADS
#else
#define EXTRA_UI_STATES
#endif
=======
const Eigen::Matrix3f VIEW_FROM_DEVICE = (Eigen::Matrix3f() <<
  0.0, 1.0, 0.0,
  0.0, 0.0, 1.0,
  1.0, 0.0, 0.0).finished();

const Eigen::Matrix3f FCAM_INTRINSIC_MATRIX = (Eigen::Matrix3f() <<
  2648.0, 0.0, 1928.0 / 2,
  0.0, 2648.0, 1208.0 / 2,
  0.0, 0.0, 1.0).finished();

// tici ecam focal probably wrong? magnification is not consistent across frame
// Need to retrain model before this can be changed
const Eigen::Matrix3f ECAM_INTRINSIC_MATRIX = (Eigen::Matrix3f() <<
  567.0, 0.0, 1928.0 / 2,
  0.0, 567.0, 1208.0 / 2,
  0.0, 0.0, 1.0).finished();
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

typedef enum UIStatus {
  STATUS_DISENGAGED,
  STATUS_OVERRIDE,
  STATUS_ENGAGED,
<<<<<<< HEAD
  EXTRA_UI_STATES
} UIStatus;

enum PrimeType {
  UNKNOWN = -2,
  UNPAIRED = -1,
  NONE = 0,
  MAGENTA = 1,
  LITE = 2,
  BLUE = 3,
  MAGENTA_NEW = 4,
  PURPLE = 5,
};

=======
} UIStatus;

>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
const QColor bg_colors [] = {
  [STATUS_DISENGAGED] = QColor(0x17, 0x33, 0x49, 0xc8),
  [STATUS_OVERRIDE] = QColor(0x91, 0x9b, 0x95, 0xf1),
  [STATUS_ENGAGED] = QColor(0x17, 0x86, 0x44, 0xf1),
};

<<<<<<< HEAD

typedef struct UIScene {
  bool calibration_valid = false;
  bool calibration_wide_valid  = false;
  bool wide_cam = true;
  mat3 view_from_calib = DEFAULT_CALIBRATION;
  mat3 view_from_wide_calib = DEFAULT_CALIBRATION;
=======
typedef struct UIScene {
  Eigen::Matrix3f view_from_calib = VIEW_FROM_DEVICE;
  Eigen::Matrix3f view_from_wide_calib = VIEW_FROM_DEVICE;
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  cereal::PandaState::PandaType pandaType;

  // modelV2
  float lane_line_probs[4];
  float road_edge_stds[2];
  QPolygonF track_vertices;
  QPolygonF lane_line_vertices[4];
  QPolygonF road_edge_vertices[2];

  // lead
  QPointF lead_vertices[2];

<<<<<<< HEAD
  // DMoji state
  float driver_pose_vals[3];
  float driver_pose_diff[3];
  float driver_pose_sins[3];
  float driver_pose_coss[3];
  vec3 face_kpts_draw[std::size(default_face_kpts_3d)];

=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  cereal::LongitudinalPersonality personality;

  float light_sensor = -1;
  bool started, ignition, is_metric, longitudinal_control;
  bool world_objects_visible = false;
  uint64_t started_frame;
} UIScene;

<<<<<<< HEAD
#ifdef SUNNYPILOT
#include "sunnypilot/qt/ui_scene.h"
#define UIScene UISceneSP
#endif
=======
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
class UIState : public QObject {
  Q_OBJECT

public:
  UIState(QObject* parent = 0);
<<<<<<< HEAD
  virtual void updateStatus();
  inline bool engaged() const {
    return scene.started && (*sm)["controlsState"].getControlsState().getEnabled();
  }

  void setPrimeType(PrimeType type);
  inline PrimeType primeType() const { return prime_type; }
  inline bool hasPrime() const { return prime_type > PrimeType::NONE; }

  int fb_w = 0, fb_h = 0;

  std::unique_ptr<SubMaster> sm;

=======
  void updateStatus();
  inline bool engaged() const {
    return scene.started && (*sm)["selfdriveState"].getSelfdriveState().getEnabled();
  }

  std::unique_ptr<SubMaster> sm;
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  UIStatus status;
  UIScene scene = {};

  QString language;
<<<<<<< HEAD

  QTransform car_space_transform;
=======
  PrimeState *prime_state;

  Eigen::Matrix3f car_space_transform = Eigen::Matrix3f::Zero();
  QRectF clip_region;
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

signals:
  void uiUpdate(const UIState &s);
  void offroadTransition(bool offroad);
<<<<<<< HEAD
  void primeChanged(bool prime);
  void primeTypeChanged(PrimeType prime_type);

protected slots:
  virtual void update();

protected:
  QTimer *timer;
  PrimeType prime_type = PrimeType::UNKNOWN;

private:  
  bool started_prev = false;
};
#undef UIScene

#ifndef SUNNYPILOT
UIState *uiState();
#endif
=======

private slots:
  void update();

private:
  QTimer *timer;
  bool started_prev = false;
};

UIState *uiState();
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

// device management class
class Device : public QObject {
  Q_OBJECT

public:
  Device(QObject *parent = 0);
  bool isAwake() { return awake; }
  void setOffroadBrightness(int brightness) {
    offroad_brightness = std::clamp(brightness, 0, 100);
  }

<<<<<<< HEAD
protected:
=======
private:
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
  bool awake = false;
  int interactive_timeout = 0;
  bool ignition_on = false;

  int offroad_brightness = BACKLIGHT_OFFROAD;
  int last_brightness = 0;
  FirstOrderFilter brightness_filter;
  QFuture<void> brightness_future;

<<<<<<< HEAD
  virtual void updateBrightness(const UIState &s);
  void updateWakefulness(const UIState &s);
  void setAwake(bool on);
  float clipped_brightness;
=======
  void updateBrightness(const UIState &s);
  void updateWakefulness(const UIState &s);
  void setAwake(bool on);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

signals:
  void displayPowerChanged(bool on);
  void interactiveTimeout();

public slots:
  void resetInteractiveTimeout(int timeout = -1);
  void update(const UIState &s);
};

<<<<<<< HEAD
#ifndef SUNNYPILOT
Device *device();
#endif
=======
Device *device();
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e

void ui_update_params(UIState *s);
int get_path_length_idx(const cereal::XYZTData::Reader &line, const float path_height);
void update_model(UIState *s,
                  const cereal::ModelDataV2::Reader &model);
<<<<<<< HEAD
void update_dmonitoring(UIState *s, const cereal::DriverStateV2::Reader &driverstate, float dm_fade_state, bool is_rhd);
void update_leads(UIState *s, const cereal::RadarState::Reader &radar_state, const cereal::XYZTData::Reader &line);
void update_line_data(const UIState *s, const cereal::XYZTData::Reader &line,
                      float y_off, float z_off, QPolygonF *pvd, int max_idx, bool allow_invert);

bool calib_frame_to_full_frame(const UIState *s, float in_x, float in_y, float in_z, QPointF *out, float margin=500.0f);
void update_state(UIState *s);
void update_sockets(UIState *s);
=======
void update_leads(UIState *s, const cereal::RadarState::Reader &radar_state, const cereal::XYZTData::Reader &line);
void update_line_data(const UIState *s, const cereal::XYZTData::Reader &line,
                      float y_off, float z_off, QPolygonF *pvd, int max_idx, bool allow_invert);
>>>>>>> 21af6b508f6e06d6f0fcb1b191cbc42514ecf01e
