class Vector3 {
public:
    float x;
    float y;
    float z;

public:
    Vector3(float x = 0, float y = 0, float z = 0);
    ~Vector3();

    float Magnitude();
    void Normalize();
    Vector3 Normalized();

    void Add(Vector3& vector);
    void Subtract(Vector3& vector);
    void Multiply(Vector3& vector);
    void Divide(Vector3& vector);
    void Scale(float scalar);

    float Dot(Vector3& vector);
    Vector3 Cross(Vector3& vector);

    float Distance(Vector3& vector);
    float Angle(Vector3& vector);
    
    Vector3 Clone();

    static void Normalize(Vector3& vector);

    static Vector3 zero();
    static Vector3 one();
    static Vector3 up();
    static Vector3 down();
    static Vector3 left();
    static Vector3 right();
    static Vector3 forward();
    static Vector3 back();  
}; 