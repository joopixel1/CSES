
## The `<complex>` Library in C++

The `<complex>` library in C++ provides a collection of functions and classes for complex number arithmetic. Complex numbers are essential in various fields, including engineering, physics, and computer science. This library allows for easy manipulation and computation with complex numbers.

### Initialization

To use the `<complex>` library, include the header at the beginning of your program:

```cpp
#include <complex>
```

### `std::complex` Class Template

The `std::complex` class template represents complex numbers. It is defined as follows:

```cpp
template <class T>
class complex {
public:
    // Constructors
    constexpr complex(const T& real = T(), const T& imag = T());
    constexpr complex(const complex& other);

    // Member functions
    T real() const;
    T imag() const;
    void real(T);
    void imag(T);

    // Operator overloading
    complex<T>& operator=(const T&);
    complex<T>& operator+=(const T&);
    complex<T>& operator-=(const T&);
    complex<T>& operator*=(const T&);
    complex<T>& operator/=(const T&);
    complex<T>& operator=(const complex&);
    complex<T>& operator+=(const complex&);
    complex<T>& operator-=(const complex&);
    complex<T>& operator*=(const complex&);
    complex<T>& operator/=(const complex&);
};
```

### Initialization and Basic Operations

#### Constructors

- Default constructor:
  ```cpp
  std::complex<double> z1;
  ```
  Initializes `z1` to `(0, 0)`.

- Constructor with real and imaginary parts:
  ```cpp
  std::complex<double> z2(3.0, 4.0);
  ```
  Initializes `z2` to `(3.0, 4.0)`.

- Constructor with only real part:
  ```cpp
  std::complex<double> z3(5.0);
  ```
  Initializes `z3` to `(5.0, 0.0)`.

#### Accessors and Mutators

- Get the real part:
  ```cpp
  double real_part = z2.real();
  ```

- Get the imaginary part:
  ```cpp
  double imag_part = z2.imag();
  ```

- Set the real part:
  ```cpp
  z2.real(7.0);
  ```

- Set the imaginary part:
  ```cpp
  z2.imag(8.0);
  ```

### Operator Overloading

The `std::complex` class supports various arithmetic operations:

- Addition:
  ```cpp
  std::complex<double> z4 = z2 + z3;
  ```

- Subtraction:
  ```cpp
  std::complex<double> z5 = z2 - z3;
  ```

- Multiplication:
  ```cpp
  std::complex<double> z6 = z2 * z3;
  ```

- Division:
  ```cpp
  std::complex<double> z7 = z2 / z3;
  ```

### Functions

#### Complex Number Functions

The `<complex>` library provides several functions for operations on complex numbers:

- `std::abs`: Returns the magnitude (absolute value) of the complex number.
  ```cpp
  double magnitude = std::abs(z2);
  ```

- `std::arg`: Returns the phase angle (argument) of the complex number.
  ```cpp
  double angle = std::arg(z2);
  ```

- `std::norm`: Returns the norm (squared magnitude) of the complex number.
  ```cpp
  double norm = std::norm(z2);
  ```

- `std::conj`: Returns the complex conjugate of the complex number.
  ```cpp
  std::complex<double> conjugate = std::conj(z2);
  ```

- `std::polar`: Constructs a complex number from polar coordinates.
  ```cpp
  std::complex<double> z8 = std::polar(5.0, 0.927295);
  ```

#### Trigonometric and Hyperbolic Functions

- `std::cos`: Returns the cosine of the complex number.
  ```cpp
  std::complex<double> cos_z = std::cos(z2);
  ```

- `std::sin`: Returns the sine of the complex number.
  ```cpp
  std::complex<double> sin_z = std::sin(z2);
  ```

- `std::tan`: Returns the tangent of the complex number.
  ```cpp
  std::complex<double> tan_z = std::tan(z2);
  ```

- `std::cosh`: Returns the hyperbolic cosine of the complex number.
  ```cpp
  std::complex<double> cosh_z = std::cosh(z2);
  ```

- `std::sinh`: Returns the hyperbolic sine of the complex number.
  ```cpp
  std::complex<double> sinh_z = std::sinh(z2);
  ```

- `std::tanh`: Returns the hyperbolic tangent of the complex number.
  ```cpp
  std::complex<double> tanh_z = std::tanh(z2);
  ```

#### Exponential and Logarithmic Functions

- `std::exp`: Returns the exponential of the complex number.
  ```cpp
  std::complex<double> exp_z = std::exp(z2);
  ```

- `std::log`: Returns the natural logarithm of the complex number.
  ```cpp
  std::complex<double> log_z = std::log(z2);
  ```

- `std::log10`: Returns the base-10 logarithm of the complex number.
  ```cpp
  std::complex<double> log10_z = std::log10(z2);
  ```

- `std::pow`: Raises the complex number to a given power.
  ```cpp
  std::complex<double> pow_z = std::pow(z2, 2.0);
  ```

- `std::sqrt`: Returns the square root of the complex number.
  ```cpp
  std::complex<double> sqrt_z = std::sqrt(z2);
  ```

### Example Usage

Here is an example program demonstrating the use of the `<complex>` library:

```cpp
#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main() {
    // Initialization
    complex<double> z1(3.0, 4.0);
    complex<double> z2(1.0, 2.0);

    // Basic Operations
    complex<double> sum = z1 + z2;
    complex<double> diff = z1 - z2;
    complex<double> prod = z1 * z2;
    complex<double> quot = z1 / z2;

    // Output results
    cout << "z1: " << z1 << endl;
    cout << "z2: " << z2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;

    // Magnitude and Phase
    cout << "Magnitude of z1: " << abs(z1) << endl;
    cout << "Phase of z1: " << arg(z1) << endl;

    // Conjugate
    cout << "Conjugate of z1: " << conj(z1) << endl;

    return 0;
}
```

This program initializes complex numbers, performs basic arithmetic operations, and demonstrates some of the functions provided by the `<complex>` library.

### Conclusion

The `<complex>` library in C++ is a powerful tool for working with complex numbers, providing a wide range of functionalities for initialization, arithmetic operations, and complex mathematical functions. It is essential for applications that involve complex number computations.