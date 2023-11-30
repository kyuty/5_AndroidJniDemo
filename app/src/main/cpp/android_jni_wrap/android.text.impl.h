// Copyright 2020-2021, Collabora, Ltd.
// SPDX-License-Identifier: BSL-1.0
// Author: Ryan Pavlik <ryan.pavlik@collabora.com>

#pragma once

namespace wrap {
namespace android::text {
inline jni::Object
TextUtils::ellipsize(jni::Object &charSequence, jni::Object &textPaint,
                     float floatParam,
                     TextUtils_TruncateAt &textUtils_TruncateAt) {
    return Meta::data().clazz().call<jni::Object>(
        Meta::data().ellipsize, charSequence, textPaint, floatParam,
        textUtils_TruncateAt.object());
}

inline jni::Object TextUtils::ellipsize(
    jni::Object &charSequence, jni::Object &textPaint, float floatParam,
    TextUtils_TruncateAt &textUtils_TruncateAt, bool booleanParam,
    jni::Object &textUtils_EllipsizeCallback) {
    return Meta::data().clazz().call<jni::Object>(
        Meta::data().ellipsize1, charSequence, textPaint, floatParam,
        textUtils_TruncateAt.object(), booleanParam,
        textUtils_EllipsizeCallback);
}
inline TextUtils_TruncateAt TextUtils_TruncateAt::END() {
    return get(Meta::data().END, Meta::data().clazz());
}
} // namespace android::text
} // namespace wrap
