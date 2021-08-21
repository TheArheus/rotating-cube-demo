#if !defined(HMATH_H_)
#define HMATH_H_

union v2
{
    struct
    {
        r32 X, Y;        
    };
    r32 E[2];
};

union v3
{
    struct
    {
        r32 X, Y, Z;        
    };
    r32 E[3];
};

union v4
{
    struct
    {
        r32 X, Y, Z, W;
    };
    r32 E[4];
};

inline v2
V2(r32 X, r32 Y)
{
    v2 Result = {};

    Result.X = X;
    Result.Y = Y;

    return Result;
}

inline v3
V3(r32 X, r32 Y, r32 Z)
{
    v3 Result = {};

    Result.X = X;
    Result.Y = Y;
    Result.Z = Z;

    return Result;
}

inline v4
V4(r32 X, r32 Y, r32 Z, r32 W)
{
    v4 Result = {};

    Result.X = X;
    Result.Y = Y;
    Result.Z = Z;
    Result.W = W;

    return Result;
}


inline v2 
operator+(v2 A, v2 B)
{
    v2 Result = {};

    Result.X = A.X + B.X;
    Result.Y = A.Y + B.Y;

    return Result;
}

inline v2
operator+(v2 A, r32 B)
{
    v2 Result = {};

    Result.X = A.X + B;
    Result.Y = A.Y + B;

    return Result;
}

inline v2
operator+(r32 A, v2 B)
{
    B = B + A;

    return B;
}

inline v2&
operator+=(v2& A, v2 B)
{
    A = A + B;

    return A;
}

inline v2&
operator+=(v2& A, r32 B)
{
    A = A + B;

    return A;
}

inline v2 
operator-(v2 A, v2 B)
{
    v2 Result = {};

    Result.X = A.X - B.X;
    Result.Y = A.Y - B.Y;

    return Result;
}

inline v2
operator-(v2 A, r32 B)
{
    v2 Result = {};

    Result.X = A.X - B;
    Result.Y = A.Y - B;
}

inline v2
operator-(r32 A, v2 B)
{
    B = B - A;

    return B;
}

inline v2&
operator-=(v2& A, v2 B)
{
    A = A - B;

    return A;
}

inline v2&
operator-=(v2& A, r32 B)
{
    A = A - B;

    return A;
}

inline v2
operator*(v2 A, v2 B)
{
    v2 Result = {};

    Result.X = A.X*B.X;
    Result.Y = A.Y*B.Y;

    return Result;
}

inline v2
operator*(v2 A, r32 B)
{
    v2 Result = {};

    Result.X = A.X*B;
    Result.Y = A.Y*B;

    return Result;
}

inline v2
operator*(r32 A, v2 B)
{
    B = B*A;

    return B;
}

inline v2&
operator*=(v2& A, v2 B)
{
    A = A*B;

    return A;
}

inline v2&
operator*=(v2& A, r32 B)
{
    A = A * B;

    return A;
}

inline v3
rotate_x(v3 P, r32 A)
{
    v3 Result = {};

    Result.X = P.X;
    Result.Y = P.Y*cosf(A) - P.Z*sinf(A);
    Result.Z = P.Y*sinf(A) + P.Z*cosf(A);

    return Result;
}

inline v3
rotate_y(v3 P, r32 A)
{
    v3 Result = {};

    Result.X = P.X*cosf(A) - P.Z*sinf(A);
    Result.Y = P.Y;
    Result.Z = P.X*sinf(A) + P.Z*cosf(A);

    return Result;
}

inline v3 
rotate_z(v3 P, r32 A)
{
    v3 Result = {};

    Result.X = P.X*cosf(A) - P.Y*sinf(A);
    Result.Y = P.X*sinf(A) + P.Y*cosf(A);
    Result.Z = P.Z;

    return Result;
}

#endif
