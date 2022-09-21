#pragma once

namespace mathematical
{
    /**
     * A Generic vector in 3D space.
     */
    template<typename T = float>
    struct Vector3
    {
    public:

        /** Vector's X property. */
        T X;

        /** Vector's Y property. */
        T Y;

        /** Vector's Z property. */
        T Z;

    public:

        /**
         * Creates a Vector3 instantiated as (0, 0, 0).
         */
        static const Vector3<T> Zero;

        /**
         * Creates a Vector3 instantiated as (1, 1, 1).
         */
        static const Vector3<T> One;

        /**
         * Creates a Vector3 instantiated as (0, 1, 0).
         * Note: 3d modeling software commonly treats the Y axis as the up/down axis.
         */
        static const Vector3<T> Up;

        /**
         * Creates a Vector3 instantiated as (0, -1, 0).
         * Note: 3d modeling software commonly treats the Y axis as the up/down axis.
         */
        static const Vector3<T> Down;

        /**
         * Creates a Vector3 instantiated as (0, 0, 1).
         * Note: 3d modeling software commonly treats the Z axis as the forward/backward axis.
         */
        static const Vector3<T> Forward;

        /**
         * Creates a Vector3 instantiated as (0, 0, -1).
         * Note: 3d modeling software commonly treats the Z axis as the forward/backward axis.
         */
        static const Vector3<T> Backward;

        /**
         * Creates a Vector3 instantiated as (1, 0, 0).
         */
        static const Vector3<T> Right;

        /**
         * Creates a Vector3 instantiated as (-1, 0, 0).
         */
        static const Vector3<T> Left;

        /**
         * Creates a Vector3 instantiated as (1, 0, 0).
         */
        static const Vector3<T> XAxis;

        /**
         * Creates a Vector3 instantiated as (0, 1, 0).
         */
        static const Vector3<T> YAxis;

        /**
         * Creates a Vector3 instantiated as (0, 0, 1).
         */
        static const Vector3<T> ZAxis;

        /**
         * Creates a Vector3 that represents the smallest possible value of the specified type for each component.
         */
        static const Vector3<T> PositiveInfinity;

        /**
         * Creates a Vector3 that represents the largest possible value of the specified type for each component.
         */
        static const Vector3<T> NegativeInfinity;

    public:

        Vector3<T>();

        explicit Vector3<T>(T vec);

        Vector3<T>(T x, T y, T z);


        Vector3<T> operator+(const Vector3<T>& vec) const;

        Vector3<T> operator-(const Vector3<T>& vec) const;

        Vector3<T> operator*(const Vector3<T>& vec) const;

        Vector3<T> operator/(const Vector3<T>& vec) const;

        Vector3<T> operator+(T scalar) const;

        Vector3<T> operator-(T scalar) const;

        Vector3<T> operator-() const;

        Vector3<T> operator*(T scale) const;

        Vector3<T> operator/(T scale) const;

        Vector3<T> operator=(const Vector3<T>& vec);

        Vector3<T> operator+=(const Vector3<T>& vec);

        Vector3<T> operator-=(const Vector3<T>& vec);

        Vector3<T> operator*=(const Vector3<T>& vec);

        Vector3<T> operator/=(const Vector3<T>& vec);

        Vector3<T> operator*=(T scale);

        Vector3<T> operator/=(T scale);

        Vector3<T> operator^(const Vector3<T>& vec);

        bool operator==(const Vector3<T>& vec) const;

        bool operator!=(const Vector3<T>& vec) const;

        /**
         * Gets specific component of the vector.
         *
         * @param Index the index of vector component
         * @return reference to component.
         */
        float& operator[](int Index);

        /**
         * Gets specific component of the vector.
         *
         * @param Index the index of vector component
         * @return Copy of the component.
         */
        float operator[](int Index)const;

    };


    template<typename T>
    Vector3<T> Vector3<T>::operator+(const Vector3<T> &vec) const {
        return Vector3<T>(X + vec.X, Y + vec.Y, Z + vec.Z);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator-(const Vector3<T> &vec) const {
        return Vector3<T>(X - vec.X, Y - vec.Y, Z - vec.Z);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator*(const Vector3<T> &vec) const {
        return Vector3<T>(X * vec.X, Y * vec.Y, Z * vec.Z);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator/(const Vector3<T> &vec) const {
        return Vector3<T>(X / vec.X, Y / vec.Y, Z / vec.Z);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator+(T scalar) const {
        return Vector3<T>(X + scalar, Y + scalar, Z + scalar );
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator-(T scalar) const {
        return Vector3<T>(X - scalar, Y - scalar, Z - scalar );
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator-() const {
        return Vector3<T>(-X, -Y, -Z);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator*(T scale) const {
        return Vector3<T>(X * scale, Y * scale, Z * scale);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator/(T scale) const {
        return Vector3<T>(X / scale, Y / scale, Z / scale);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator=(const Vector3<T> &vec) {
        return Vector3<T>(vec.X, vec.Y, vec.Z);
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator^(const Vector3<T> &vec) {
        return Vector3<T>(Y * vec.Z - Z * vec.Y, Z * vec.X - X * vec.Z, X * vec.Y - Y * vec.X);
    }

    template<typename T>
    bool Vector3<T>::operator==(const Vector3<T> &vec) const {
        return false;
    }

    template<typename T>
    bool Vector3<T>::operator!=(const Vector3<T> &vec) const {
        return false;
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator+=(const Vector3<T> &vec) {
        return Vector3<T>();
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator-=(const Vector3<T> &vec) {
        return Vector3<T>();
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator*=(const Vector3<T> &vec) {
        return Vector3<T>();
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator/=(const Vector3<T> &vec) {
        return Vector3<T>();
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator*=(T scale) {
        return Vector3<T>();
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator/=(T scale) {
        return Vector3<T>();
    }

    template<typename T>
    float &Vector3<T>::operator[](int Index) {
        return Vector3<T>();
    }

    template<typename T>
    float Vector3<T>::operator[](int Index) const {
        return 0;
    }

    template<typename T>
    Vector3<T>::Vector3() {
        X = 0;
        Y = 0;
        Z = 0;

    }

    template<typename T>
    Vector3<T>::Vector3(T vec) {
        X = vec;
        Y = vec;
        Z = vec;

    }

    template<typename T>
    Vector3<T>::Vector3(T x, T y, T z) {
        X = x;
        Y = y;
        Z = z;

    }


}
