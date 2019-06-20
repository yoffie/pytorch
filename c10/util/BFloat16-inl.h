#pragma once

#include <cstring>
#include <limits>
#include <c10/macros/Macros.h>

namespace c10 {

/// Constructors

inline C10_HOST_DEVICE BFloat16::BFloat16(float value) {
  x = detail::fp16_ieee_from_fp32_value2(value);
}

/// Implicit conversions

inline C10_HOST_DEVICE BFloat16::operator float() const {
  return detail::fp16_ieee_to_fp32_value2(x);
}


/// Arithmetic

inline C10_HOST_DEVICE BFloat16 operator+(const BFloat16& a, const BFloat16& b) {
  return static_cast<float>(a) + static_cast<float>(b);
}

inline C10_HOST_DEVICE BFloat16 operator-(const BFloat16& a, const BFloat16& b) {
  return static_cast<float>(a) - static_cast<float>(b);
}

inline C10_HOST_DEVICE BFloat16 operator*(const BFloat16& a, const BFloat16& b) {
  return static_cast<float>(a) * static_cast<float>(b);
}

inline C10_HOST_DEVICE BFloat16 operator/(const BFloat16& a, const BFloat16& b) {
  return static_cast<float>(a) / static_cast<float>(b);
}

inline C10_HOST_DEVICE BFloat16 operator-(const BFloat16& a) {
  return -static_cast<float>(a);
}

inline C10_HOST_DEVICE BFloat16& operator+=(BFloat16& a, const BFloat16& b) {
  a = a + b;
  return a;
}

inline C10_HOST_DEVICE BFloat16& operator-=(BFloat16& a, const BFloat16& b) {
  a = a - b;
  return a;
}

inline C10_HOST_DEVICE BFloat16& operator*=(BFloat16& a, const BFloat16& b) {
  a = a * b;
  return a;
}

inline C10_HOST_DEVICE BFloat16& operator/=(BFloat16& a, const BFloat16& b) {
  a = a / b;
  return a;
}

/// Arithmetic with floats

inline C10_HOST_DEVICE float operator+(BFloat16 a, float b) {
  return static_cast<float>(a) + b;
}
inline C10_HOST_DEVICE float operator-(BFloat16 a, float b) {
  return static_cast<float>(a) - b;
}
inline C10_HOST_DEVICE float operator*(BFloat16 a, float b) {
  return static_cast<float>(a) * b;
}
inline C10_HOST_DEVICE float operator/(BFloat16 a, float b) {
  return static_cast<float>(a) / b;
}

inline C10_HOST_DEVICE float operator+(float a, BFloat16 b) {
  return a + static_cast<float>(b);
}
inline C10_HOST_DEVICE float operator-(float a, BFloat16 b) {
  return a - static_cast<float>(b);
}
inline C10_HOST_DEVICE float operator*(float a, BFloat16 b) {
  return a * static_cast<float>(b);
}
inline C10_HOST_DEVICE float operator/(float a, BFloat16 b) {
  return a / static_cast<float>(b);
}

inline C10_HOST_DEVICE float& operator+=(float& a, const BFloat16& b) {
  return a += static_cast<float>(b);
}
inline C10_HOST_DEVICE float& operator-=(float& a, const BFloat16& b) {
  return a -= static_cast<float>(b);
}
inline C10_HOST_DEVICE float& operator*=(float& a, const BFloat16& b) {
  return a *= static_cast<float>(b);
}
inline C10_HOST_DEVICE float& operator/=(float& a, const BFloat16& b) {
  return a /= static_cast<float>(b);
}

/// Arithmetic with doubles

inline C10_HOST_DEVICE double operator+(BFloat16 a, double b) {
  return static_cast<double>(a) + b;
}
inline C10_HOST_DEVICE double operator-(BFloat16 a, double b) {
  return static_cast<double>(a) - b;
}
inline C10_HOST_DEVICE double operator*(BFloat16 a, double b) {
  return static_cast<double>(a) * b;
}
inline C10_HOST_DEVICE double operator/(BFloat16 a, double b) {
  return static_cast<double>(a) / b;
}

inline C10_HOST_DEVICE double operator+(double a, BFloat16 b) {
  return a + static_cast<double>(b);
}
inline C10_HOST_DEVICE double operator-(double a, BFloat16 b) {
  return a - static_cast<double>(b);
}
inline C10_HOST_DEVICE double operator*(double a, BFloat16 b) {
  return a * static_cast<double>(b);
}
inline C10_HOST_DEVICE double operator/(double a, BFloat16 b) {
  return a / static_cast<double>(b);
}

/// Arithmetic with ints

inline C10_HOST_DEVICE BFloat16 operator+(BFloat16 a, int b) {
  return a + static_cast<BFloat16>(b);
}
inline C10_HOST_DEVICE BFloat16 operator-(BFloat16 a, int b) {
  return a - static_cast<BFloat16>(b);
}
inline C10_HOST_DEVICE BFloat16 operator*(BFloat16 a, int b) {
  return a * static_cast<BFloat16>(b);
}
inline C10_HOST_DEVICE BFloat16 operator/(BFloat16 a, int b) {
  return a / static_cast<BFloat16>(b);
}

inline C10_HOST_DEVICE BFloat16 operator+(int a, BFloat16 b) {
  return static_cast<BFloat16>(a) + b;
}
inline C10_HOST_DEVICE BFloat16 operator-(int a, BFloat16 b) {
  return static_cast<BFloat16>(a) - b;
}
inline C10_HOST_DEVICE BFloat16 operator*(int a, BFloat16 b) {
  return static_cast<BFloat16>(a) * b;
}
inline C10_HOST_DEVICE BFloat16 operator/(int a, BFloat16 b) {
  return static_cast<BFloat16>(a) / b;
}

//// Arithmetic with int64_t

inline C10_HOST_DEVICE BFloat16 operator+(BFloat16 a, int64_t b) {
  return a + static_cast<BFloat16>(b);
}
inline C10_HOST_DEVICE BFloat16 operator-(BFloat16 a, int64_t b) {
  return a - static_cast<BFloat16>(b);
}
inline C10_HOST_DEVICE BFloat16 operator*(BFloat16 a, int64_t b) {
  return a * static_cast<BFloat16>(b);
}
inline C10_HOST_DEVICE BFloat16 operator/(BFloat16 a, int64_t b) {
  return a / static_cast<BFloat16>(b);
}

inline C10_HOST_DEVICE BFloat16 operator+(int64_t a, BFloat16 b) {
  return static_cast<BFloat16>(a) + b;
}
inline C10_HOST_DEVICE BFloat16 operator-(int64_t a, BFloat16 b) {
  return static_cast<BFloat16>(a) - b;
}
inline C10_HOST_DEVICE BFloat16 operator*(int64_t a, BFloat16 b) {
  return static_cast<BFloat16>(a) * b;
}
inline C10_HOST_DEVICE BFloat16 operator/(int64_t a, BFloat16 b) {
  return static_cast<BFloat16>(a) / b;
}

/// NOTE: we do not define comparisons directly and instead rely on the implicit
/// conversion from c10::BFloat16 to float.

} // namespace c10

namespace std {

template <>
class numeric_limits<c10::BFloat16> {
 public:
  static constexpr bool is_specialized = true;
  static constexpr bool is_signed = true;
  static constexpr bool is_integer = false;
  static constexpr bool is_exact = false;
  static constexpr bool has_infinity = true;
  static constexpr bool has_quiet_NaN = true;
  static constexpr bool has_signaling_NaN = true;
  static constexpr auto has_denorm = numeric_limits<float>::has_denorm;
  static constexpr auto has_denorm_loss =
      numeric_limits<float>::has_denorm_loss;
  static constexpr auto round_style = numeric_limits<float>::round_style;
  static constexpr bool is_iec559 = true;
  static constexpr bool is_bounded = true;
  static constexpr bool is_modulo = false;
  static constexpr int digits = 11;
  static constexpr int digits10 = 3;
  static constexpr int max_digits10 = 5;
  static constexpr int radix = 2;
  static constexpr int min_exponent = -13;
  static constexpr int min_exponent10 = -4;
  static constexpr int max_exponent = 16;
  static constexpr int max_exponent10 = 4;
  static constexpr auto traps = numeric_limits<float>::traps;
  static constexpr auto tinyness_before =
      numeric_limits<float>::tinyness_before;
  static constexpr c10::BFloat16 min() {
    return c10::BFloat16(0x0400, c10::BFloat16::from_bits());
  }
  static constexpr c10::BFloat16 lowest() {
    return c10::BFloat16(0xFBFF, c10::BFloat16::from_bits());
  }
  static constexpr c10::BFloat16 max() {
    return c10::BFloat16(0x7BFF, c10::BFloat16::from_bits());
  }
  static constexpr c10::BFloat16 epsilon() {
    return c10::BFloat16(0x1400, c10::BFloat16::from_bits());
  }
  static constexpr c10::BFloat16 round_error() {
    return c10::BFloat16(0x3800, c10::BFloat16::from_bits());
  }
  static constexpr c10::BFloat16 infinity() {
    return c10::BFloat16(0x7C00, c10::BFloat16::from_bits());
  }
  static constexpr c10::BFloat16 quiet_NaN() {
    return c10::BFloat16(0x7E00, c10::BFloat16::from_bits());
  }
  static constexpr c10::BFloat16 signaling_NaN() {
    return c10::BFloat16(0x7D00, c10::BFloat16::from_bits());
  }
  static constexpr c10::BFloat16 denorm_min() {
    return c10::BFloat16(0x0001, c10::BFloat16::from_bits());
  }
};

} // namespace std
