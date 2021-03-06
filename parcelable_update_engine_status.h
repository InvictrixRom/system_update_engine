//
// Copyright (C) 2016 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef UPDATE_ENGINE_UPDATE_ENGINE_STATUS_H_
#define UPDATE_ENGINE_UPDATE_ENGINE_STATUS_H_

#include <binder/Parcelable.h>
#include <utils/String16.h>

namespace android {
namespace brillo {

// Parcelable object containing the current status of update engine, to be sent
// over binder to clients from the server.
class ParcelableUpdateEngineStatus : public Parcelable {
 public:
  ParcelableUpdateEngineStatus() = default;
  virtual ~ParcelableUpdateEngineStatus() = default;

  status_t writeToParcel(Parcel* parcel) const override;
  status_t readFromParcel(const Parcel* parcel) override;

  int64_t last_checked_time_;
  double progress_;
  android::String16 current_operation_;
  android::String16 new_version_;
  int64_t new_size_;
};

}  // namespace brillo
}  // namespace android

#endif  // UPDATE_ENGINE_UPDATE_ENGINE_STATUS_H_
