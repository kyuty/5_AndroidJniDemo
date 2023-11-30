// Copyright 2020-2021, Collabora, Ltd.
// SPDX-License-Identifier: BSL-1.0
// Author: Ryan Pavlik <ryan.pavlik@collabora.com>

#pragma once

#include "ObjectWrapperBase.h"

namespace wrap {
namespace android::text {
class TextUtils_TruncateAt;
} // namespace android::text

} // namespace wrap

namespace wrap {
namespace android::text {
/*!
 * Wrapper for android.text.TextUtils objects.
 */
class TextUtils : public ObjectWrapperBase {
  public:
    using ObjectWrapperBase::ObjectWrapperBase;
    static constexpr const char *getTypeName() noexcept {
        return "android/text/TextUtils";
    }

    /*!
     * Wrapper for the ellipsize static method
     *
     * Java prototype:
     * `public static java.lang.CharSequence ellipsize(java.lang.CharSequence,
     * android.text.TextPaint, float, android.text.TextUtils$TruncateAt);`
     *
     * JNI signature:
     * (Ljava/lang/CharSequence;Landroid/text/TextPaint;FLandroid/text/TextUtils$TruncateAt;)Ljava/lang/CharSequence;
     *
     */
    static jni::Object ellipsize(jni::Object &charSequence,
                                 jni::Object &textPaint, float floatParam,
                                 TextUtils_TruncateAt &textUtils_TruncateAt);

    /*!
     * Wrapper for the ellipsize static method
     *
     * Java prototype:
     * `public static java.lang.CharSequence ellipsize(java.lang.CharSequence,
     * android.text.TextPaint, float, android.text.TextUtils$TruncateAt,
     * boolean, android.text.TextUtils$EllipsizeCallback);`
     *
     * JNI signature:
     * (Ljava/lang/CharSequence;Landroid/text/TextPaint;FLandroid/text/TextUtils$TruncateAt;ZLandroid/text/TextUtils$EllipsizeCallback;)Ljava/lang/CharSequence;
     *
     */
    static jni::Object ellipsize(jni::Object &charSequence,
                                 jni::Object &textPaint, float floatParam,
                                 TextUtils_TruncateAt &textUtils_TruncateAt,
                                 bool booleanParam,
                                 jni::Object &textUtils_EllipsizeCallback);

    /*!
     * Class metadata
     */
    struct Meta : public MetaBaseDroppable {
        jni::method_t ellipsize;
        jni::method_t ellipsize1;

        /*!
         * Singleton accessor
         */
        static Meta &data() {
            static Meta instance{};
            return instance;
        }

      private:
        Meta();
    };
};
/*!
 * Wrapper for android.text.TextUtils$TruncateAt objects.
 */
class TextUtils_TruncateAt : public ObjectWrapperBase {
  public:
    using ObjectWrapperBase::ObjectWrapperBase;
    static constexpr const char *getTypeName() noexcept {
        return "android/text/TextUtils$TruncateAt";
    }

    /*!
     * Getter for the END static field value
     *
     * Java prototype:
     * `public static final android.text.TextUtils$TruncateAt END;`
     *
     * JNI signature: Landroid/text/TextUtils$TruncateAt;
     *
     */
    static TextUtils_TruncateAt END();

    /*!
     * Class metadata
     */
    struct Meta : public MetaBaseDroppable {
        impl::StaticFieldId<TextUtils_TruncateAt> END;

        /*!
         * Singleton accessor
         */
        static Meta &data() {
            static Meta instance{};
            return instance;
        }

      private:
        Meta();
    };
};
} // namespace android::text
} // namespace wrap
#include "android.text.impl.h"
